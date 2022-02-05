/*
 * @Date: 2022.02.05 20:54
 * @Description: Omit
 * @LastEditors: Rustle Karl
 * @LastEditTime: 2022.02.05 20:54
 */
#include <string.h>
#include <stdarg.h>
#include <getopt.h>
#include <stdlib.h>

#include "vhdwriter.h"

int init_vhd_writer(vhd_writer *writer, const char *vhd_file) {
    FILE *fp = fopen(vhd_file, "rb+");
    if (fp == NULL) {
        writer->error = OPEN_FILE_ERROR;
        return 0;
    }

    writer->fp = fp;
    writer->error = NO_ERROR;

    return 1;
}

void release_vhd_writer(vhd_writer *writer) {
    fclose(writer->fp);
}

int is_valid_vhd(vhd_writer *writer) {
    char cookie[9] = {0};
    /* the beginning of last sector means VHD cookie */
    fseek(writer->fp, -512, SEEK_END);
    fread(cookie, 1, 8, writer->fp);
    return strcmp(cookie, "conectix") == 0 && (writer->valid = 1);
}

int is_fixed_vhd(vhd_writer *writer) {
    int type;
    /* the last sector with offset 0x3C means VHD type */
    fseek(writer->fp, -512 + 0x3C, SEEK_END);
    fread(&type, sizeof(int), 1, writer->fp);
    return type == 0x02000000 && (writer->fixed = 1);
}

uint64_t swap_big_little_endian_uint64(uint64_t val) {
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL) | ((val >> 8) & 0x00FF00FF00FF00FFULL);
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL) | ((val >> 16) & 0x0000FFFF0000FFFFULL);
    return (val << 32) | (val >> 32);
}

uint64_t get_vhd_original_size(vhd_writer *writer) {
    uint64_t size;
    /* the last sector with offset 0x28 means original size */
    fseek(writer->fp, -512 + 0x28, SEEK_END);
    fread(&size, sizeof(int64_t), 1, writer->fp);
    /* reverse big-endian into little-endian */
    return writer->size = swap_big_little_endian_uint64(size);
}

geometry get_vhd_geometry(vhd_writer *writer) {
    geometry geo;
    fseek(writer->fp, -512 + 0x38, SEEK_END);
    fread(&geo, sizeof(geo), 1, writer->fp);
    return geo;
}

unsigned int write_one_vhd_sector(vhd_writer *writer, int sector_offset, vhd_sector *sector) {
    fseek(writer->fp, sector_offset * 512, SEEK_SET);
    return fwrite(sector->buffer, 1, sector->valid_bytes, writer->fp);
}

unsigned int write_to_vhd_from_binary_file(vhd_writer *writer, int sector_offset, char *bin_file) {
    unsigned int valid_bytes, bytes_written;
    unsigned int total_bytes_written = 0, total_sectors = writer->size / 512;

    if (sector_offset < 0 || sector_offset >= total_sectors) {
        writer->error = OFFSET_OUT_OF_RANGE;
        return 0;
    }

    FILE *fp = fopen(bin_file, "rb");
    vhd_sector sector;

    if (fp == NULL) {
        writer->error = OPEN_FILE_ERROR;
        return 0;
    }

    do {
        valid_bytes = fread(sector.buffer, 1, 512, fp);
        sector.valid_bytes = valid_bytes;
        bytes_written = write_one_vhd_sector(writer, sector_offset++, &sector);
        total_bytes_written += bytes_written;
    } while (sector_offset < total_sectors && valid_bytes == 512 && bytes_written);

    fclose(fp);

    return total_bytes_written;
}

void printf_message(char *format, ...) {
    va_list vl;
    va_start(vl, format);
    vfprintf(stdout, format, vl);
    fprintf(stdout, "\n");
    va_end(vl);
}

#define WRITER_MESSAGE(s, ...) printf_message(s, ##__VA_ARGS__)

int main(int argc, char **argv) {
    char *help = "Fixed VHD Writer\n\n"
                 "[-h] usage help\n"
                 "[-s] show information about specify .vhd file\n"
                 "[-v] specify .vhd file to write  [required]\n"
                 "[-b] specify .bin file to read\n"
                 "[-o] specify sector offset to write\n";

    if (argc <= 1) {
        WRITER_MESSAGE(help);
        return -1;
    }


    vhd_writer writer;
    char vhd_file[512] = {0}, bin_file[512] = {0};
    int sector_offset = 0;
    int show_geometry = 0;

    int option;
    char *options = "hv:b:o:s";

    while ((option = getopt(argc, argv, options)) != -1) {
        switch (option) {
            case 'h':
                WRITER_MESSAGE(help);
                return 0;
            case 's':
                show_geometry = 1;
                break;
            case 'v':
                strcpy(vhd_file, optarg);
                break;
            case 'b':
                strcpy(bin_file, optarg);
                break;
            case 'o':
                sector_offset = atoi(optarg);
                break;
            default:
                printf("default");
                break;
        }
    }

    if (strlen(vhd_file) == 0) {
        WRITER_MESSAGE("VHD image file is not specified");
        return -1;
    }

    init_vhd_writer(&writer, vhd_file);
    if (writer.error == OPEN_FILE_ERROR) {
        WRITER_MESSAGE("Open %s file error", vhd_file);
        return -1;
    }

    if (!is_valid_vhd(&writer)) {
        WRITER_MESSAGE("Invalid or broken VHD image file");
        release_vhd_writer(&writer);
        return -1;
    }


    if (!is_fixed_vhd(&writer)) {
        WRITER_MESSAGE("The VHD image is not fixed which is still not support");
        release_vhd_writer(&writer);
        return -1;
    }

    uint64_t original_size = get_vhd_original_size(&writer);

    if (show_geometry) {
        geometry geo = get_vhd_geometry(&writer);

        fprintf(stdout,
                "Original size: %lluMB\n"
                "Cylinder: %d\n"
                "Heads: %d\n"
                "Sectors Per Cylinder: %d\n",
                original_size >> 20, (geo.cylinder[0] << 4) + geo.cylinder[1],
                geo.heads, geo.sectors_per_cylinder
        );

        return 0;
    }

    if (strlen(bin_file) == 0) {
        WRITER_MESSAGE("binary file is not specified");
        return -1;
    }

    unsigned int total_bytes_written = write_to_vhd_from_binary_file(&writer, sector_offset, bin_file);
    writer_error error = writer.error;

    if (error == OFFSET_OUT_OF_RANGE) {
        WRITER_MESSAGE("sector_offset is out of range (0 - %d)", writer.size / 512 - 1);
        release_vhd_writer(&writer);
        return -1;
    } else if (error == OPEN_FILE_ERROR) {
        WRITER_MESSAGE("Open %s file error", bin_file);
        release_vhd_writer(&writer);
        return -1;
    }

    fprintf(stdout,
            "Data: %s\n"
            "VHD: %s (sector offset: %d)\n"
            "Total bytes written: %u\n"
            "Total sectors written: %u\n",
            bin_file, vhd_file, sector_offset, total_bytes_written,
            total_bytes_written / 512 + (total_bytes_written % 512 != 0));

    release_vhd_writer(&writer);

    return 0;
}


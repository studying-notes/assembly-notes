/*
 * @Date: 2022.02.05 20:54
 * @Description: Omit
 * @LastEditors: Rustle Karl
 * @LastEditTime: 2022.02.05 20:54
 */
#ifndef VHDWRITER_VHDWRITER_H
#define VHDWRITER_VHDWRITER_H

#include <stdint.h>
#include <stdio.h>

typedef enum {
    NO_ERROR,
    OFFSET_OUT_OF_RANGE,
    OPEN_FILE_ERROR
} writer_error;

typedef struct {
    FILE *fp;
    int valid;
    int fixed;
    uint64_t size;
    writer_error error;
} vhd_writer;

typedef struct {
    unsigned int valid_bytes;
    uint8_t *buffer[512];
} vhd_sector;

typedef struct {
    char cylinder[2];
    char heads;
    char sectors_per_cylinder;
} geometry;

#endif //VHDWRITER_VHDWRITER_H

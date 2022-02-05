.PHONY: ;
.SILENT: ;               # no need for @
.ONESHELL: ;             # recipes execute in same shell
.NOTPARALLEL: ;          # wait for target to finish
.EXPORT_ALL_VARIABLES: ; # send all vars to shell

.IGNORE: dep clean test;            # ignore all errors, keep going

ifeq ($(OS), Windows_NT)
SHELL := pwsh.exe
.SHELLFLAGS := -NoProfile -Command
endif

PROJECT = vhdwriter

TARGET = $(PROJECT)

INSTALL_PATH = /usr/local/bin/

ifeq ($(OS), Windows_NT)
TARGET = $(PROJECT).exe
INSTALL_PATH = c:/developer/bin/
endif

all: reinstall

build:
	gcc -o $(TARGET) $(PROJECT).c

uninstall:
	-(rm $(INSTALL_PATH)$(TARGET))

install:
	copy $(TARGET) $(INSTALL_PATH)
	rm $(TARGET)

reinstall: uninstall build install

tag:
	git tag v$(VERSION)
	git push origin v$(VERSION)

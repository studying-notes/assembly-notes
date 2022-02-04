.PHONY: ;

NAME = vhdwriter

TARGET = $(NAME)
COPY_TO = /usr/local/bin/

ifeq ($(OS), Windows_NT)
SHELL := pwsh.exe
.SHELLFLAGS := -NoProfile -Command

TARGET = $(NAME).exe
COPY_TO = C:/Developer/bin/
endif

all: install

build:
	gcc -o $(TARGET) $(NAME).c

install: build
	copy $(TARGET) $(COPY_TO)
	rm $(TARGET)

uninstall:
	rm $(COPY_TO)$(TARGET)

BUILD_PATH = .\build
CC = "C:\MinGW\bin\gcc.exe"

INC_DIRS = src\external\SDL2\include
INC_FLAGS = -I$(INC_DIRS)

LIB_DIRS = src\external\SDL2\lib
LIB_FLAGS = -L$(LIB_DIRS)

CFLAGS = -lmingw32 -lSDL2main -lSDL2

LDFLAGS = -Wall -g -O2 $(LIB_FLAGS) $(INC_FLAGS) $(CFLAGS)

build:
	$(CC) -o main src\main.c $(LDFLAGS)

run:
	main

clean:
	del /f $(BUILD_PATH)\main.exe

.PHONY: clean build
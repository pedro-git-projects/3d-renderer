CC = gcc 
LANG_STD = -std=c99
COMPILER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = -I"./libs/"
SRC_FILES = ./src/*.c
LINKER_FLAGS = "-lSDL2"
OBJ_NAME = renderer 

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)
	mv $(OBJ_NAME) ./bin

run:
	./bin/$(OBJ_NAME)

clean:
	rm ./bin/$(OBJ_NAME)

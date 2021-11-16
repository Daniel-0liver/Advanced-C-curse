APPS = ./apps
BIN = ./bin
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
FLAGS = -Wall -Wextra -Werror
CC = gcc


all: libed myapps
	
libed:
	$(CC) $(FLAGS) -c $(SRC)./float_vector.c -I $(INCLUDE) -o $(OBJ).\float_vector.o
	$(CC) $(FLAGS) -c $(SRC)./mytime.c -I $(INCLUDE) -o $(OBJ).\mytime.o

myapps:
	$(CC) $(FLAGS) $(APPS)./app.c $(OBJ)/*.o -I $(INCLUDE)/ -o $(BIN)./app

run:
	bin/./app

clean:
	rm $(OBJ)/* $(BIN)/*
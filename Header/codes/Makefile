APPS = ./apps
BIN = ./bin
LIB = ./lib
LIBS = -lm -led -L $(LIB)
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
FLAGS = -o3 -Wall -Wextra -Werror
CC = gcc


all: libed myapps
	
libed: $(OBJ)/float_vector.o $(OBJ)/mytime.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

myapps: clean_apps $(BIN)/test_float_vector


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	$(CC) $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
	$(BIN)/test_float_vector

clean:
	@rm -rf $(OBJ)/* $(BIN)/* $(LIB)/*

clean_apps:
	@rm -rf $(BIN)/*
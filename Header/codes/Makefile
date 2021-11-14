APPS = .\apps
BIN = .\bin
SRC = .\src
INCLUDE = .\include
OBJ = .\obj


all: libed myapps
	
libed:
	gcc -c $(SRC).\float_vector.c -I $(INCLUDE) -o $(OBJ).\float_vector.o
	gcc -c $(SRC).\mytime.c -I $(INCLUDE) -o $(OBJ).\mytime.o

myapps:
	gcc $(APPS).\app.c $(OBJ)/* -I $(INCLUDE)\ -o $(BIN).\app
	# gcc $(APPS).\app.c .\$(OBJ).\* -I $(INCLUDE)\ -o $(BIN).\app

run:
	bin\.\app.exe

clean:
	rm $(OBJ)/*
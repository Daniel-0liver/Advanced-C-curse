all:
	bin\.\app.exe

obf:
	gcc -c src\.\float_vector.c -I include -o obj\float_vector.o

obm:
	gcc -c .\src\mytime.c -I include -o obj\mytime.o

exe:
	gcc .\apps\app.c .\obj\*.o -I .\include\ -o .\bin\.\app

clean:

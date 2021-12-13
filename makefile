cesar.exe : main.o fonction.o
	gcc main.o fonction.o -o cesar.exe
main.o : main.c cesar.h
	gcc -Wall -c main.c
fonction.o : fonction.c cesar.h
	gcc -Wall -c fonction.c
clean :
	rm *.o cesar.exe

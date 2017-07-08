#
# Para compilar:   make
# Para ejecutar:   make run
# Para limpiar:    make clean

CC = gcc
CFLAGS= -g -Wall
OBJ = main.o set.o
EXE = exe

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE)

run:
	./$(EXE)
clean:
	rm -r $(EXE) *.o

main.o: main.c
set.o: set.c set.h

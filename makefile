CC=gcc
FLAGS=-g -W -Wall -ansi -pedantic
EXEC=prog

all: $(EXEC)

prog: prog.o file.o pile.o test.o truc.o
	$(CC) -o $@ $^
	@echo "--------------------------------"
	@echo "------Compilation réussie-------"
	@echo "--------------------------------"
	@echo "Lancer le programme avec  ./prog"

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
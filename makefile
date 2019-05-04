CC=gcc
FLAGS=-g -W -Wall -ansi -pedantic
EXEC=main

all: $(EXEC)

main	: main.o arbre.o pile.o fichier.o
	$(CC) -o $@ $^
	@echo "--------------------------------"
	@echo "------Compilation réussie-------"
	@echo "--------------------------------"
	@echo "Lancer le programme avec  ./main"

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

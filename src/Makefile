NAME := $(shell basename $(PWD))
export MODULE := M1
all: $(NAME)-64 $(NAME)-32

include ../Makefile

pstree.o: pstree.c 
	gcc -std=gnu99 -Wall pstree.c -c  
pstree: pstree.o 
	gcc -o a.out pstree.o && ./a.out 

.PHONY: clean 
clean:
	rm -f *.out *.o *.s pstree *.log

deep-clean:
	rm -f *.txt

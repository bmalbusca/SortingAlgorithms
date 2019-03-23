# AED 2018-2019, sem.2
# Makefile for LabAval Problem 2
# Last edit: abl 2019.03.19
#-----------------------------------------------------------------------
#   Compiler, Compiler Flags
CC = gcc
CFLAGS = -g -Wall -ansi -pedantic

#  Sources
SOURCES = p2.c

FILES = $(shell ls ./test/*.txt)
p2: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

# tests
t:  for F in ${FILES}; do ./p2 $${F}; done;

t1:
	./p2 ./test/m3x3.txt

t2:
	./p2 ./test/m4x4.txt

t3:
	./p2 ./test/m5x6.txt

    
# tests w/ valgrind mem check
v:  v1 v2 v3

v1:
	valgrind --leak-check=full ./p2 ./test/m3x3.txt

v2:
	valgrind --leak-check=full ./p2 ./test/m4x4.txt

v3:
	valgrind --leak-check=full ./p2 ./test/m5x6.txt

clean::
	rm -f *.o core a.out  *~

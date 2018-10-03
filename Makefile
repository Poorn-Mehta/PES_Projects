CC=gcc
CFLAGS=-I.

Test: tmp.o
     $(CC) -o Test tmp.o
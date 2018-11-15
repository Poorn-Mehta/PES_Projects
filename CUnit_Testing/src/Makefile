IDIR =../inc
CC=gcc
CFLAGS=-I$(IDIR) -lcunit

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = Custom_Circular_Buffer.h Custom_Main.h Custom_Sys_Identifier.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Custom_Circular_Buffer.o Main.o test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

project: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
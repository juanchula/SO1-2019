#Macros
CC=gcc
CFLAGS=-Wall -pedantic
FLOUT=rdproc
FL=main.c
FLS=filetools.c tp1a.c tp1b.c tp1c.c tp1d.c
RM=rm
OBJ=main.o

#Reglas xplicitas
all: $(FL)
		$(CC) $(CFLAGS) -o $(FLOUT) $(FLS) $(FL)

clean:
		$(RM) $(OBJ)

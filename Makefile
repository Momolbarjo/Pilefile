CC = gcc
CFLAGS =  -I$(IDIR) 

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c
all: pile run

pile:	$(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./pile

clean:
	rm pile

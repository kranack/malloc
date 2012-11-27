CC      = gcc
CFLAGS  = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g
 
all: my_free my_malloc
 
PRG1	= my_malloc.o my_free.o
PRG2	= my_malloc.o test_malloc.o
PRG3	= my_malloc.o my_free.o

my_malloc: $(PRG1)
	$(CC) $(CFLAGS) -o $@ $(PRG1)
test_malloc: $(PRG2)
	$(CC) $(CFLAGS) -o $@ $(PRG2)
my_free: $(PRG3)
	$(CC) $(CFLAGS) -o $@ $(PRG3)
 
clean:
	$(RM) $(PRG1) $(PRG2)
cleanall: clean
	$(RM) $(EXE) $(PRG1) $(PRG2)
 
.PHONY: clean cleanall

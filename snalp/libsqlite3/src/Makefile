

CFLAGS= -I.. -02 -Wall

SRC:=$(wildcard *.c)
OBJS:= $(SRC:.c=.o)

bti.o: $(OBJS)
	ld -r -o $@ -o $@ $(OBJS)

.c.o:
	@echo Compiling $@
	@$(CC) -c -o $@ $<

clean:
	rm *.o

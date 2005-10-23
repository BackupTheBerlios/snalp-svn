

CFLAGS= -I.. -02 -Wall

SRC:=$(wildcard *.c)
OBJS:= $(SRC:.c=.o)

#$(OBJS) : Makefile

bti.o: $(OBJS)
	ld -r -o $@ $(OBJS)

.c.o: Makefile
	@echo Compiling $< to $@
	@$(CC) -c -o $@ $<

clean:
	rm -f *.o

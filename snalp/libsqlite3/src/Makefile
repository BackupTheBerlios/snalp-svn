

CFLAGS= -I.. -02 -Wall

SRC:=$(wildcard *.c)
OBJS:= $(SRC:.c=.o)

#$(OBJS) : Makefile

bti.o: $(OBJS)
	@echo linking $@
	@ld -r -o $@ $(OBJS)

.c.o: Makefile
	@echo Compiling $< to $@
	@$(CC) -c -o $@ $<

clean:
	@echo Cleaning up ...
	@-rm *.o

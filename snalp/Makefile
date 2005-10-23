###
### Makefile v0.3
###
### still dirty, but it works __better__
###

INCFLAGS=`pkg-config libglademm-2.4 --cflags`

CFLAGS=${INCFLAGS} -Wall -O2 

LDFLAGS=`pkg-config libglademm-2.4 --libs` 


HDRS:=$(wildcard *.h *.hpp)
	
SRCS:=$(wildcard *.cpp)

OBJS:=$(SRCS:.cpp=.o) libsqlite3/libsnalpsqlite.a

all: snalp

$(OBJS): $(HDRS)

.cpp.o: Makefile
	@echo Compiling $< to $@
	@g++ ${CFLAGS} -c -o $@ $<
		   
snalp: ${OBJS} 
	g++ ${CFLAGS} ${LDFLAGS} -o $@ ${OBJS}

libsqlite3/libsnalpsqlite.a: libsqlite3
libsqlite3: 
# /libsnalpsqlite.a:
	@(cd libsqlite3;$(MAKE);)

.PHONY: libsqlite3

install:
	@echo atm haben wir das install target ned ins makefile eingebaut

thisclean:
	rm -f snalp *.o
	
clean: thisclean
	(cd libsqlite3;$(MAKE) clean;)

.PHONY: thisclean clean

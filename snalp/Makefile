###
### Makefile v0.2
###
### still dirty, but it works __better__
###

INCFLAGS=`pkg-config libglademm-2.4 --cflags`




SQLITEFLAGS=#-L./libsqlite3 -lsnalpsqlite3

CFLAGS=${INCFLAGS} -Wall -O2 #-Weffc++ -fmessage-length=0 

LDFLAGS=`pkg-config libglademm-2.4 --libs` ${SQLITEFLAGS}



.cpp.o: Makefile
	@echo Compiling $< to $@
	@g++ ${CFLAGS} -c -o $@ $<

OBJS=snalp.o Database.o MainWindow.o SnippetTreeView.o libsqlite3/libsnalpsqlite.a

all: snalp
install:
	@echo atm haben wir das install target ned ins makefile eingebaut
snalp: ${OBJS} 
	g++ ${CFLAGS} ${LDFLAGS} -o $@ ${OBJS}

libsqlite3/libsnalpsqlite.a:
	@(cd libsqlite3;$(MAKE);)

thisclean:
	rm -f snalp *.o
	
clean: thisclean
	(cd libsqlite3;$(MAKE) clean;)

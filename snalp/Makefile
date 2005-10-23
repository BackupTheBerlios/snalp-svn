###
### Makefile v0.2
###
### still dirty, but it works __better__
###

INCFLAGS=`pkg-config libglademm-2.4 --cflags`

SQLITEFLAGS="-lsqlite3"

CFLAGS=${INCFLAGS} -Wall -O2

LDFLAGS=`pkg-config libglademm-2.4 --libs` ${SQLITEFLAGS}

.cpp.o:
	g++ ${CFLAGS} -c -o $@ $<

OBJS=snalp.o Database.o MainWindow.o SnippetTreeView.o 

all: snalp
install:
	@echo atm haben wir das install target ned ins makefile eingebaut
snalp: ${OBJS} 
	g++ ${CFLAGS} ${LDFLAGS} -o $@ ${OBJS}

clean:
	rm snalp *.o

###
### Makefile v0.1
###
### way too dirty, but it works
###

CFLAGS=`pkg-config libglademm-2.4 --cflags --libs`
all: snalp.x86
install:
	@echo atm haben wir das install target ned ins makefile eingebaut
snalp.x86: Database.cpp  MainWindow.cpp  snalp.cpp  SnippetTreeView.cpp 
	gcc ${CFLAGS}  -lsqlite3 -Wall -o snalp.x86 *.cpp

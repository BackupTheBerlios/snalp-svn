// snalp.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#pragma warning( disable :4250)
#pragma warning( disable :4541)

#include <iostream>
#include "Database.h"
#include "debughelpher.h"
#include <gtkmm.h>


int main(int argc, char** argv)
{
    Gtk::Main main_obj(argc,argv);
    Gtk::Window window_obj;
    main_obj.run(window_obj);
    //Database db;
	return 0;
}

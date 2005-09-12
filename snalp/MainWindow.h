#pragma once
#include <gtkmm.h>
#include <glademm.h> 
#include <map>
class MainWindow
{
public:
    MainWindow();
    ~MainWindow();
    static int Run( int argc , char ** argv );
private:
    Gtk::Window * window;
    Gtk::Main * main;  
    std::map<std::string , Gtk::Label * > DataLabels;
    Gtk::TextView * text_view;
};

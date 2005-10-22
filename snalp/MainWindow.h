#pragma warning( disable :4250)
#pragma warning( disable :4541)
#pragma once
#include <gtkmm.h>
#include <libglademm.h>
#include <map>
#include "SnippetTreeView.h"

class MainWindow
{
public:
    MainWindow();
    ~MainWindow();
    static int Run( int argc , char ** argv );
private:    
    Glib::RefPtr<Gnome::Glade::Xml> XmlRef;
    Gtk::Window * window;
    std::map<std::string , Gtk::Label * > DataLabels;
    Gtk::TextView * text_view;
    SnippetTreeView * snippet_tv;
};

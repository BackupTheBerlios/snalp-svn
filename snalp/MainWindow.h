#pragma warning( disable :4250)
#pragma warning( disable :4541)
#pragma once
#include <gtkmm.h>
#include <libglademm.h>
#include <map>
#include <boost/shared_ptr.hpp>
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
    boost::shared_ptr<SnippetTreeView> snippet_tv;
};

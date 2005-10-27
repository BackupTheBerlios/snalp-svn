#ifndef GUARD_MAINWINDOW_H_INCLUDED
#define GUARD_MAINWINDOW_H_INCLUDED 1

#include "FowardDeclarations.h"
#include <boost/shared_ptr.hpp>
#include <glibmm/refptr.h>
#include <map>

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
    void ConnectMenuSignals();
};

#endif

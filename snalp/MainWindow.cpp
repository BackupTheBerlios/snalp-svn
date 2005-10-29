
#include "MainWindow.h"

#include <iostream>
#include <gtkmm.h>
#include <libglademm.h>
#include "SnalpException.h"
#include "SnippetTreeView.h"
#include "debughelper.h"

//##################################################################################################################
MainWindow::MainWindow()
: window(0)
{
    try{
        XmlRef = Gnome::Glade::Xml::create("snalp_glade_gui/snalp.glade");
        XmlRef->get_widget<Gtk::Window>("MainWindow",window);
        snippet_tv = boost::shared_ptr<SnippetTreeView>(new SnippetTreeView(XmlRef));
        snippet_tv->AddLanguage("C++");
        snippet_tv->AddCategory("C++","File I/O");
        snippet_tv->AddSnippet("C++","File I/O","Reading files",1ULL);
        ConnectMenuSignals();
    }
    catch( Gnome::Glade::XmlError & e )
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException,e.what());
    }
}
//##################################################################################################################
MainWindow::~MainWindow()
{
}
//##################################################################################################################
int MainWindow::Run( int argc , char ** argv )
{
    Gtk::Main main_obj(argc,argv);
    MainWindow application;
    main_obj.run(*application.window);
    return EXIT_SUCCESS;
}
//##################################################################################################################
void MainWindow::ConnectMenuSignals()
{
    try
    {
        Gtk::MenuItem * item = 0;
        XmlRef->get_widget<Gtk::MenuItem>("menu_beenden1",item);
        item->signal_activate().connect(sigc::mem_fun(*(this->window),&Gtk::Window::hide));
    }
    catch( Gnome::Glade::XmlError & e)
    {
        THROW_SNALP_EXCEPTION(SnalpFatalException,e.what());
    }
}
//##################################################################################################################

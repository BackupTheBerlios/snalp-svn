#include <iostream>
#include "mainwindow.h"

MainWindow::MainWindow()
: window(0)
{
    try{
        XmlRef = Gnome::Glade::Xml::create("snalp/snalp.glade");
        XmlRef->get_widget<Gtk::Window>("MainWindow",window);
        snippet_tv = new SnippetTreeView(XmlRef);
    }
    catch( Gnome::Glade::XmlError & e )
    {
        std::cout << e.what() << std::endl;        
    }
}

MainWindow::~MainWindow()
{
}

int MainWindow::Run( int argc , char ** argv )
{
    Gtk::Main main_obj(argc,argv);
    MainWindow application;
    main_obj.run(*application.window);
    return EXIT_SUCCESS;
}
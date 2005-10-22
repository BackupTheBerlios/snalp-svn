#include <iostream>
#include "MainWindow.h"

MainWindow::MainWindow()
: window(0)
{
    try{
        XmlRef = Gnome::Glade::Xml::create("snalp/snalp.glade");
        XmlRef->get_widget<Gtk::Window>("MainWindow",window);
        snippet_tv = boost::shared_ptr<SnippetTreeView>(new SnippetTreeView(XmlRef));
        snippet_tv->AddLanguage("C++");
        snippet_tv->AddCategory("C++","File I/O");
        snippet_tv->AddSnippet("C++","File I/O","Reading files",1ULL);
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
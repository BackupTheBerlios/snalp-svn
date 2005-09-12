#include "mainwindow.h"

MainWindow::MainWindow()
{
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
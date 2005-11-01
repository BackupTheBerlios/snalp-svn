// snalp.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "FowardDeclarations.h"
#include <iostream>
#include <typeinfo>
#include <glibmm/exception.h>
#include <libglademm/xml.h>
#include "SnalpException.h"
#include "Database.h"
#include "debughelper.h"
#include "MainWindow.h"

#include "DatabaseTests.h"

int main(int argc, char** argv)
{
  //  DatabaseTests tests;
  //  tests.StartTests();
  //  return 0;
  // Debugging only at the moment
    int ret = 0;
    try
    {
        ret = MainWindow::Run(argc,argv);
    }
    catch(SnalpException & e)
    {
        SNALP_ERROR( "Caught " << typeid(e).name() << " Message: " << e.what() );
    }
    catch( Gnome::Glade::XmlError const & e )
    {
        SNALP_ERROR( "Caught " << typeid(e).name() << " Message: " << e.what() );
    }
    catch( std::exception const & e )
    {
        SNALP_ERROR( "Caught " << typeid(e).name() << " Message: " << e.what() );
    }
    catch( Glib::Exception const & e )
    {
        SNALP_ERROR( "Caught " << typeid(e).name() << " Message: " << e.what() );
    }
    catch( ... )
    {
        SNALP_ERROR( "Unknown exception caught" );
    }
}

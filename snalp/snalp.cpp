// snalp.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <iostream>
#include <typeinfo>
#include "SnalpException.h"
#include "Database.h"
#include "debughelpher.h"
#include "MainWindow.h"

int main(int argc, char** argv)
{
    int ret = 0;
    try
    {
        ret = MainWindow::Run(argc,argv);
    }
    catch(SnalpException & e)
    {
        SNALP_ERROR( "Caught " << typeid(e).what() << " Message: " << e.what() );
    }
    catch(...)
    {
        SNALP_ERROR( "Caught " << typeid(e).what() << " Message: " << e.what() );
    }
}

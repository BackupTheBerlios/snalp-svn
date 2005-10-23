// snalp.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <iostream>
#include <typeinfo>
#include "SnalpException.h"
#include "Database.h"
#include "debughelper.h"
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
        SNALP_ERROR( "Caught " << typeid(e).name() << " Message: " << e.what() );
    }
    catch(...)
    {
        SNALP_ERROR( "Non specified exception caught");
    }
}

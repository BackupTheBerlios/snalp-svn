// snalp.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#pragma warning( disable :4250)
#pragma warning( disable :4541)

#include <iostream>
#include "Database.h"
#include "debughelpher.h"
#include "MainWindow.h"

int main(int argc, char** argv)
{
    return MainWindow::Run(argc,argv);
}

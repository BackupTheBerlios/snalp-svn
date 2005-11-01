#include <iostream>
#include "DatabaseTests.h"

DatabaseTests::DatabaseTests(void)
{
}

DatabaseTests::~DatabaseTests(void)
{
}

void DatabaseTests::StartTests()
{
    InsertTest();
    ExistsCheck();
    std::system("Pause");
}

void DatabaseTests::InsertTest()    
{
    m_database.AddGroup("Gruppe1");
    m_database.AddGroup("Gruppe2");
    m_database.AddGroup("Gruppe3");
    m_database.AddLanguage("C++");
    m_database.AddLanguage("C");
    m_database.AddLanguage("C#");
}

void DatabaseTests::ExistsCheck()
{
    std::cout << "Checks case insensitive" << std::endl;
    std::cout << std::boolalpha << m_database.ExistsGroup("GrUppe1") << std::endl;
    std::cout << std::boolalpha << m_database.ExistsGroup("GruPPe2") << std::endl;
    std::cout << std::boolalpha << m_database.ExistsGroup("GruppE3") << std::endl;
    std::cout << std::boolalpha << m_database.ExistsLanguage("c++")  << std::endl;
    std::cout << std::boolalpha << m_database.ExistsLanguage("c")    << std::endl;
    std::cout << std::boolalpha << m_database.ExistsLanguage("c#")   << std::endl;
}
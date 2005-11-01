#pragma once
#include "Database.h"

class DatabaseTests
{
public:
    DatabaseTests(void);
    ~DatabaseTests(void);
    void StartTests();
    void InsertTest();
    void ExistsCheck();
private:
    Database m_database;
};

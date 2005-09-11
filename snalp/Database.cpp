#include "database.h"
#include "debughelpher.h"

#pragma comment(lib,"libsqlite3/release/libsqlite3.lib")

char const DatabaseSchemaCreation[] = 
{
    "BEGIN TRANSACTION;\n"
    "CREATE TABLE Languages( id integer primary key , name text );\n"
    "CREATE TABLE Categories( id integer primary key , name text );\n"
    "CREATE TABLE Snippets( id integer primary key , topic text , description text , dependencies text , categorie integer , language integer , author text , snippet_data text );\n"
    "COMMIT;\n"
};

//##################################################################
Database::Database()
{
    m_db_path = "snalp.db";
    m_db = 0;
    Open();
}
//##################################################################
Database::~Database()
{
    Close();
}
//##################################################################
void Database::Open()
{
    Close();
    if(sqlite3_open(m_db_path.c_str(),&m_db) != SQLITE_OK)
        m_db = 0;
}
//##################################################################
void Database::Close()
{
    if(m_db)
        sqlite3_close(m_db);
}
//##################################################################
StringList const & Database::GetLanguages()
{
    return m_languages;
}
//##################################################################
StringList const & Database::GetGroups()
{
    return m_groups;
}
//##################################################################
std::string const & Database::GetTopic( uint64_t id )
{
    return m_topic_map[id];
}
//##################################################################
void Database::CreateEmptyDatabase()
{
    if(!m_db)
        return;
    char * errmsg = 0;
    if(sqlite3_exec(m_db,DatabaseSchemaCreation,0,0,&errmsg) != SQLITE_OK)
    {
        SNALP_ERROR(" FATAL: " << errmsg);
        sqlite3_free(errmsg);
    }        
}
//##################################################################
void Database::InitCheck()
{
    if(m_db)
    {
            
    }
}
//##################################################################


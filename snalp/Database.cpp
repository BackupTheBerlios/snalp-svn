#include "database.h"
#include "debughelpher.h"
#include <boost/lexical_cast.hpp>

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
    Reload();
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
    {
        SNALP_LOG("Database could not be opened");
        m_db = 0;
    }
    else
        InitCheck();
}
//##################################################################
void Database::Close()
{
    if(m_db)
        sqlite3_close(m_db);
}
//##################################################################
IdToStringMap & Database::GetLanguages()
{
    return m_languages;
}
//##################################################################
IdToStringMap & Database::GetGroups()
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
int Database::CallbackMethod(Database * _this,int count ,char**data, char**colname)
{
    ResultMap map;
    for(int i = 0; i < count; ++i)
        map[colname[i]] = ( data[i] ? data[i] : "NULL" );
    _this->m_result.push_back(map);
    return SQLITE_OK;
}
//##################################################################
void Database::Query(std::string const & sqlstatement )
{
    if(!m_db)
        return;
    char * errmsg = 0;
    if( sqlite3_exec(m_db,sqlstatement.c_str(),(sqlite3_callback)Database::CallbackMethod,this,&errmsg) != SQLITE_OK)
    {
        SNALP_DEBUG("[QUERY FAILED]" << errmsg);
        sqlite3_free(errmsg);
    }
}
//##################################################################
void Database::InitCheck()
{
    if(!m_db)
        return;
    std::string sql_statement = 
        "SELECT tbl_name from sqlite_master "
        "where tbl_name = 'Languages'       "
        "or tbl_name    = 'Categories'      "
        "or tbl_name    = 'Snippets';       ";

    m_result.clear();
    Query(sql_statement);
    if(m_result.size() != 3)
    {
        SNALP_DEBUG("Database corrupted or empty creating new");
        CreateEmptyDatabase();
    }
}
//##################################################################
void Database::Reload()
{
    if(!m_db)
        return;
    m_result.clear();
    std::string sql_lang = "SELECT * FROM LANGUAGES;";
    std::string sql_cat  = "SELECT * FROM CATEGORIES;";
    Query(sql_lang);
    try
    {
        m_languages.clear();
        for(size_t i = 0; i < m_result.size();++i)
            m_languages[boost::lexical_cast<uint64_t>(m_result[i]["id"])] = m_result[i]["name"];
    }
    catch(boost::bad_lexical_cast & e)
    {
        SNALP_ERROR("[FATAL][Loading languages] lexical_cast<uint64_t> failed | " << e.what());
    }
    m_result.clear();
    Query(sql_cat);
    try
    {
        m_groups.clear();
        for(size_t i = 0; i < m_result.size();++i)
            m_groups[boost::lexical_cast<uint64_t>(m_result[i]["id"])] = m_result[i]["name"];
    }
    catch(boost::bad_lexical_cast & e)
    {
        SNALP_ERROR("[FATAL][Loading categories] lexical_cast<uint64_t> failed | " << e.what());
    }
    LoadTopics();
}
//##################################################################

//##################################################################

#include <iostream>
#include "Database.h"
#include "debughelper.h"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

#ifdef _MSC_VER
    #pragma comment(lib,"libsqlite3/release/libsqlite3.lib")
#endif 

#include "libsqlite3/sqlite3.h"

char const DatabaseSchemaCreation[] = 
{
    "BEGIN TRANSACTION;\n"
    "CREATE TABLE Languages( id integer primary key , name text );\n"
    "CREATE TABLE Categories( id integer primary key , name text );\n"
    "CREATE TABLE Snippets( id integer primary key , topic text , description text , dependencies text , category integer , language integer , author text , snippet_data text );\n"
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
TreeviewIdMap & Database::GetAll()
{
    return m_treeview_id_map;
}
//##################################################################
void Database::CreateEmptyDatabase()
{
    Execute(DatabaseSchemaCreation);
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
    try
    {
        if(!m_db)
            return;
        static char const * sql_cmds[] = { "SELECT * FROM LANGUAGES;","SELECT * FROM CATEGORIES;"};
        static IdToStringMap * maps[] = { &m_languages , &m_groups };
        for(size_t i = 0; i < 2; ++i)
        {
            m_result.clear();
            Query(sql_cmds[i]);
            maps[i]->clear();
            for(size_t j = 0; j < m_result.size();++j)
                (*maps[i])[boost::lexical_cast<uint64_t>(m_result[j]["id"])] = m_result[j]["name"];
        }

    }
    catch(boost::bad_lexical_cast & e)
    {
        SNALP_ERROR("[FATAL][Loading categories] lexical_cast<uint64_t> failed | " << e.what());
    }
    LoadTopics();
}
//##################################################################
void Database::LoadTopics()
{
    try
    {
        m_result.clear();
        m_treeview_id_map.clear();
        std::string sql_topic = "SELECT language,category,id,topic from Snippets;";
        Query(sql_topic);

        for(size_t i = 0; i < m_result.size(); ++i)
        {
            uint64_t id       = boost::lexical_cast<uint64_t>(m_result[i]["id"]);
            unsigned lang_id  = boost::lexical_cast<unsigned>(m_result[i]["language"]);
            unsigned group_id = boost::lexical_cast<unsigned>(m_result[i]["category"]);
            m_topic_map[id] = m_result[i]["topic"];
            m_treeview_id_map[lang_id][group_id].push_back(id);
        }

    }
    catch( boost::bad_lexical_cast & e )
    {
        SNALP_ERROR("[FATAL][Loading snippet topics] lexical_cast<uint64_t> failed | " << e.what());
    }
}
//##################################################################
void Database::AddLanguage( std::string const & lang )
{
    if(ExistsLanguage(lang))
        return; // Nothing todo
    std::ostringstream ostr;
    ostr << "INSERT INTO LANGUAGES VALUES( NULL , '" << lang << "');";
    Execute(ostr.str());
    Reload();
}
//##################################################################
void Database::AddGroup( std::string const & group )
{
    if(ExistsGroup(group))
        return; // Nothing todo
    std::ostringstream ostr;
    ostr << "INSERT INTO CATEGORIES VALUES( NULL , '"<< group << "');";
    Execute(ostr.str());
    Reload();
}
//##################################################################
void Database::AddSnippet( SnippetItem const & item )
{
    std::string format_string = "INSERT INTO SNIPPETS VALUES( NULL,'%1%','%2%','%3%',%4%,%5%,'%6%','%7%');";
    boost::format fmt(format_string);
    fmt % item.topic 
        % item.description 
        % item.dependencies
        % item.category
        % item.language
        % item.author
        % item.snippet_data;
     Execute(fmt.str());
     Reload();
}
//##################################################################
void Database::GetSnippet( uint64_t id , SnippetItem & item )
{
    m_result.clear();
    std::ostringstream ostr;
    ostr << "SELECT * from SNIPPET where id = " << id;
    Query(ostr.str());
    try
    {
        if(m_result.size())
        {
            item.author       = m_result[0]["author"];
            item.topic        = m_result[0]["topic"];
            item.dependencies = m_result[0]["dependencies"];
            item.description  = m_result[0]["description"];
            item.snippet_data = m_result[0]["snippet_data"];
            item.id           = boost::lexical_cast<unsigned>(m_result[0]["id"]);
            item.language     = boost::lexical_cast<unsigned>(m_result[0]["language"]);
            item.category     = boost::lexical_cast<unsigned>(m_result[0]["category"]);
        }
    }
    catch( boost::bad_lexical_cast & e )
    {
        SNALP_ERROR("[FATAL][Loading snippet] lexical_cast<uint64_t> failed | " << e.what());
    }
}
//##################################################################
void Database::Execute( std::string const & sqlstatement )
{
    if(!m_db)
        return;
    char * errmsg = 0;
    if(sqlite3_exec(m_db,sqlstatement.c_str(),0,0,&errmsg) != SQLITE_OK)
    {
        SNALP_ERROR(errmsg);
        sqlite3_free(errmsg);
    }        
}
//##################################################################
bool Database::ExistsLanguage( std::string const & lang )
{
    return Exists("Languages","name",lang);
}
//##################################################################
bool Database::ExistsGroup( std::string const & cat )
{
    return Exists("Categories","name",cat);
}
//##################################################################
bool Database::Exists( std::string const & table , std::string const & col_name , std::string const & value )
{
    boost::format fmt("SELECT %2% from %1% WHERE %2% LIKE '%3%';");
    fmt % table % col_name % value;
    m_result.clear();
    Query(fmt.str());
    return !m_result.empty();
}
//##################################################################

#ifndef GUARD_DATABASE_H_INCLUDED
#define GUARD_DATABASE_H_INCLUDED
#include "types.h"

struct sqlite3;
struct SnippetItem
{
    uint64_t id;
    unsigned language;
    unsigned category;
    std::string topic;
    std::string author;
    std::string description;
    std::string dependencies;
    std::string snippet_data;
};

class Database
{
public:
    Database();
    ~Database();
    IdToStringMap & GetLanguages();
    IdToStringMap & GetGroups();
    TreeviewIdMap & GetAll();
    std::string const & GetTopic( uint64_t id );
    void AddLanguage( std::string const & lang );
    void AddGroup( std::string const & group );
    void AddSnippet( SnippetItem const & item );
    void GetSnippet( uint64_t id , SnippetItem & item );

    bool ExistsLanguage( std::string const & lang );
    bool ExistsGroup( std::string const & cat );
    bool Exists( std::string const & table , std::string const & col_name , std::string const & value );
private:
    void Execute( std::string const & sqlstatement );
    void Query(std::string const & sqlstatement );
    void CreateEmptyDatabase();
    void InitCheck();
    void Open();
    void Close();
    void Reload();
    void LoadTopics();
    IdToStringMap m_topic_map; 
    TreeviewIdMap m_treeview_id_map;
    
    IdToStringMap m_languages;
    IdToStringMap m_groups;
    ResultMapList m_result;
    sqlite3 *     m_db;
    std::string   m_db_path;
    static int CallbackMethod(Database*,int,char**, char**);
};

#endif  //GUARD_DATABASE_H_INCLUDED

#ifndef GUARD_DATABASE_H_INCLUDED
#define GUARD_DATABASE_H_INCLUDED
#include "sqlite3.h"
#include "types.h"
#include <vector>
#include <string>
#include <map>

typedef std::vector< std::string >         StringList;
typedef std::vector<uint64_t>              IdList;
typedef std::map< uint64_t , std::string > IdToStringMap;
typedef std::map< unsigned , std::map< unsigned , IdList > > TreeviewIdMap;

class Database
{
public:
    Database();
    ~Database();
    StringList const & GetLanguages();
    StringList const & GetGroups();
    std::string const & GetTopic( uint64_t id );
private:

    void CreateEmptyDatabase();
    void InitCheck();
    void Open();
    void Close();

    IdToStringMap m_topic_map; 
    TreeviewIdMap m_treeview_id_map;
    
    StringList m_languages;
    StringList m_groups;
    
    sqlite3 * m_db;
    std::string m_db_path;
};

#endif  //GUARD_DATABASE_H_INCLUDED

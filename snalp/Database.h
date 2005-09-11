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
typedef std::map< std::string , std::string > ResultMap;
typedef std::vector<ResultMap>                ResultMapList;
class Database
{
public:
    Database();
    ~Database();
    IdToStringMap & GetLanguages();
    IdToStringMap & GetGroups();
    std::string const & GetTopic( uint64_t id );
private:
    void Query(std::string const & sqlstatement );
    void CreateEmptyDatabase();
    void InitCheck();
    void Open();
    void Close();
    void Reload();
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

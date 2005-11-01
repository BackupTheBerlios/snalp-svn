#ifndef GUARD_TYPES_H_INCLUDED
#define GUARD_TYPES_H_INCLUDED 1

#include <vector>
#include <string>
#include <map>
#include <boost/cstdint.hpp>

using boost::uint64_t;
using boost::uint32_t;
using boost::uint16_t;
using boost::uint8_t;

using boost::int64_t;
using boost::int32_t;
using boost::int16_t;
using boost::int8_t;

typedef std::vector< std::string >            StringList;
typedef std::vector<uint64_t>                 IdList;
typedef std::map< uint64_t , std::string >    IdToStringMap;
typedef std::map< unsigned , IdList >         IdToIdListMap;
typedef std::map< unsigned , IdToIdListMap >  TreeviewIdMap;
typedef std::map< std::string , std::string > ResultMap;
typedef std::vector<ResultMap>                ResultMapList;

#endif  //GUARD_TYPES_H_INCLUDED


#ifndef GUARD_DEBUGHELPER_H_INCLUDED
#define GUARD_DEBUGHELPER_H_INCLUDED
#include <fstream>
#include <sstream>

inline void WriteToDebugFile( std::ostream const & ostr )
{
    static std::ofstream DebugFilestream("DEBUG.txt");    
    DebugFilestream << ostr;
}

inline void WriteToErrorFile( std::ostream const & ostr )
{
    static std::ofstream ErrorFilestream("ERROR.txt");    
    ErrorFilestream << ostr;
}

#define SNALP_LOG(x)   { std::ostringstream LOG_OSTR;   LOG_OSTR   << "[" << __FILE__ << ":"<< __LINE__ << "][ " << __FUNCTION__ << " ]" << x << std::endl; WriteToDebugFile(LOG_OSTR);   }
#define SNALP_ERROR(x) { std::ostringstream ERROR_OSTR; ERROR_OSTR << "[" << __FILE__ << ":"<< __LINE__ << "][ " << __FUNCTION__ << " ]" << x << std::endl; WriteToErrorFile(ERROR_OSTR); }

#endif  //GUARD_DEBUGHELPER_H_INCLUDED

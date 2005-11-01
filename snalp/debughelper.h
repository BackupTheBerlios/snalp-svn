#ifndef GUARD_DEBUGHELPER_H_INCLUDED
#define GUARD_DEBUGHELPER_H_INCLUDED 1

#include <fstream>
#include <sstream>

inline void WriteToDebugFile( std::ostringstream const & ostr )
{
    std::ofstream DebugFilestream("DEBUG.TXT",std::ios::ate);    
    DebugFilestream << ostr.str();
}

inline void WriteToErrorFile( std::ostringstream const & ostr )
{
    std::ofstream ErrorFilestream("ERROR.TXT",std::ios::ate);    
    ErrorFilestream << ostr.str();
}
#define SNALP_LOG(x)   { std::ostringstream LOG_OSTR;   LOG_OSTR   << "[" << __FILE__ << ":"<< __LINE__ << "][ " << __FUNCTION__ << " ]" << x << std::endl; WriteToDebugFile(LOG_OSTR);   }
#define SNALP_ERROR(x) { std::ostringstream ERROR_OSTR; ERROR_OSTR << "[" << __FILE__ << ":"<< __LINE__ << "][ " << __FUNCTION__ << " ]" << x << std::endl; WriteToErrorFile(ERROR_OSTR); }

#ifdef _DEBUG
    #define SNALP_DEBUG(x) SNALP_LOG("[DEBUG]" << x)
#else
    #define SNALP_DEBUG(x) SNALP_LOG("[DEBUG]" << x)
#endif 

#endif  //GUARD_DEBUGHELPER_H_INCLUDED

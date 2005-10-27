#ifndef GUARD_SNALPEXCEPTION_H_INCLUDED
#define GUARD_SNALPEXCEPTION_H_INCLUDED 1
#include <string>
#include <fstream>

#define THROW_SNALP_EXCEPTION( ExceptionType , ExceptionMessage )\
    {\
        std::ostringstream ostr;\
        ostr << "["<< __FILE__ << ":" << __LINE__ << "]" << "(" << __FUNCTION__ << ") " << ExceptionMessage;\
        throw ExceptionType(ostr.str());\
    }

struct SnalpException
{
    SnalpException()
    : m_message("")
    {
        std::ofstream ofs("SNALP_EXCEPTIONS_LOG.txt",std::ios::app);
        ofs << m_message << std::endl;
    }
    SnalpException(std::string const & msg)
    : m_message(msg)
    {
        std::ofstream ofs("SNALP_EXCEPTIONS_LOG.txt",std::ios::app);
        ofs << m_message << std::endl;
    }
    virtual ~SnalpException(){}
    std::string const & what(){ return m_message; }
private:
    std::string m_message;
};

struct SnalpFatalException : SnalpException
{
    SnalpFatalException()
    : SnalpException("Unspecified fatal exception"){}
    SnalpFatalException(std::string const & msg)
    : SnalpException("SnalpFatalException: " + msg){}
    virtual ~SnalpFatalException(){}
};

struct SnalpNotFoundException : SnalpException
{
    SnalpNotFoundException()
    : SnalpException("Unspecified SnalpNotFoundException"){}
    SnalpNotFoundException(std::string const & msg)
    : SnalpException("SnalpNotFoundException: " + msg){}
    virtual ~SnalpNotFoundException(){}
};

#endif // GUARD_SNALPEXCEPTION_H_INCLUDED

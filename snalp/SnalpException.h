#ifndef GUARD_SNALPEXCEPTION_H_INCLUDED
#define GUARD_SNALPEXCEPTION_H_INCLUDED 1
#include <string>

struct SnalpException
{
    SnalpException()
    : m_message(""){}
    SnalpException(std::string const & msg)
    : m_message(msg){}
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
    : SnalpException("Fatal: " + msg){}
    virtual ~SnalpFatalException(){}
};

#endif // GUARD_SNALPEXCEPTION_H_INCLUDED

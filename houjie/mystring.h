#ifndef _MYSTRING_
#define _MYSTRING_

class Mystring
{
    public:
        //construcor
        Mystring(const char* cstr=0);
        //big three
        Mystring(const Mystring& s);
        Mystring& operator = (const Mystring& s);
        ~Mystring();
        //member func inline
        char* get_c_str() const
        {
            return m_data;
        }

    private:
        char* m_data;
};

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Mystring::Mystring(const char* cstr)
{
    if(cstr)
    {
        m_data=new char[strlen(cstr)+1];
        strcpy(m_data,cstr);
    }
    else
    {
        m_data=new char[1];
        *m_data = '\0';
    }
}

Mystring::~Mystring()
{
    delete [] m_data;
}

Mystring::Mystring(const Mystring& str)
{
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
}

Mystring&
Mystring::operator = (const Mystring& str)
{
    //self assignment
    if(this==&str)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
    return *this;
}

#include <iostream>
using namespace std;

inline ostream& 
operator << (ostream& os,const Mystring& s)
{
    os<<s.get_c_str();
}

#endif
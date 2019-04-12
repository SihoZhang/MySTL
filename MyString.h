/* 
* author:Siho Zhang
* Time:2019/4/12
*/
#ifndef __MYSTRING__
#define __MYSTRING__
#include <iostream>
#include <cstring>

using std::ostream;
using std::istream;

namespace zsh{    
    class MyString{
    public:
        MyString(const char* cstr = 0);
        MyString(const MyString& str);
        MyString& operator=(const MyString& str);
        MyString& operator+=(const MyString& str);
        ~MyString();
        friend ostream& operator<<(ostream& os, const MyString& str);
        friend istream& operator>>(istream& is, MyString& str);
        const unsigned length() const;
    private:
        char* m_data;
        };
    //Constructor(default)
    inline
    MyString::MyString(const char* cstr)
    {
        if(cstr) {
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data, cstr);
        }
        else {
            m_data = new char[1];
            *m_data = '\0';
        }
    }
    //Constructor(copy)
    inline
    MyString::MyString(const MyString& str)
    {
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }
    //assign
    inline MyString& 
    MyString::operator=(const MyString& str)
    {
        if(this == &str)
            return *this;
        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }
    //+=
    inline MyString&
    MyString::operator+=(const MyString& str)
    {
        char* new_data = new char[length() + str.length() + 1];
        strcpy(new_data, m_data);
        delete[] m_data;
        strcat(new_data, str.m_data);
        m_data = new_data;
        return *this;
    }
    //Destructor
    inline
    MyString::~MyString()
    {
        delete[] m_data;
    }
    //<<
    inline ostream&
    operator<<(ostream& os,const MyString& str)
    {
        return os<<str.m_data;
    }
    //>>
    inline istream&
    operator>>(istream& is,MyString& str)
    {
        char buff[4096];
        is >> buff;
        delete[] str.m_data;
        str.m_data = new char[strlen(buff) + 1];
        strcpy(str.m_data, buff);
        return is;
    }
    //length
    inline const unsigned
    MyString::length() const
    {
        return strlen(m_data);
    }
}
#endif  /* __MYSTRING__ */

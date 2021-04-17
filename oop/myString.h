#ifndef __MYSTRING__
#define __MYSTRING__

class MyString
{
public:
    MyString(const char* cstr = 0);
    MyString(const MyString& str);
    MyString& operator = (const MyString& str);
    ~MyString();

    char* get_c_str() const { return m_data; }

private:
    char* m_data;
};

//ctor
#include<cstring>
MyString::MyString(const char* cstr){
    if (cstr){
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }else{
        m_data = new char[1];
        *m_data = '\0';
    }
}
MyString::MyString(const MyString& str){
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}
MyString& MyString::operator = (const MyString& str){
    if (this == &str) return *this;
    if(m_data) delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

//dtor
MyString::~MyString(){
    delete[] m_data;
}

//cout
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const MyString& str)
{
   os << str.get_c_str();
   return os;
}
#endif
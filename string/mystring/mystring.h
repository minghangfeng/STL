#ifndef _MYSTRING_
#define _MYSTRING_
#include <iostream>
#include <cstring>
#include <assert.h>

using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class MyString{
public:
    MyString(const char* str = NULL);
    MyString(const MyString &str);
    ~MyString();
    int length();
    int find(const MyString &str);

    MyString operator=(const MyString &str);
    MyString operator+(const MyString &str);
    char operator[](int i) const;
    friend istream & operator >> (istream &is, MyString &str);
    friend ostream & operator << (ostream &is, MyString &str);


private:
    int string_length;
    char *data;

};
#endif
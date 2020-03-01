#include "mystring.h"


MyString::MyString(const char* str){
    if(!str){
        length = 0;
        data = new char('\0');
    }
    else{
        length = strlen(str);
        data = new char[length+1];
        strcpy(data, str);
    }
}


MyString::MyString(const MyString &str){
    length = str.length;
    data = new char[length + 1];
    strcpy(data, str.data);
}


MyString::~MyString(){
    delete[] data;
}


MyString MyString::operator=(const MyString &str){
    length = str.length;
    delete[] data;
    data = new char[length + 1];
    strcpy(data, str.data);
    return *this;
}


MyString MyString::operator+(const MyString &str){
    char *tmp = new char[length + 1];
    strcpy(tmp, data);
    length = length + str.length;
    delete[] data;
    data = new char[length + 1];
    strcpy(data, tmp);
    strcat(data, str.data);
    return *this;
}


char* MyString::c_str(){
    return data;
}


ostream & operator << (ostream &is, MyString &str){
    is << str.data;
    return is;
}


istream & operator >> (istream &is, MyString &str){
    char buff[4096];
    is >> buff;
    delete[] str.data;
    str.length = strlen(buff);
    str.data = new char[strlen(buff)+1];
    strcpy(str.data, buff);
    return is;
}
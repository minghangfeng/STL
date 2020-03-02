#include "mystring.h"

MyString::MyString(const char* str){
    if(!str){
        string_length = 0;
        data = new char('\0');
    }
    else{
        string_length = strlen(str);
        data = new char[string_length+1];
        strcpy(data, str);
    }
}


MyString::MyString(const MyString &str){
    string_length = str.string_length;
    data = new char[string_length + 1];
    strcpy(data, str.data);
}


MyString::~MyString(){
    delete[] data;
}


int MyString::length(){
    return string_length;
}


int MyString::find(const MyString &str){
    if (str.string_length > string_length){
        return -1;
    }
    else{
        int i = 0;
        int j = 0;
        for (i; i < str.string_length; i++){
            for (j; j < string_length; j++){
                if (str[i] == data[j]){
                    j = j + 1;
                    break;
                }else{
                    if(i > 0){
                        return -1;
                    }
                }
            }
        }
        return j - str.string_length;
    }
}


MyString MyString::operator=(const MyString &str){
    string_length = str.string_length;
    delete[] data;
    data = new char[string_length + 1];
    strcpy(data, str.data);
    return *this;
}


MyString MyString::operator+(const MyString &str){
    char *tmp = new char[string_length + 1];
    strcpy(tmp, data);
    string_length = string_length + str.string_length;
    delete[] data;
    data = new char[string_length + 1];
    strcpy(data, tmp);
    strcat(data, str.data);
    return *this;
}

char MyString::operator[](int i) const{
    assert(i < string_length);
    return data[i];
}


ostream & operator << (ostream &is, MyString &str){
    is << str.data;
    return is;
}


istream & operator >> (istream &is, MyString &str){
    char buff[4096];
    is >> buff;
    delete[] str.data;
    str.string_length = strlen(buff);
    str.data = new char[strlen(buff)+1];
    strcpy(str.data, buff);
    return is;
}
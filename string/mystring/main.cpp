#include "mystring.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    MyString str1 = "16266366646666";
    MyString str2("12221");
    int *next = new int[str2.length()];
    str2.get_next(str2, next);
    cout<<next[1]<<endl;
}
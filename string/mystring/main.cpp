#include "mystring.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    MyString str1 = "abcdefgfgfg";
    MyString str2("fg");
    cout<<str1.find(str2)<<endl;
    MyString str3;
    str3 = str1 + str2;
    cout<<str3<<endl;
}
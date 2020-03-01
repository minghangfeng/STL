#include "mystring.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
    MyString str1 = "111";
    MyString str2 = "222";
    MyString str3 = str1 + str2;
    cout<<str3<<endl;
    cin>>str3;
    cout<<str3<<endl;
}
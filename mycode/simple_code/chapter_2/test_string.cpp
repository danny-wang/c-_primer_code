//全局变量会默认初始化，函数内部的变量不会默认初始化
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string s("123");
    getline(cin,s);
    //transform string s to upper format
    for(auto &c :s){
        c = toupper(c);
    }
    cout<<s<<endl;
    //transform the first word of string s to upper format
    getline(cin,s);
    for(decltype(s.size()) index=0; index!=s.size() && !isspace(s[index]);++index )
        s[index] = toupper(s[index]);
    cout<<s<<endl;
    return 0;
}

//全局变量会默认初始化，函数内部的变量不会默认初始化
#include <iostream>
#include <string>
using namespace std;
struct Sales_data{
    string bookNo;
    unsigned units_sold = 99999;
    double revenue;
};

void f(){
    Sales_data data;
    cout<<"data:"<<data.units_sold<<" "<<data.revenue<<endl;
}
int i = 42;
int main(){
    int i=100;
    int j=i;
    cout<<j<<endl;
    j=::i;
    cout<<j<<endl;
    Sales_data data;
    cout<<"data:"<<data.units_sold<<" "<<data.revenue<<endl;
    f();
    return 0;
}

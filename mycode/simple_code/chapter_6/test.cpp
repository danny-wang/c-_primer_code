#include <iostream>
#include <cstddef>
using namespace std;

size_t count_calls(){
    static size_t ctr=0;
    return ++ctr;
}

int main(){
    for(size_t i=0;i<10;i++){
        cout<<count_calls()<<endl;
    }
    int a=3;
    int *ptr=&a;
    const int *ptr2=ptr;
    cout<<*ptr2<<endl;
    return 0;
}

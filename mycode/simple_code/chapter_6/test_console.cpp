#include <iostream>
#include <cstddef>
#include <cassert>
using namespace std;


int main (int argc, char** argv){
    cout<<"argc = "<<argc<<endl;
    //assert(argc<3);
    if(argc<3)
        cout<<"Error: "<<__FILE__
            <<" :in funciton "<<__func__
            <<" at line "<<__LINE__<<endl
            <<"     Compiled on "<<__DATE__
            <<" at "<<__TIME__<<endl;
    for(size_t i=0;i<argc;i++){
        cout<<argv[i]<<endl;
    }
    return 0;
}

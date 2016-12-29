
#include "MurmurHash.h"
#include "gtest/gtest.h"
#include <string>
using namespace std;


TEST(MurmurHash_test, Normal) {
 
 	string a("i love my country");
    uint64_t a_hash= MurmurHash64A(a.c_str(),a.size(),0xEE6B27EB);
    cout<<"a= "<<hex<<a_hash<<endl;
    string b("i love my country");
    uint64_t b_hash= MurmurHash64A(b.c_str(),b.size(),0xEE6B27EB);
    cout<<"b= "<<hex<<b_hash<<endl;
    string c("i love china");
    uint64_t c_hash= MurmurHash64A(c.c_str(),c.size(),0xEE6B27EB);
    cout<<"c= "<<hex<<c_hash<<endl;
    string d("i love my country");
    uint64_t d_hash= MurmurHash64A(d.c_str(),d.size(),16);
    cout<<"d= "<<hex<<d_hash<<endl;
    string f("i love my countryy");
    uint64_t f_hash= MurmurHash64A(f.c_str(),f.size(),0xEE6B27EB);
    cout<<"f= "<<hex<<f_hash<<endl;
    EXPECT_EQ(a_hash, b_hash);
    EXPECT_NE(a_hash, c_hash);
    EXPECT_NE(a_hash, d_hash);


}
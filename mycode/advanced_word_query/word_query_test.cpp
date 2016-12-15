
#include "Query_base.h"
#include "gtest/gtest.h"
#include <fstream>
#include <string>
using namespace std;
void runqueries(ifstream &infile){
    TextQuery tq(infile);
    while(true){
        cout<<"enter word to look for, or q to quit:"<<endl;
        string s;
        if(!(cin>>s)|| s=="q")
            break;
        print(cout, tq.query(s))<<endl;
    }
}

TEST(word_query_test, Negative) {
 
 	//ifstream infile("word_query_class/example.txt");
    //runqueries(infile);
    ifstream infile("word_query_class/example.txt");
    TextQuery tq(infile);
    Query q= Query("wise") & Query("men") | Query("wave");
    print(cout,  q.eval(tq))<<endl;
    cout<<q<<endl;
    EXPECT_EQ(1, 1);



}
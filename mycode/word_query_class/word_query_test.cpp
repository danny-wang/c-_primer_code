
#include "TextQuery.h"
#include "QueryResult.h"
#include "gtest/gtest.h"
#include <fstream>
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
 
 	ifstream infile("word_query_class/example.txt");
    runqueries(infile);
    EXPECT_EQ(1, 1);



}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextQuery.cpp
 * Author: danny
 * 
 * Created on December 12, 2016, 9:06 PM
 */

#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
using namespace std;
TextQuery::TextQuery(ifstream &is):file(new vector<string>) {
    string text;
    while(getline(is,text)){  //for every line
        file->push_back(text); //save content of this line
        int n=file->size()-1;  //current lino_no
        istringstream line(text);
        string word;
        while(line>>word){
            auto &lines=wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string&s) const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc=wm.find(s);
    if(loc==wm.end())
        return QueryResult(s, nodata, file);
    else
        return QueryResult(s,loc->second,file);
    

}




/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueryResult.cpp
 * Author: danny
 * 
 * Created on December 12, 2016, 9:31 PM
 */

#include "QueryResult.h"
using namespace std;
ostream &print(std::ostream& os, const QueryResult& qr){
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" times"<<endl;
    for(auto num : *qr.lines)
        os<<"\t(line"<<num+1<<")"<<*(qr.file->begin()+num)<<endl;
    return os;
}


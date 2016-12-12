/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrBlob.cpp
 * Author: danny
 * 
 * Created on December 10, 2016, 3:27 PM
 */

#include <exception>
#include "StrBlob.h"
#include "StrBlobPtr.h"
using namespace std;
StrBlob::StrBlob():data(make_shared<vector<string>>()) {
}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(make_shared<vector<string>>(il)) {

}

void StrBlob::check(size_type i, const std::string& msg) const{
    if(i>= data->size())
        throw out_of_range(msg);
    
}

string& StrBlob::front(){
    check(0,"front on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const{
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back(){
    check(0,"back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const{
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0,"pop_back on empty StrBlob");
    return data->pop_back();
}

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end(){
    auto ret=StrBlobPtr(*this, data->size());
    return ret;
}



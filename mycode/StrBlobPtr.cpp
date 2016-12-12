/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrBlobPtr.cpp
 * Author: danny
 * 
 * Created on December 12, 2016, 1:27 PM
 */

#include "StrBlobPtr.h"
#include <exception>
using namespace std;
shared_ptr<vector<string>>
        StrBlobPtr::check(size_t i, const string& msg) const{
    auto ret=wptr.lock();
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i>=ret->size())
        throw std::out_of_range(msg);
    return ret;
}
string& StrBlobPtr::deref() const{
    auto p=check(curr,"dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}




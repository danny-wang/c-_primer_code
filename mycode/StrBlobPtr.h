/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrBlobPtr.h
 * Author: danny
 *
 * Created on December 12, 2016, 1:27 PM
 */

#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <vector>
#include "StrBlob.h"
class StrBlobPtr {
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a, size_t sz=0):
        wptr(a.data),curr(sz){}
    std::string& deref() const;
    StrBlobPtr& incr();
    std::string& operator*() const{
        auto p=check(curr, "defeference past end");
        return (*p)[curr];
    }
    std::string* operator->() const{
        return & this->operator *();
    }
    virtual ~StrBlobPtr()=default;
private:
    std::shared_ptr<std::vector<std::string>>
            check(std::size_t, const std::string&) const; 
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; //current location of vector

};

#endif /* STRBLOBPTR_H */


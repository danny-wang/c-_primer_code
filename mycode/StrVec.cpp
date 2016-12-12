/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrVec.cpp
 * Author: danny
 * 
 * Created on December 9, 2016, 2:16 PM
 */

#include "StrVec.h"
#include <utility>


std::allocator<std::string> StrVec::alloc; 

StrVec::StrVec(const StrVec& orig) {
    auto newdata=alloc_n_copy(orig.begin(), orig.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept
    :elements(s.elements),first_free(s.first_free),cap(s.cap){
    s.elements=s.first_free=s.cap=nullptr;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(std::initializer_list<std::string> il){
    auto data=alloc_n_copy(il.begin(),il.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}

StrVec& StrVec::operator =(StrVec&& rhs) noexcept{
    if(this!=&rhs){
        free();
        elements=rhs.elements;
        first_free=rhs.first_free;
        cap=rhs.cap;
        rhs.elements=rhs.first_free=rhs.cap=nullptr;
    }
    return *this;
}

StrVec& StrVec::operator=(const StrVec& orig){
    auto data=alloc_n_copy(orig.begin(), orig.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}

void StrVec::push_back(const std::string& s){
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string&& s){
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

std::pair<std::string*, std::string*>
        StrVec::alloc_n_copy(const std::string *b, const std::string *e){
    auto data=alloc.allocate(e-b);
    return {data,std::uninitialized_copy(b,e,data)};
   
}

void StrVec::free(){
    if(elements){
        for(auto ite=first_free; ite!=elements;){
            alloc.destroy(--ite);
        }
        alloc.deallocate(elements,cap-elements);
    }
}

void StrVec::reallocate(){
    /**
    auto newcapacity =  size()? 2*size() : 1 ;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0; i!= size(); ++i){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
     **/
    auto newcapacity =  size()? 2*size() : 1 ;
    auto first = alloc.allocate(newcapacity);
    auto last= std::uninitialized_copy(std::make_move_iterator(begin()),std::make_move_iterator(end()),first);
    free();
    elements=first;
    first_free=last;
    cap=elements+newcapacity;
    
}
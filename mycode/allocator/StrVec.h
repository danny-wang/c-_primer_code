/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrVec.h
 * Author: danny
 * Description: simulate a vector<string>
 * Created on December 9, 2016, 2:16 PM
 */

#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>
#include <cstddef>
class StrVec {
public:
    StrVec():elements(nullptr),first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec& orig);
    StrVec(StrVec &&) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& operator=(StrVec&&) noexcept;
    StrVec& operator=(std::initializer_list<std::string>);
    std::string& operator[](std::size_t n){
        return elements[n];
    }
    const std::string& operator[](std::size_t n) const{
        return elements[n];
    }
    virtual ~StrVec();
    void push_back(const std::string&);
    void push_back(std::string&&);
    size_t size() const {
        return first_free-elements;
    }
    size_t capacity() const{
        return cap-elements;
    }
    std::string *begin() const{
        return elements;
    }
    std::string *end() const{
        return  first_free;
    }
private:
    static std::allocator<std::string> alloc; //allocate memory
    std::string *elements; //first element of vector
    std::string *first_free;// first free element;
    std::string *cap; //after the last element of vector
    void reallocate();//get more space and cope exist elements
    void free(); //destroy elements and free memory space
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);
    void chk_n_alloc(){
        if(size()==capacity())
            reallocate();
    }
};




#endif /* STRVEC_H */


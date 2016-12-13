/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrBlob.h
 * Author: danny
 *
 * Created on December 10, 2016, 3:27 PM
 */

#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <vector>
class StrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlobPtr begin();
    StrBlobPtr end();
    size_type size() const{
        return data->size();
    }
    bool empty(){
        return data->empty();
    }
    void push_back(const std::string &t){
        data->push_back(t);
    }
    void pop_back();
    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;
    virtual ~StrBlob()=default;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;

};

#endif /* STRBLOB_H */


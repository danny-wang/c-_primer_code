/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StrBlob.h
 * Author: danny
 * Description: simulate vector<>
 * Created on December 10, 2016, 3:27 PM
 */

#ifndef BLOB_H
#define BLOB_H
#include <memory>
#include <vector>
#include <exception>
#include <string>
template <typename T>
class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    //number of elements in Blob
    size_type size() const{
        return data->size();
    }
    bool empty() const{
        return data->empty();
    }
    //add and delete element
    void push_back(const T &t){
        data->push_back(t);
    }
    void push_back(T &&t){
        data->push_back(std::move(t));
    }
    void pop_back();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
    T& operator[](size_type i);
    const T& operator[](size_type i) const;
    virtual ~Blob()=default;
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;

};
template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()){ }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)){ }


template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const{
    if(i>= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back(){
    check(0,"back on empty Blob");
    return data->back();
}

template <typename T>
const T& Blob<T>::back() const{
    check(0,"back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::front(){
    check(0,"front on empty Blob");
    return data->front();
}

template <typename T>
const T& Blob<T>::front() const{
    check(0,"front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::operator[](size_type i){
    check(i,"subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const{
    check(i,"subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back(){
    check(0,"pop_back on empty Blob");
    data->pop_back();
}


#endif /* BLOB_H */


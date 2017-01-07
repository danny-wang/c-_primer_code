/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextQuery.cpp
 * Author: danny
 * 
 * Created on January 7, 2017, 2:37 PM
 */

#include "Widget.h"

namespace WidgetStuff{

Widget& Widget::operator=(const Widget &rhs){
    if(this==&rhs)
        return *this;
    *pImpl=*(rhs.pImpl);
    return *this;
}
void Widget::swap(Widget &other){
    using std::swap;
    swap(pImpl,other.pImpl);
}
void swap(Widget &a, Widget &b){
    a.swap(b);
    std::cout<<"this is a non_member function"<<std::endl;
}

}


namespace std{
    using WidgetStuff::Widget;
    template<>
    void swap<Widget>(Widget &a, Widget &b){
        a.swap(b);
        std::cout<<"this is the total template specialization swap()"<<std::endl;
    }
}

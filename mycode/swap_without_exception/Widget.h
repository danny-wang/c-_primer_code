/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Widget.h
 * Author: danny
 *
 * Created on January 7, 2017, 2:37 PM
 * Description: an example about how to creat a swap() function, which is more efficient than std::swap.
 * 	the way to deal with normal class and template class is different, please be careful. You have no way to 
 	creat a total template specialization of std::swap() to template class. You will see the difference between 
	below two class.
 		Widget : a normal class;
 		TemplateWiget: a Template class.
 	As for the class WidgetImpl and TemplateWightImpl, they are classes which really contain data.
 */

#ifndef WIDGET_H
#define WIDGET_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
namespace WidgetStuff{

class WidgetImpl{
public:
	WidgetImpl(int one,int two, int three, std::initializer_list<double> il) : a(one),b(two),c(three),v(il){}
	int get_a(){
		return a;
	}
private:
	int a,b,c;
	std::vector<double> v;

};

class Widget {  //use pimpl method
public:
   Widget(WidgetImpl *p):pImpl(p){}
   Widget(const Widget &rhs)=default;
   Widget& operator=(const Widget &rhs);
   void swap(Widget &other);
   int get_a(){
   	return pImpl->get_a();
   }
private:
   WidgetImpl *pImpl; //point to the real data.
};

void swap(Widget &a, Widget &b);   //First select this function.

template<typename T>
class TemplateWightImpl{}; //TODO: waste time
template<typename T>
class TemplateWiget{}; //TODO: can not hold a total template specialization of std::swap()
template<typename T>
void swap(TemplateWiget<T> &a, TemplateWiget<T> &b){  //only can use this function to swap.
	//a.swap(b);
} 
 
}

namespace std{
	using WidgetStuff::Widget;
	template<>
	void swap<Widget>(Widget &a, Widget &b);   //keep the coherence with STL 
}
#endif /* WIDGET_H */


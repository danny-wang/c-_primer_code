/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueryResult.h
 * Author: danny
 *
 * Created on December 12, 2016, 9:31 PM
 */

#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory>
class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    typedef std::vector<std::string>::size_type line_no;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,  std::shared_ptr<std::vector<std::string>> f):
    sought(s), lines(p), file(f){}
    virtual ~QueryResult()=default;
    std::set<line_no>::iterator begin(){
    	return lines->begin();
    } 
    std::set<line_no>::iterator end(){
    	return lines->end();
    }
    std::shared_ptr<std::vector<std::string>> 
    get_file(){
    	return file;
    }
private:
    std::string sought; //query wrod
    std::shared_ptr<std::set<line_no>> lines; //line_no
    std::shared_ptr<std::vector<std::string>> file; //input file+

};

#endif /* QUERYRESULT_H */


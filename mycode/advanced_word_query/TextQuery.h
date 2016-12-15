/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextQuery.h
 * Author: danny
 *
 * Created on December 12, 2016, 9:06 PM
 */

#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <memory>
class QueryResult;
class TextQuery {
public:
    typedef std::vector<std::string>::size_type line_no;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
    virtual ~TextQuery()=default;
private:
    std::shared_ptr<std::vector<std::string>> file; //input file
    //every word and the line which includes this word.
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif /* TEXTQUERY_H */


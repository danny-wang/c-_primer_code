
#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
#include <memory>
#include <algorithm>
class Query_base{
	friend class Query;
protected:
	typedef TextQuery::line_no  line_no;
	virtual ~Query_base()=default;
private:
	//return this query's queryResult
	virtual QueryResult eval(const TextQuery&) const=0;
	//rep represents query string
	virtual std::string rep() const=0;


};


class Query{
	friend Query operator~(const Query &);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	Query(const std::string &);
	QueryResult eval(const TextQuery &t) const;
	std::string rep() const;
private:
	Query(std::shared_ptr<Query_base> query): q(query){ }
	std::shared_ptr<Query_base> q;


};
std::ostream & operator<<(std::ostream &os, const Query &query);


class NotQuery: public Query_base{
	friend Query operator~(const Query&);
	NotQuery(const Query &q) :query(q){ }
	QueryResult eval(const TextQuery& t) const;
	//rep represents query string
	std::string rep() const{
		return "~("+query.rep()+")";
	}
	Query query;

};
inline Query operator~(const Query& q){
	return std::shared_ptr<Query_base>(new NotQuery(q));
}

class BinaryQuery: public Query_base{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s):
		lhs(l),rhs(r),opSym(s){ }
	std::string rep() const {
		return "("+lhs.rep()+" "+opSym+" "+rhs.rep()+")";
	}
	Query lhs,rhs;
	std::string opSym;
};

class AndQuery: public BinaryQuery{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &l,const Query &r):BinaryQuery(l,r,"&"){ }
	QueryResult eval(const TextQuery&) const;
};


class OrQuery: public BinaryQuery{
	friend Query operator| (const Query&, const Query&);
	OrQuery(const Query &l, const Query &r):BinaryQuery(l,r,"|"){ }
	QueryResult eval(const TextQuery&) const;
};

class WordQuery: public Query_base{
public:
	friend class Query;
	WordQuery(const std::string& s) :query_word(s){ }
	QueryResult eval(const TextQuery& t) const{
		return t.query(query_word);
	}
	//rep represents query string
	std::string rep() const {
		return query_word;
	}
	std::string query_word;


};

#endif /* QUERY_BASE_H */
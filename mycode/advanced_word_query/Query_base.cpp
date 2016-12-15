#include "Query_base.h"

QueryResult Query::eval(const TextQuery &t) const{
		return q->eval(t);
	}
std::string Query::rep() const{
		return q->rep();
	}

std::ostream & operator<<(std::ostream &os, const Query &query){
	return os<< query.rep();
}

Query::Query(const std::string &s) : q(new WordQuery(s)){

}

QueryResult NotQuery::eval(const TextQuery &text) const{
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg=result.begin(), end= result.end();
	auto sz= result.get_file()->size();
	for(size_t n=0;n!=sz;++n){
		//check whether current line in result 
		if(beg==end || *beg!=n)
			ret_lines->insert(n); //if not in the result, add this line
		else if(beg != end)
			++beg;   //otherwise keep get next line(if current line in the result)
	}
	return QueryResult(rep(),ret_lines,result.get_file());
}


QueryResult OrQuery::eval(const TextQuery &text) const{
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);
	auto ret_lines= std::make_shared<std::set<line_no>>(left.begin(),left.end());
	ret_lines->insert(right.begin(),right.end());
	return QueryResult(rep(),ret_lines,left.get_file());
}
QueryResult AndQuery::eval(const TextQuery &text) const{
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	set_intersection(left.begin(),left.end(),
					right.begin(), right.end(),
					std::inserter(*ret_lines,ret_lines->begin()));
	return QueryResult(rep(),ret_lines, left.get_file());
}

Query operator&(const Query &lhs, const Query &rhs){
	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

Query operator|(const Query &lhs, const Query &rhs){
	return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}
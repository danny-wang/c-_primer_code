#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iterator>
using namespace std;
//输出vector中长度大于sz的所有string,去除重复
void biggies(vector<string> &words, vector<string>::size_type sz);
int main(){
    vector<int> vec = {1,2,3,4,5,6,1,22};
    cout<<"count= "<< count(vec.begin(), vec.end(), 1)<<endl;
    cout<<"sum= "<< accumulate(vec.cbegin(),vec.cend(),0)<<endl;
    vector<double> vec2 = {1.23,1.56,8,9,2,2.5};
    cout<<"sum= "<< accumulate(vec2.cbegin(),vec2.cend(),0.0)<<endl;
    vector<int> vec3;
    auto it = back_inserter(vec3);
    *it=3;
    fill_n(back_inserter(vec3),10,0);
    cout<<"size of vec3= "<<vec3.size()<<endl;
    sort(vec.begin(),vec.end());
    for (auto ite=vec.begin();ite!=vec.end();ite++)
        cout<<*ite<<" ";
    cout<<endl;
    auto end_unique = unique(vec.begin(),vec.end());
    for (auto ite=vec.begin();ite!=vec.end();ite++)
        cout<<*ite<<" ";
    cout<<endl;
    vec.erase(end_unique,vec.end());
    for (auto ite=vec.begin();ite!=vec.end();ite++)
        cout<<*ite<<" ";
    cout<<endl;
    vector<string> vec5 = {"danny","alex","bob","anc","asfdsadfasdf","sdfsadfsfd"};
    biggies(vec5,5);
    return 0;
}
void elimDups(vector<string> &words){
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique, words.end());
    return;
}
void biggies(vector<string> &words, vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(),words.end(),[](const string &a, const string &b){return a.size()<b.size();});
    auto wc = find_if(words.begin(),words.end(),[sz](const string &s){return s.size()>sz;});
    auto count = words.end() - wc;
    cout<<"there are: "<<count<<" strings' size are bigger than "<<sz<<endl;
    for_each(wc, words.end(),[](const string &s){cout<<s<<" ";});
    cout<<endl;
}



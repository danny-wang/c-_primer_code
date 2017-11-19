//功能:给定一个string,将它转换为另一个string
//程序的输入是两个文件，第一个文件保存的是一些规则，用来转换第二个文件的文本。这条规则由两部分组成：一个可能出现在输入文件中的单词和一个用来替换它的短语。
//表达的含义是，每当第一个单词出现咋输入中时，我们就将它替换为对应的短语。

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//建立转换映射
map<string,string> buildMap(ifstream &map_file){
    map<string,string> output;
    string key;
    string value;
    while(map_file >> key && getline(map_file, value)){
        if(value.size()>1){
            output[key]=value.substr(1); //跳过前导空格
        }else{
            throw runtime_error("no rule for key: "+key);
        }
    }
    return output;
}
//生成转换文本
const string& transform(string &word, map<string, string> &m){
    auto ite = m.find(word);
    if(ite!=m.end()){
        return m[word];
    }else{
        return word;
    }
}
//单词转化程序，第一个参数绑定到单词的转换文件，第二个参数绑定到要转换的文本文件
void wordTransform(ifstream &map_file, ifstream &input){
    auto transform_map = buildMap(map_file);
    string sentence;
    while(getline(input, sentence)){
        bool first = true;
        stringstream ss(sentence);
        string word;
        while(ss >> word){
            if(first){
                first = false;
            }else{
                cout << " ";
            }
            cout << transform(word, transform_map);
        }
        cout << endl;
    }

}
int main(){
    ifstream map_file("map_file.txt");
    ifstream input("input.txt");
    wordTransform(map_file, input);
    return 0;
}

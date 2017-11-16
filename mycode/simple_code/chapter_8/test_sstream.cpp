#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct PersonInfo{
    string name;
    vector<string> phones;
};

int main(){
    string line, word;
    vector<PersonInfo> people;
    string file_name("input.txt");
    ifstream file(file_name);
    while(getline(file,line)){
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while(record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    cout<<people.size()<<endl;
    file.close();
}


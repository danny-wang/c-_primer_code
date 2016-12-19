//
// Created by danny on 12/7/16.
//

#ifndef FOLDERANDMESSAGE_H
#define FOLDERANDMESSAGE_H

#include <string>
#include <set>
#include <cstddef>

class Message;
class Folder {
public:
    void addMsg( Message*);
    void remMsg( Message*);
    Folder()=default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    size_t size() const{
        return messages.size();
    }
    friend std::ostream& operator<<(std::ostream &os, const Folder &f);
private:
    void remove_from_messages();
    void add_to_messages(const Folder&);
    std::set<Message*> messages;
	

};


class Message {
    friend  class Folder;
    //friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string &str=""):contents(str) {}
    Message(const Message&); //cope construct function
    Message& operator=(const Message& );
    ~Message();
    // ADD OR DELETE THIS MESSAGE FROM THE FOLDER
    void save(Folder&);
    void remove(Folder&);
    std::string get_contents() const{
	return contents;
    }
    size_t get_reference_num() const{
	return folders.size();
    }

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};



#endif //FOLDERANDMESSAGE_H

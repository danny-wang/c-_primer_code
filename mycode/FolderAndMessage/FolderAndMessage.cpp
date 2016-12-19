//
// Created by danny on 12/7/16.
//

#include "FolderAndMessage.h"
#include <iostream>
using namespace std;

void Folder::addMsg( Message *m){ 
    messages.insert(m);
}
void Folder::remMsg( Message *m){
    messages.erase(m);
}
Folder::Folder(const Folder &f): messages(f.messages){
    add_to_messages(f);
}
Folder& Folder::operator=(const Folder &rhs){
    remove_from_messages();
    messages=rhs.messages;
    add_to_messages(rhs);
    return *this;
}

Folder::~Folder(){
    remove_from_messages();
}
void Folder::remove_from_messages(){
    for(auto m : this->messages)
        m->remove(*this);
}
void Folder::add_to_messages(const Folder &f){
    for(auto m : f.messages)
        m->save(*this);
}

ostream& operator<<(ostream &os, const Folder &f){
    for(auto m : f.messages)
	os<<m->get_contents()<<endl;
    os<<endl;
    return os;
}


void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for(auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m):contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

void Message::remove_from_Folders() {
    for(auto f : this->folders)
        f->remMsg(this);
}

Message::~Message() {
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents=rhs.contents;
    folders=rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

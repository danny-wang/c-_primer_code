#include "FunctionPointers.h"
#include <iostream>;
using std::cout;
using std::endl;
int loseHealthQuickly(const GameCharacter &gc){
	cout<<"this is loseHealthQuickly() function"<<endl;
	return 1;
}
int loseHealthSlowly(const GameCharacter &gc){
	cout<<"this is loseHealthSlowly() function"<<endl;
	return 2;
}
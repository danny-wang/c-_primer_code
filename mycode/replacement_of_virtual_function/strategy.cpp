#include "strategy.h"
#include <iostream>
using std::cout;
using std::endl;
int HealthCalcFunc::calc(const GameCharacter &gc) const{
	cout<<"this is calc() from base class: HealthCalcFunc"<<endl;
	return 1;
}

HealthCalcFunc defaultHealthCalc;

int SlowHealthLoser::calc(const GameCharacter &gc) const{
	cout<<"this is calc() from derived class: SlowHealthLoser"<<endl;
	return 2;
}

int FastHealthLoser::calc(const GameCharacter &gc) const{
	cout<<"this is calc() from derived class: FastHealthLoser"<<endl;
	return 3;
}
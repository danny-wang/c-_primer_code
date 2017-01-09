/* 
 * File:   strategy.h
 * Author: danny
 * Description: strategy pattern, class GameCharacter can contain a pointer to class HealthCalcFunc, which defines deferent
 Health calculate strategies. 
 * Created on January 9, 2017,11:10 AM
 */

#ifndef STRATEGY_H
#define STRATEGY_H

class GameCharacter;
class HealthCalcFunc{
public:
    virtual int calc(const GameCharacter &gc) const;
};

extern HealthCalcFunc defaultHealthCalc;

class SlowHealthLoser: public HealthCalcFunc{
public:
    virtual int calc(const GameCharacter &gc) const;
};

class FastHealthLoser: public HealthCalcFunc{
public:
    virtual int calc(const GameCharacter &gc) const;
};

class GameCharacter{
public:
    explicit GameCharacter(HealthCalcFunc *phcf=&defaultHealthCalc):pHealthCalc(phcf){}
    int healthValue() const{
        return pHealthCalc->calc(*this);
    }
private:
    HealthCalcFunc *pHealthCalc;
};

class EvilBadGuy: public GameCharacter{
public:
    explicit EvilBadGuy(HealthCalcFunc *phcf=&defaultHealthCalc): GameCharacter(phcf){}
};

class EyeCandyCharacter: public GameCharacter{
public:
    explicit EyeCandyCharacter(HealthCalcFunc *phcf=&defaultHealthCalc): GameCharacter(phcf){}   
};
#endif /* STRATEGY_H */


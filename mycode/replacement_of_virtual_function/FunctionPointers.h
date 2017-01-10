#ifndef FUNCTIONPOINTERS_H
#define FUNCTIONPOINTERS_H
//an interesting replecment to implement public virtual
class GameCharacter;
int defaultHealthCalc(const GameCharacter &gc);

class GameCharacter{
public:
    typedef int(*HealthCalcFunc)(const GameCharacter&);
    explicit GameCharacter(HealthCalcFunc hcf=defaultHealthCalc):
        healthFunc(hcf){ }
    int healthValue() const{
        return healthFunc(*this);
    }
private:
    HealthCalcFunc  healthFunc;
};

class EvilBadGuy: public GameCharacter{
public:
    explicit EvilBadGuy(HealthCalcFunc hcf=defaultHealthCalc):
        GameCharacter(hcf){ }
};

int loseHealthQuickly(const GameCharacter&);
int loseHealthSlowly(const GameCharacter&);
#endif /* FUNCTIONPOINTERS_H */


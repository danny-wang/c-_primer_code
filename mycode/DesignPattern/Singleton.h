#include <pthread.h>
//饿汉模式：即无论是否调用该类的实例，在程序开始时就会产生一个该类的实例，并在以后仅返回此实例。
class singleton
{
protected:
    singleton()
    {}
private:
    static singleton* p;
public:
    static singleton* instance();
};



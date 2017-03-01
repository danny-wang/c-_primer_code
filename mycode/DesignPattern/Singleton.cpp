#include "Singleton.h"
singleton* singleton::p = new singleton();
singleton* singleton::instance()
{
    return p;
}
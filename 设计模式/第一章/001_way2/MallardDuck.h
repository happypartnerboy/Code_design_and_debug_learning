#ifndef _MALLARD_DUCK_H_
#define _MALLARD_DUCK_H_
#include "Duck.h"
class CMallardDuck:public CDuck
{
public:
    CMallardDuck()
    {
        m_pflyBehavior = new CFlyTurnWay; 
    };
public:
    int Display(); 
    int Test(); 
};
#endif
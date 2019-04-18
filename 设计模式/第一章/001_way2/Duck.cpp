#include "Duck.h"
#include <iostream>
using namespace std; 

int CDuck::Swim() 
{
    cout << "I am Swiming" <<endl;
    return 0;
}


int CDuck::Quack() 
{
    cout << "I am Quacking" <<endl;
    return 0;
}

void CDuck::perforFly()
{
    m_pflyBehavior->fly();
}
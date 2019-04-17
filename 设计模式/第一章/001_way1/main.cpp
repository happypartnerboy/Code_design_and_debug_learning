#include <iostream>
#include "MallardDuck.h"
#include "RedheadDuck.h"
#include "RubberDuck.h"
#include "Duck.h"
using namespace std;
int main()
{
    CMallardDuck    MallardDuck;								
	CRedheadDuck    RedheadDuck;					
	CRubberDuck     RubberDuck;				
    CDuck *Duck     = NULL;	
    Duck  = (CMallardDuck *)&MallardDuck;
    Duck->Display();     
    Duck->Swim();
    Duck->Quack();
    Duck->Flay();
    MallardDuck.Test();
    cout << "hello word" << endl;
}
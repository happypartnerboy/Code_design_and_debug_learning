#include <iostream>
#include "MallardDuck.h"
#include "RedheadDuck.h"
#include "RubberDuck.h"
#include "Duck.h"
#include "DecoyDuck.h"
using namespace std;
int main()
{
    CMallardDuck    MallardDuck;								
	CRedheadDuck    RedheadDuck;					
	CRubberDuck     RubberDuck;				
    CDecoyDuck		DecoyDuck;	
    CDuck *Duck     = NULL;	
    Duck  = (CMallardDuck *)&MallardDuck;
    Duck->Display();     
    Duck->Swim();
    Duck->Quack();
    Duck->Flay();
    MallardDuck.Test();
    Duck  = (CDecoyDuck *)&DecoyDuck;
    Duck->Display();    
    cout << "hello word" << endl;
}
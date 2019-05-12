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
    Duck->perforFly();
    MallardDuck.Test();
    Duck  = (CRubberDuck *)&RubberDuck;
    Duck->Display();     
    Duck->Swim();
    Duck->Quack();
    Duck->perforFly();
    cout << "hello word" << endl;   
    Duck->SetPerfomFly(new CFlyTurnWay());
    Duck->perforFly();
}
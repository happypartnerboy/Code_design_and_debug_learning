#include "OberverPaper.h"
#include <iostream>

using namespace std;


void OberverPaper::update(int parameter)
{
    OutPut = parameter + 2;
    display();
}


void OberverPaper::display()
{
    cout << "OberverPaper  %d" << OutPut << endl;
}
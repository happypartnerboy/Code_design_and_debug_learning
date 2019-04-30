#include "OberverPaper.h"
#include <iostream>

using namespace std:


void OberverPaper::update(int parameter)
{
    OutPut = parameter + 2;
}


void OberverPaper::display()
{
    cout << "OberverMonitor" << OutPut << endl;
}
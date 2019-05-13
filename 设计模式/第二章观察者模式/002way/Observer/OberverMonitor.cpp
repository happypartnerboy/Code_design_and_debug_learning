#include "OberverMonitor.h"
#include <iostream>
using namespace std;


void OberverMonitor::update(int parameter)
{
    OutPut = parameter + 2;
    display();
}


void OberverMonitor::display()
{
    cout << "OberverMonitor  %d" << OutPut << endl;
}
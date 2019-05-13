/*!
*\file    OberverMonitor.h
*\brief   显示器输出
*\author  晓光胡
*\date	  2019/04/26
*\version 0.1
*/

#ifndef _OBERVERMONITOR_
#define _OBERVERMONITOR_
#include "OberverBase.h"
class OberverMonitor:public ObserverBase
{  
public:
    void update(int parameter);
    void display();
};
#endif     
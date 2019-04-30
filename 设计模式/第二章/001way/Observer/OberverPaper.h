/*!
*\file    OberverPaper.h
*\brief   显示器输出
*\author  晓光胡
*\date	  2019/04/26
*\version 0.1
*/

#ifndef _OBERVERPAPER_
#define _OBERVERPAPER_
#include "ObserverBase.h"
class OberverPaper:public ObserverBase
{  
public:
    void update(int parameter);
    void display();
};
#endif     
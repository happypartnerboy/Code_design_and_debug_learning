/*!
*\file    OberverBase.h
*\brief   观察者
*\author  晓光胡
*\date	  2019/04/26
*\version 0.1
*/

#ifndef _OBERVERBASH_
#define _OBERVERBASH_

class ObserverBase
{
public:
    int OutPut;        
public:
    virtual void update(int parameter) = 0;
    virtual void display() = 0;
};
#endif     
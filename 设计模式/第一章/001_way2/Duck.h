/*!
*\file    DUCK.h
*\brief   鸭子的超类
*\author  晓光胡
*\date	  2019/04/16
*\version 0.1
*/

#ifndef _DUCK_H_
#define _DUCK_H_
#include <iostream>
using namespace std;
//接口类
class CFlyBehavior   
{
public:
    virtual void fly()
    {

    }
};

class CFlyWithWings:public CFlyBehavior 
{
public:
    void fly()
    {
        cout<<"flying I can fly" << endl;
    }
};

class CFlyNoWay:public CFlyBehavior 
{
public:
    void fly()
    {
        cout<<"No flying I can't fly" << endl;
    }
};

class CFlyTurnWay:public CFlyBehavior 
{
public:
    void fly()
    {
        cout<<"no  CFlyTurnWay I can CFlyTurnWay" << endl;
    }
};


class CDuck
{
public:

	CDuck()
    {
        flyBehavior = new CFlyNoWay();  //默认不会飞
    };
	virtual ~CDuck()
    {

    };
public:
	//游泳 
    int Swim();
	//呱呱的叫 
    int Quack();
    //鸭子的会话函数
	virtual int Display() = 0;

    void perforFly();
public:
    CFlyBehavior *flyBehavior;//接口
};

#endif
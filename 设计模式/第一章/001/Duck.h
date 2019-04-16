/*!
*\file    DUCK.h
*\brief   鸭子的超类
*\author  晓光胡
*\date	  2019/04/16
*\version 0.1
*/

#ifndef _DUCK_H_
#define _DUCK_H_
class CDuck
{
public:

	CDuck(){};
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
};

#endif
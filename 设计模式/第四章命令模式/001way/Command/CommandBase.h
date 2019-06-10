/*!
*\file    COMMANDBASE.h
*\brief   发布者超类
*\author  晓光胡
*\date	  2019/04/26
*\version 0.1
*/
#ifndef _COMMANDBASE_
#define _COMMANDBASE_
#include "../Receiver/Receiver.h" 
class CommandBase
{
	public:
		BarbecueMaster * mp_chif;		//厨师类
	public:
		CommandBase(BarbecueMaster * p)
		{
			mp_chif = p;	//huxiaoguag	
		}
	virtual void executeCmd() = 0;		//声明为纯虚函数
};
#endif     
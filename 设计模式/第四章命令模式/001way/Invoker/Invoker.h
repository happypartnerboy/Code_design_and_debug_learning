/*!
*\file    Invoker.h
*\brief   服务人员
*\author  晓光胡
*\date	  2019/05/25
*\version 0.1
*/

#ifndef _INVOKER_
#define _INVOKER_
#include <iostream>
#include "../Command/CommandBase.h"
#include <vector>
#include <algorithm>
using namespace std;
class Waiter
{
private:
	vector<CommandBase *> m_Command_array; //命令数组

public:
	//清空CommandBase
	~Waiter()		//析构函数
	{
		vector< CommandBase *>::iterator it;
		for (it = m_Command_array.begin(); it != m_Command_array.end(); it++)
		{
			delete(*it);
		}
		m_Command_array.clear();
	}

	//相关的命令
	void add(CommandBase * p);			//添加命令
	void remove(CommandBase * p);		//移除命令
	void submitCmd();					//执行命令
};
#endif     
#include <iostream>
#include "./Invoker/Invoker.h"
#include "./Command/CommandBase.h"
#include "./Command/CommandMutton.h"
#include "./Command/CommandChiken.h"
using namespace std;

int main()
{
	Waiter * pWaiter = new Waiter();	//new 需要封装
	BarbecueMaster * pMaster = new BarbecueMaster; //厨师
	pWaiter->add(new CommandButton(pMaster));	//添加烤牛肉的命令
	pWaiter->add(new CommandChiken(pMaster));	//添加烤牛肉的命令
	pWaiter->submitCmd();						//执行命令

	//释放对象
	delete pWaiter;
	delete pMaster;
	return 0;
}
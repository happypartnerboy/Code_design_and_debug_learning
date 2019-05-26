#include "Invoker.h"
using namespace std;
//�������
void Waiter::add(CommandBase * p)			//�������
{
	m_Command_array.push_back(p);
}

//�Ƴ�����
void Waiter::remove(CommandBase * p)		//�Ƴ�����
{
	vector< CommandBase *>::iterator it;
	it = find(m_Command_array.begin(), m_Command_array.end(), p);
	if (it != m_Command_array.end())
		m_Command_array.erase(it);
}

//ִ������
void Waiter::submitCmd()					//ִ������
{
	vector< CommandBase *>::iterator it;
	for (it = m_Command_array.begin(); it != m_Command_array.end(); it++)
	{
		(*it)->executeCmd();
	}
}
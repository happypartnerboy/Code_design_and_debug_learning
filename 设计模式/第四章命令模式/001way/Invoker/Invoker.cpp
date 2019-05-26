#include "Invoker.h"
using namespace std;
//Ìí¼ÓÃüÁî
void Waiter::add(CommandBase * p)			//Ìí¼ÓÃüÁî
{
	m_Command_array.push_back(p);
}

//ÒÆ³ıÃüÁî
void Waiter::remove(CommandBase * p)		//ÒÆ³ıÃüÁî
{
	vector< CommandBase *>::iterator it;
	it = find(m_Command_array.begin(), m_Command_array.end(), p);
	if (it != m_Command_array.end())
		m_Command_array.erase(it);
}

//Ö´ĞĞÃüÁî
void Waiter::submitCmd()					//Ö´ĞĞÃüÁî
{
	vector< CommandBase *>::iterator it;
	for (it = m_Command_array.begin(); it != m_Command_array.end(); it++)
	{
		(*it)->executeCmd();
	}
}
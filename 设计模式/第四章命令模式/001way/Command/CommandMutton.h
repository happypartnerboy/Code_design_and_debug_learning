#ifndef _COMMANDMUTTON_
#define _COMMANDMUTTON_
#include "CommandBase.h"
#include "../Receiver/Receiver.h"
class CommandButton:public CommandBase
{
	public:
		CommandButton(BarbecueMaster * p): CommandBase (p)
		{
			
		}
	void executeCmd();

};
#endif 
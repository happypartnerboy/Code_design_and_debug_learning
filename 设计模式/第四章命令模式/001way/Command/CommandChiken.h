#ifndef _COMMANDCHIKEN_
#define _COMMANDCHIKEN_
#include "CommandBase.h"
#include "../Receiver/Receiver.h"
class CommandChiken:public CommandBase  
{
	public:
		CommandChiken(BarbecueMaster * p): CommandBase (p)
		{
			
		}
		void executeCmd();
};
#endif 
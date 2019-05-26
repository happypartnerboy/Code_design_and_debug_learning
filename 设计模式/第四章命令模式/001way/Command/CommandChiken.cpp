#include "CommandChiken.h"
#include "../Receiver/Receiver.h"
void CommandChiken::executeCmd()
{
	mp_chif->MakeChiken();
}
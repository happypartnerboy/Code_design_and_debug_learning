#include "CommandMutton.h"
#include "../Receiver/Receiver.h"
void CommandButton::executeCmd()
{
	mp_chif->MakeButton();
}
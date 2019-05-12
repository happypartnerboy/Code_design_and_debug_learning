#include "ConcreteSubject.h"
#include <iostream>
#include "../Observer/OberverBase.h"
using namespace std;

void ConcreteSubject::removejoiner(ObserverBase *joiner) 
{
   m_PsubscriptionList.push_back(joiner);
}



void ConcreteSubject::removeObserver(ObserverBase *remove) 
{
  
    list<ObserverBase *>::iterator it;
    for(it = m_PsubscriptionList.begin(); it != m_PsubscriptionList.end(); ++it)
    {
        if(remove ==*it)
        {
            m_PsubscriptionList.remove(remove);
        }
    }
   
}
    
void ConcreteSubject::notifyObserver()   
{
 
     list<ObserverBase *>::iterator it;
     for(it = m_PsubscriptionList.begin(); it != m_PsubscriptionList.end(); ++it)
     {
        (*it)->update(resource);      //通知所有的订阅者
     }

    //遍历链表的问题
    
}



#ifndef _CONCRETESUBJECT_
#define _CONCRETESUBJECT_
#include "SubjectBase.h"
#include "../Observer/OberverBase.h"
#include <list>
using namespace std;
class ConcreteSubject:SbjectBash
{
    public:
        int resource; 
        list<ObserverBase *>	m_PsubscriptionList;	
        ConcreteSubject(){
            resource = 0;
        };
        virtual ~ConcreteSubject()
        {

        };
    public:
        void removejoiner(ObserverBase *joiner);  	
        void removeObserver(ObserverBase * remove);
        void notifyObserver() ;
};
#endif 
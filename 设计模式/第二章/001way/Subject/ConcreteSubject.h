#ifndef _CONCRETESUBJECT_
#define _CONCRETESUBJECT_
#include "Observer/SubjectBase.h"
#include "OberverPaper.h"
#include <list>
class ConcreteSubject:SbjectBash
{
public:
    int resource; 
    list<ObserverBase>	m_PsubscriptionList;	
	ConcreteSubject(){
        resource = 0;
    };
	virtual ~ConcreteSubject()
    {

    };
public:
	void registerObserver(ObserverBase register) ;
    void removeObserver(ObserverBase remove)   ;
    void notifyObserver() ;
};
#endif 
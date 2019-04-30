/*!
*\file    DUCK.h
*\brief   发布者超类
*\author  晓光胡
*\date	  2019/04/26
*\version 0.1
*/

#ifndef _SUBJECTBASH_
#define _SUBJECTBASH_
#include "Observer/SubjectBase.h"
class SbjectBash
{
public:
	SbjectBash(){};
	virtual ~SbjectBash()
    {

    };
public:
	virtual void registerObserver(ObserverBase register) = 0;
    virtual void removeObserver(ObserverBase remove) = 0;      
    virtual void notifyObserver() = 0;
};
#endif     
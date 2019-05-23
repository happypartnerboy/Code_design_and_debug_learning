/*!
*\file    DUCK.h
*\brief   发布者超类
*\author  晓光胡
*\date	  2019/04/26
*\version 0.1
*/

#ifndef _SUBJECTBASH_
#define _SUBJECTBASH_
#include "../Observer/OberverBase.h"
class SbjectBash
{
    public:
        SbjectBash(){};
        virtual ~SbjectBash()
        {

        };
    public:
        virtual void removeObserver(ObserverBase *remove) = 0; 
        virtual void removejoiner(ObserverBase *joiner) = 0;           
        virtual void notifyObserver() = 0;
};

class SbjectBash
{
    public:
        SbjectBash(){};
        virtual ~SbjectBash()
        {

        };
    public:
        virtual void removeObserver(ObserverBase *remove) = 0; 
        virtual void removejoiner(ObserverBase *joiner) = 0;           
        virtual void notifyObserver() = 0;
};


#endif     
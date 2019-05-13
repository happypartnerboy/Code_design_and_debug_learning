#include <iostream>
#include <string>
#include "ConcreteSubject.h"
#include "OberverPaper.h"
#include "OberverMonitor.h"
#include "OberverBase.h"
using namespace std;
int main()
{
    //声明观察者和订阅者
    ConcreteSubject ObserverTes;
    OberverPaper    OpaperTest;
    OberverMonitor  Monitor;

    //加入数据
    ObserverTes.removejoiner((ObserverBase *)&OpaperTest);
    ObserverTes.removejoiner((ObserverBase *)&Monitor);
    
    //通知数据
    ObserverTes.notifyObserver();

    cout<<"hello world"<<endl;

    //退订数据
    ObserverTes.removeObserver((ObserverBase *)&OpaperTest);
     //通知数据
    ObserverTes.notifyObserver();
    return 0;
}
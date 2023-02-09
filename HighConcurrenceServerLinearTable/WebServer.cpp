#include "WebServer.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

static void CheckTimeOutLinearTable(LinearTable& InputlinearTable, time_t InputNow)
{
    for (int i = 0; i < InputlinearTable.Length; i++)
    {
        if (InputNow >= InputlinearTable.ElementEntry[i].TimeOut)
        {
            RemoveElementInTable(InputlinearTable, i + 1);
        }
    }
}

/*int main()
{
    //时间戳的概念
    /*time_t Now;
    time(&Now);
    cout << "当前时间为:" << Now << endl;
    Sleep(2000);
    time(&Now);
    cout << "当前时间为:" << Now << endl;#1#

    LinearTable _LinearTable;
    InitTable(_LinearTable); //初始化线性表
    _TimeOut TimeOut;
    time_t Now;
    time(&Now);
    time_t LastTime;
    LastTime = Now;
    time_t End;
    End = Now + 20;

    for (int i = 0; i < 5; i++)
    {
        TimeOut.FD = i;
        TimeOut.TimeOut = Now + 5 + 2 * i;
        if (!AddElementInTable(_LinearTable, TimeOut))
        {
            cout << "添加元素失败" << endl;
        }
    }

    do
    {
        if (LastTime + 0.999 < Now)
        {
            cout << "正在检查是否超时" << endl;
            CheckTimeOutLinearTable(_LinearTable, Now);
            LastTime = Now;
            PrintTable(_LinearTable);
        }
        time(&Now);
    }
    while (Now < End);

    //DestroyTable(_LinearTable); //销毁线性表
}*/

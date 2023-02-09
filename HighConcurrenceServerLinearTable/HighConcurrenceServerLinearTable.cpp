#include <iostream>
#include "WebServer.h"
using namespace std;
/*
    顺序表
*/

bool TableIsFull(LinearTable& InputLinearTable)
{
    if (InputLinearTable.Length == MAX_SIZE)
    {
        return true;
    }
    return false;
}

bool TableIsEmpty(LinearTable& InputLinearTable)
{
    if (InputLinearTable.Length == 0)
    {
        return true;
    }
    return false;
}

bool InitTable(LinearTable& InputLinearTable)
{
    if (TableIsFull(InputLinearTable))
    {
        cout << "线性表已满" << endl;
    }
    InputLinearTable.ElementEntry = new _TimeOut[MAX_SIZE];
    if (!InputLinearTable.ElementEntry)
    {
        return false;
    }
    InputLinearTable.Length = 0;
    InputLinearTable.Size = MAX_SIZE;
    return true;
}

bool AddElementInTable(LinearTable& InputLinearTable, _TimeOut Element)
{
    if (TableIsFull(InputLinearTable))
    {
        cout << "线性表已满" << endl;
        return false;
    }
    InputLinearTable.ElementEntry[InputLinearTable.Length] = Element;
    InputLinearTable.Length++;
    return true;
}

bool InsertElementInTable(LinearTable& InputLinearTable, int Position, _TimeOut Element)
{
    if (TableIsFull(InputLinearTable))
    {
        return false;
    }
    if (Position < 0 || Position > InputLinearTable.Length)
    {
        return false;
    }
    if (Position == InputLinearTable.Length)
    {
        InputLinearTable.ElementEntry[Position] = Element;
        InputLinearTable.Length++;
        return true;
    }
    for (int i = InputLinearTable.Length - 1; i >= Position; i--)
    {
        InputLinearTable.ElementEntry[i + 1] =
            InputLinearTable.ElementEntry[i];
    }
    InputLinearTable.ElementEntry[Position] = Element;
    InputLinearTable.Length++;
    return true;
}

bool RemoveElementInTable(LinearTable& InputLinearTable, int Position)
{
    if (TableIsEmpty(InputLinearTable))
    {
        return false;
    }
    if (Position < 0 || Position > InputLinearTable.Length)
    {
        return false;
    }
    for (int i = Position; i < InputLinearTable.Length; i++)
    {
        InputLinearTable.ElementEntry[i - 1] = InputLinearTable.ElementEntry[i];
    }
    InputLinearTable.Length--;
    return true;
}

void DestroyTable(LinearTable& InputLinearTable)
{
    if (InputLinearTable.ElementEntry)
    {
        delete []InputLinearTable.ElementEntry;
        InputLinearTable.Length = 0;
        InputLinearTable.Size = 0;
        cout << "线性表已销毁" << endl;
    }
}

void PrintTable(LinearTable& InputLinearTable)
{
    cout << "当前顺序表中元素个数为:" << InputLinearTable.Length << endl;
    cout << endl;
}

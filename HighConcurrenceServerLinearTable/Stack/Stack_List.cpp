#include <iostream>
using namespace std;

#define Max_Size 16

typedef int DataType;

typedef struct _StackNode
{
    DataType Data;
    struct _StackNode* Next;
} StackNode;

typedef struct _StackList
{
    StackNode* Top;
    StackNode* Base;
    int Size;
} StackList;

bool IsEmpty(const StackList& InputStackList)
{
    return (InputStackList.Size == 0);
};

bool IsFull(const StackList& InputStackList)
{
    return (InputStackList.Size == Max_Size);
}

bool InitStackList(StackList& InputStackList)
{
    InputStackList.Top = InputStackList.Base = nullptr;
    InputStackList.Size = 0;
    return true;
}

bool PushElementToStackList(StackList& InputStackList, StackNode* InputStackNode)
{
    if (IsFull(InputStackList))
    {
        return false;
    }
    if (InputStackNode == nullptr)
    {
        return false;
    }

    if (IsEmpty(InputStackList))
    {
        InputStackNode->Next = nullptr;
        InputStackList.Base = InputStackList.Top = InputStackNode;
        InputStackList.Size++;
        return true;
    }
    else
    {
        InputStackNode->Next = InputStackList.Top;
        InputStackList.Top = InputStackNode;
        InputStackList.Size++;
        return true;
    }
}

bool PopElementToStackList(StackList& InputStackList, StackNode& OutputStackNode)
{
    if (IsEmpty(InputStackList))
    {
        return false;
    }
    const StackNode* TempNode = InputStackList.Top;
    OutputStackNode = *InputStackList.Top;
    InputStackList.Top = InputStackList.Top->Next;
    InputStackList.Size--;
    delete TempNode;
    return true;
}

void DestroyStackList(StackList& InputStackList)
{
    if (!InputStackList.Base)
    {
        return;
    }
    const StackNode* TempNode = InputStackList.Base;
    while (TempNode != nullptr)
    {
        const StackNode* DeleteNode = TempNode;
        TempNode = TempNode->Next;
        delete DeleteNode;
    }
    InputStackList.Base = InputStackList.Top = nullptr;
    InputStackList.Size = 0;
}

/*int main()
{
    //初始化栈
    StackList PrepareStackList;
    InitStackList(PrepareStackList);

    int InputCount;
    cout << "请输入要入栈的个数:";
    cin >> InputCount;
    cout << "请输入要入栈的元素:" << endl;
    StackNode* InputData;
    for (int i = 0; i < InputCount; i++)
    {
        InputData = new StackNode;
        if (InputData == nullptr)
        {
            break;
        }
        cin >> InputData->Data;
        PushElementToStackList(PrepareStackList, InputData);
    }

    //从栈中弹出元素
    cout << "弹出的元素为:" << endl;
    StackNode OutputData;
    for (int i = 0; i < 5; i++)
    {
        if (!PopElementToStackList(PrepareStackList, OutputData))
        {
            cout << "栈中已没有元素" << endl;
        }
        else
        {
            cout << OutputData.Data << ' ';
        }
    }
    cout << endl;
    return 1;
}*/

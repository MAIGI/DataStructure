#include <iostream>
using namespace std;

#define Max_Size 16

typedef int DataType;

typedef struct _StackArray
{
    DataType* Top;
    DataType* Base;
    int Size;
} StackArray;

bool IsEmpty(const StackArray& InputStackArray)
{
    return (InputStackArray.Size == 0);
};

bool IsFull(const StackArray& InputStackArray)
{
    return (InputStackArray.Size == Max_Size);
}

bool InitStackArray(StackArray& InputStackArray)
{
    InputStackArray.Base = new DataType[Max_Size];
    if (InputStackArray.Base == nullptr)
    {
        return false;
    }
    InputStackArray.Top = InputStackArray.Base;
    InputStackArray.Size = 0;
    return true;
}

bool PushElementToStackArray(StackArray& InputStackArray, DataType InputDataType)
{
    if (IsFull(InputStackArray))
    {
        return false;
    }
    *InputStackArray.Top = InputDataType;
    InputStackArray.Top++;
    InputStackArray.Size++;
    return true;
}

bool PopElementToStackArray(StackArray& InputStackArray, DataType& OutputDataType)
{
    if (IsEmpty(InputStackArray))
    {
        return false;
    }
    OutputDataType = *--InputStackArray.Top;
    InputStackArray.Size--;
    return true;
}

/*int main()
{
    //初始化栈
    StackArray PrepareStackArray;
    InitStackArray(PrepareStackArray);

    int InputCount;
    cout << "请输入要入栈的个数:";
    cin >> InputCount;
    cout << "请输入要入栈的元素:" << endl;
    DataType InputData;
    for (int i = 0; i < InputCount; i++)
    {
        cin >> InputData;
        PushElementToStackArray(PrepareStackArray, InputData);
    }

    //从栈中弹出元素
    cout << "弹出的元素为:" << endl;
    DataType OutputData;
    for (int i = 0; i < 5; i++)
    {
        if (!PopElementToStackArray(PrepareStackArray, OutputData))
        {
            cout << "栈中已没有元素" << endl;
        }
        else
        {
            cout << OutputData << ' ';
        }
    }
    cout << endl;
    return 1;
}*/

#include <iostream>
using namespace std;

typedef struct _CommonDoubleList
{
    struct _CommonDoubleList* Prev;
    struct _CommonDoubleList* Next;
} CommonDoubleList, CommonDoubleListNode;

typedef struct _Data
{
    int DataSource;
    CommonDoubleList ListSource;
} Data;

void InitializeCommonDoubleList(CommonDoubleList& InputCommonDoubleList)
{
    InputCommonDoubleList.Prev = nullptr;
    InputCommonDoubleList.Next = nullptr;
}

bool InsertElementInCommonDoubleList_Front(CommonDoubleList& InputCommonDoubleList,
                                           CommonDoubleListNode*& InputCommonDoubleListNode)
{
    if (InputCommonDoubleListNode == nullptr)
    {
        return false;
    }
    if (InputCommonDoubleList.Next == nullptr)
    {
        InputCommonDoubleList.Next = InputCommonDoubleListNode;
        InputCommonDoubleListNode->Next = nullptr;
        InputCommonDoubleListNode->Prev = &InputCommonDoubleList;
        return true;
    }
    else
    {
        InputCommonDoubleList.Next->Prev = InputCommonDoubleListNode;
        InputCommonDoubleListNode->Prev = &InputCommonDoubleList;
        InputCommonDoubleListNode->Next = InputCommonDoubleList.Next;
        InputCommonDoubleList.Next = InputCommonDoubleListNode;
        return true;
    }
}

void DeleteElementInDoubleListByPosition(CommonDoubleList& InputCommonDoubleList,
                                         CommonDoubleListNode*& InputCommonDoubleListNode, int Position)
{
    if (InputCommonDoubleList.Next = nullptr)
    {
        delete &InputCommonDoubleList;
    }
    if (InputCommonDoubleListNode == nullptr || Position <= 0)
    {
        return;
    }
    int TemPosition = 0;
    CommonDoubleListNode* TemCommonDoubleListNode = &InputCommonDoubleList;
    while (TemPosition < Position)
    {
        TemCommonDoubleListNode = TemCommonDoubleListNode->Next;
        TemPosition++;
    }
    TemCommonDoubleListNode->Prev->Next = TemCommonDoubleListNode->Next;
    TemCommonDoubleListNode->Next->Prev = TemCommonDoubleListNode->Prev;
    delete TemCommonDoubleListNode;
}

void PrintCommonDoubleList(Data*& InputData)
{
    if (InputData->ListSource.Next == nullptr)
    {
        cout << "共享链表为空" << endl;
    }
    CommonDoubleListNode* TemCommonDoubleListNode = &InputData->ListSource;
    cout << "数据为:" << endl;
    while (TemCommonDoubleListNode->Next != nullptr)
    {
        TemCommonDoubleListNode = TemCommonDoubleListNode->Next;
        const int Interval = offsetof(Data, ListSource);
        const Data* TemData = (Data*)((size_t)TemCommonDoubleListNode - Interval);
        if (TemData)
        {
            cout << TemData->DataSource << ' ';
        }
    }
    cout << endl;
}

/*int main()
{
    //测试内存偏移
    /*Data* P_Data = new Data;
    CommonDoubleList* P_CommonDoubleList = &(P_Data->ListSource);
    cout << "请输入参数值:";
    cin >> P_Data->DataSource;
    const int Interval = offsetof(Data, ListSource);
    const Data* TemData = (Data*)((size_t)P_CommonDoubleList - Interval);
    cout << "输入的数据为:" << TemData->DataSource << endl;#1#

    //测试共享链表
    Data* P_Data = new Data;
    if (P_Data == nullptr)
    {
        return 0;
    }
    InitializeCommonDoubleList(P_Data->ListSource);
    int i = 0;
    cout << "请输入要插入的数据个数:";
    cin >> i;
    int j = 0;
    cout << "请输入要插入的元素:" << endl;
    while (j < i)
    {
        Data* TemData = new Data;
        if (TemData == nullptr)
        {
            break;
        }
        CommonDoubleListNode* P_CommonDoubleListNode = &TemData->ListSource;
        if (P_CommonDoubleListNode == nullptr)
        {
            break;
        }
        cin >> TemData->DataSource;

        if (InsertElementInCommonDoubleList_Front(P_Data->ListSource, P_CommonDoubleListNode) == false)
        {
            cout << "插入失败" << endl;
        }
        else
        {
            j++;
        }
    }
    cout << endl;
    PrintCommonDoubleList(P_Data);
    return 0;
}*/

#include <iostream>
using namespace std;

typedef struct _DoubleLinkList
{
    int Data;
    struct _DoubleLinkList* Prev;
    struct _DoubleLinkList* Next;
} DoubleLinkList, DoubleLinkNode;

bool InitDoubleLinkList(DoubleLinkList*& InputDoubleLinklist)
{
    InputDoubleLinklist = new DoubleLinkList;
    if (!InputDoubleLinklist)
    {
        return false;
    }

    InputDoubleLinklist->Data = -1;
    InputDoubleLinklist->Prev = nullptr;
    InputDoubleLinklist->Next = nullptr;
    return true;
}

bool InsertElementFromFrontInDoubleLinkList(DoubleLinkList*& InputDoubleLinkList, DoubleLinkNode*& InputDoubleLinkNode,
                                            int InputData)
{
    if (!InputDoubleLinkList)
    {
        return false;
    }
    InputDoubleLinkNode = new DoubleLinkNode;
    if (!InputDoubleLinkNode)
    {
        return false;
    }
    //双向链表只有一个头节点的情况
    if (InputDoubleLinkList->Next == nullptr)
    {
        InputDoubleLinkNode->Data = InputData;
        InputDoubleLinkNode->Prev = InputDoubleLinkList;
        InputDoubleLinkNode->Next = InputDoubleLinkList->Next;
        InputDoubleLinkList->Next = InputDoubleLinkNode;
    }
    //双向链表拥有多个节点的情况
    else
    {
        InputDoubleLinkNode->Data = InputData;
        InputDoubleLinkNode->Prev = InputDoubleLinkList;
        InputDoubleLinkNode->Next = InputDoubleLinkList->Next;
        InputDoubleLinkList->Next->Prev = InputDoubleLinkNode;
        InputDoubleLinkList->Next = InputDoubleLinkNode;
    }
    return true;
}

bool InsertElementFromEndInDoubleLinkList(DoubleLinkList*& InputDoubleLinkList, DoubleLinkNode*& InputDoubleLinkNode,
                                          int InputData)
{
    if (!InputDoubleLinkList)
    {
        return false;
    }
    InputDoubleLinkNode = new DoubleLinkNode;
    if (!InputDoubleLinkNode)
    {
        return false;
    }
    DoubleLinkNode* LastDoubleLinkNode = InputDoubleLinkList;
    while (LastDoubleLinkNode->Next != nullptr)
    {
        LastDoubleLinkNode = LastDoubleLinkNode->Next;
    }
    InputDoubleLinkNode->Data = InputData;
    InputDoubleLinkNode->Prev = LastDoubleLinkNode;
    InputDoubleLinkNode->Next = LastDoubleLinkNode->Next;
    LastDoubleLinkNode->Next = InputDoubleLinkNode;
    return true;
}

bool InsertElementAnywhereInDoubleLinkList(DoubleLinkList*& InputDoubleLinkList, DoubleLinkNode*& InputDoubleLinkNode,
                                           int InputPosition, int InputData)
{
    if (!InputDoubleLinkList)
    {
        return false;
    }
    int TemPosition = 0;
    InputDoubleLinkNode = new DoubleLinkNode;
    if (!InputDoubleLinkNode || InputPosition < TemPosition)
    {
        return false;
    }
    InputDoubleLinkNode->Data = InputData;
    DoubleLinkNode* TemDoubleLinkNode = InputDoubleLinkList;
    while (TemDoubleLinkNode && TemPosition < InputPosition)
    {
        TemDoubleLinkNode = TemDoubleLinkNode->Next;
        TemPosition ++;
    }
    if (TemDoubleLinkNode == nullptr)
    {
        return false;
    }
    if (InputPosition == 0)
    {
        InsertElementFromFrontInDoubleLinkList(InputDoubleLinkList, InputDoubleLinkNode, InputData);
    }
    else
    {
        InputDoubleLinkNode->Prev = TemDoubleLinkNode->Prev;
        TemDoubleLinkNode->Prev = InputDoubleLinkNode;
        InputDoubleLinkNode->Prev->Next = InputDoubleLinkNode;
        InputDoubleLinkNode->Next = TemDoubleLinkNode;
    }
    return true;
}

void GetElementInDoubleLinkListByPosition(DoubleLinkList*& InputDoubleLinkList, int InputPosition, int& OutputData)
{
    if (!InputDoubleLinkList)
    {
        OutputData = -1;
        return;
    }
    int TemPosition = 0;
    if (InputPosition < TemPosition)
    {
        OutputData = -1;
        return;
    }
    DoubleLinkList* ProperLinkNode = InputDoubleLinkList;
    while (ProperLinkNode && TemPosition < InputPosition)
    {
        ProperLinkNode = ProperLinkNode->Next;
        TemPosition++;
    }
    if (!ProperLinkNode)
    {
        OutputData = -1;
        return;
    }
    else
    {
        OutputData = ProperLinkNode->Data;
    }
}

void DeleteProperElementInDoubleLinkListByPosition(DoubleLinkList*& InputDoubleLinkList, int InputPosition,
                                                   int& DeleteElementData)
{
    if (!InputDoubleLinkList)
    {
        DeleteElementData = -1;
        return;
    }
    int TemPosition = 0;
    if (InputPosition < TemPosition)
    {
        DeleteElementData = -1;
        return;
    }
    DoubleLinkList* ProperLinkNode = InputDoubleLinkList;
    while (ProperLinkNode && TemPosition < InputPosition)
    {
        ProperLinkNode = ProperLinkNode->Next;
        TemPosition++;
    }
    if (!ProperLinkNode)
    {
        DeleteElementData = -1;
        return;
    }
    else
    {
        ProperLinkNode->Prev->Next = ProperLinkNode->Next;
        ProperLinkNode->Next->Prev = ProperLinkNode->Prev;
        DeleteElementData = ProperLinkNode->Data;
        delete ProperLinkNode;
    }
}

void PrintDoubleLinkList(DoubleLinkList*& InputDoubleLinkList)
{
    if (!InputDoubleLinkList || InputDoubleLinkList->Next == nullptr)
    {
        return;
    }
    DoubleLinkNode* LastDoubleLinkNode = InputDoubleLinkList;
    cout << "正向打印结果:" << endl;
    while (LastDoubleLinkNode->Next != nullptr)
    {
        LastDoubleLinkNode = LastDoubleLinkNode->Next;
        cout << LastDoubleLinkNode->Data << ' ';
    }
    cout << endl;
    cout << "逆向打印结果:" << endl;
    while (LastDoubleLinkNode->Prev != nullptr)
    {
        cout << LastDoubleLinkNode->Data << ' ';
        LastDoubleLinkNode = LastDoubleLinkNode->Prev;
    }
    cout << endl;
}


/*int main()
{
    //初始化双向链表
    DoubleLinkList* DefaultDoubleLinkList = nullptr;
    DoubleLinkNode* DefaultLinkNode = nullptr;
    InitDoubleLinkList(DefaultDoubleLinkList);
    //插入元素
    cout << "请输入要插入的元素:";
    for (int i = 0; i < 5; i++)
    {
        int InputData = 0;
        cin >> InputData;
        //前插
        //InsertElementFromFrontInDoubleLinkList(DefaultDoubleLinkList, DefaultLinkNode, InputData);
        //尾插
        InsertElementFromEndInDoubleLinkList(DefaultDoubleLinkList, DefaultLinkNode, InputData);
    }
    PrintDoubleLinkList(DefaultDoubleLinkList);
    //在任意位置插入元素
    /*int InputData;
    int InputPosition;
    for (int i = 0; i < 2; i++)
    {
        cout << "请输入插入位置:";
        cin >> InputPosition;
        cout << "请输入插入位置的数值:";
        cin >> InputData;
        cout << endl;
        if (!InsertElementAnywhereInDoubleLinkList(DefaultDoubleLinkList, DefaultLinkNode, InputPosition, InputData))
        {
            cout << "插入失败" << endl;
        }
        PrintDoubleLinkList(DefaultDoubleLinkList);
    }#1#
    //根据位置获取相应元素
    /*int TemPosition = 0;
    int OutputData;
    cout << "请输入想要查找的位置:";
    cin >> TemPosition;
    cout << endl;
    GetElementInDoubleLinkListByPosition(DefaultDoubleLinkList, TemPosition, OutputData);
    cout << "获取的元素为:" << OutputData << endl;#1#
    //根据位置删除相应元素
    int DeleteData = 0;
    int DeletePosition = 0;
    cout << "请输入要删除的位置:";
    cin >> DeletePosition;
    DeleteProperElementInDoubleLinkListByPosition(DefaultDoubleLinkList, DeletePosition, DeleteData);
    cout << "删除的元素值为:" << DeleteData << endl;
    PrintDoubleLinkList(DefaultDoubleLinkList);

    return 0;
}*/

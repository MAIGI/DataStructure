#include <iostream>
using namespace std;

typedef struct LoopList
{
    int Data;
    struct LoopList* Next;
} LinkList, LinkNode;


bool InitLoopList(LinkList*& InputLoopList)
{
    InputLoopList = new LinkNode;
    if (!InputLoopList)
    {
        return false;
    }
    InputLoopList->Data = -1;
    InputLoopList->Next = InputLoopList;
    return true;
}

bool InsetElementToLoopList(LinkList*& InputLoopList, LinkNode*& InputLinkNode, int InputData)
{
    if (!InputLoopList)
    {
        cout << "链表无效" << endl;
        return false;
    }
    InputLinkNode = new LinkNode;
    if (!InputLinkNode)
    {
        cout << "节点无效" << endl;
        return false;
    }
    InputLinkNode->Data = InputData;
    if (InputLoopList->Next == InputLoopList)
    {
        InputLoopList->Next = InputLinkNode;
        InputLinkNode->Next = InputLoopList;
        return true;
    }
    else
    {
        LinkNode* TemLinkNode = InputLoopList;
        while (TemLinkNode->Next != InputLoopList)
        {
            TemLinkNode = TemLinkNode->Next;
        }
        TemLinkNode->Next = InputLinkNode;
        InputLinkNode->Next = InputLoopList;
        return true;
    }
}

void PrintLoopList(LinkList*& InputLinkList)
{
    if (!InputLinkList)
    {
        return;
    }
    if (InputLinkList->Next == InputLinkList)
    {
        cout << "循环链表为空" << endl;
    }
    LinkNode* TemLinkNode = InputLinkList->Next;
    while (TemLinkNode != InputLinkList)
    {
        cout << "当前数据为:" << TemLinkNode->Data << " ";
        TemLinkNode = TemLinkNode->Next;
    }
    cout << endl;
}

bool Joseph(LinkList*& InputLinkList, int Interval)
{
    if (!InputLinkList)
    {
        return false;
    }
    int ConstInterval = Interval;
    int Count = 1;
    int DeleteData = 0;
    LinkNode* TemNode = InputLinkList;
    if (TemNode->Next == InputLinkList)
    {
        cout << "链表为空" << endl;
        return false;
    }
    const LinkNode* DeleteNode = nullptr;
    do
    {
        while (Count < Interval)
        {
            TemNode = TemNode->Next;
            Count++;
        }
        if (TemNode->Next == InputLinkList)
        {
            TemNode = TemNode->Next;
        }
        DeleteNode = TemNode->Next;
        TemNode->Next = DeleteNode->Next;
        DeleteData = DeleteNode->Data;
        delete DeleteNode;
        cout << "删除的节点为:" << DeleteData << endl;
        Count++;
        cout << "Count值为:" << Count << endl;
        PrintLoopList(InputLinkList);
        Interval = Interval + ConstInterval;
    }
    while (InputLinkList->Next != InputLinkList);

    cout << "最后删除的节点数据是:" << DeleteData << endl;
    return true;
}

/*int main()
{
    LinkList* NewLinkList = nullptr;
    if (InitLoopList(NewLinkList))
    {
        cout << "初始化链表成功" << endl;
    }
    else
    {
        cout << "初始化链表失败" << endl;
    }
    for (int i = 1; i <= 5; i++)
    {
        LinkNode* NewLinkNode = nullptr;
        if (InsetElementToLoopList(NewLinkList, NewLinkNode, i))
        {
            cout << "元素插入成功" << endl;
        }
        else
        {
            cout << "元素插入失败" << endl;
        }
    }
    PrintLoopList(NewLinkList);

    //约瑟夫问题
    if (!Joseph(NewLinkList, 3))
    {
        cout << "问题解决失败" << endl;
    }
    else
    {
        cout << "问题解决" << endl;
    }

    return 0;
}*/

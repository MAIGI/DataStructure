#include <iostream>

using namespace std;

typedef struct _ListNode
{
    int Data;
    int Length;
    struct _ListNode* NextNode;
} LinkList, ListNode;

bool InitLinkList(LinkList*& InputLinkList)
{
    InputLinkList = new LinkList;
    if (!InputLinkList)
    {
        return false;
    }
    InputLinkList->Data = 0;
    InputLinkList->Length = 0;
    InputLinkList->NextNode = nullptr;
    return true;
}

bool InsertNodeInList_Front(LinkList*& InputLinkList, ListNode*& InputListNode, int InputData)
{
    if (!InputLinkList)
    {
        return false;
    }
    InputListNode = new ListNode;
    if (!InputListNode)
    {
        return false;
    }
    InputListNode->Data = InputData;
    InputListNode->NextNode = InputLinkList->NextNode;
    InputLinkList->NextNode = InputListNode;
    InputLinkList->Length++;
    return true;
}

bool InsertNodeInList_End(LinkList*& InputLinkList, ListNode*& InputListNode, int InputData)
{
    InputListNode = new ListNode;
    if (!InputListNode)
    {
        return false;
    }
    ListNode* P;
    P = InputLinkList;
    while (P->NextNode != nullptr)
    {
        P = P->NextNode;
    }
    P->NextNode = InputListNode;
    InputListNode->Data = InputData;
    InputListNode->NextNode = nullptr;
    InputLinkList->Length++;
    return true;
}

bool InsertNodeInListAnyPosition(LinkList*& InputLinkList, ListNode*& InputListNode, int Position, int InputData)
{
    if (!InputLinkList || !InputListNode || Position < 0)
    {
        return false;
    }
    int P = 1;
    ListNode* CorrectNode = InputLinkList;
    while (CorrectNode && Position > P)
    {
        CorrectNode = CorrectNode->NextNode;
        P++;
    }
    if (!CorrectNode)
    {
        return false;
    }
    ListNode* NewNode = new ListNode;
    NewNode->Data = InputData;
    NewNode->Length++;
    NewNode->NextNode = CorrectNode->NextNode;
    CorrectNode->NextNode = NewNode;
    return true;
}

bool GetElementFromListByIndex(LinkList*& InputLinkList, int Position, int& InputData)
{
    if (!InputLinkList)
    {
        return false;
    }
    int Index = 1;
    ListNode* Node = InputLinkList->NextNode;
    while (Index < Position && Node)
    {
        Node = Node->NextNode;
        Index++;
    }
    if (!Node || Position <= 0)
    {
        return false;
    }
    else
    {
        InputData = Node->Data;
        return true;
    }
}

bool GetElementFromListByData(LinkList*& InputLinkList, int& Position, int InputData)
{
    if (!InputLinkList)
    {
        Position = -1;
        return false;
    }
    int Index = 1;
    ListNode* Node = InputLinkList->NextNode;
    while (Node && Node->Data != InputData)
    {
        Node = Node->NextNode;
        Index++;
    }
    if (!Node)
    {
        Position = -1;
        return false;
    }
    else
    {
        Position = Index;
        return true;
    }
}

bool DeleteSpecificedNodeFromListByPosition(LinkList*& InputLinkList, int Position, int& InputData)
{
    if (!InputLinkList)
    {
        return false;
    }
    int Index = 0;
    ListNode* Node = InputLinkList;
    ListNode* TemproNode = Node;
    while (Node && Index < Position - 1)
    {
        Node = Node->NextNode;
        TemproNode = Node;
        Index++;
    }
    if (!Node || Position <= 0)
    {
        InputData = -1;
        return false;
    }
    else
    {
        TemproNode = TemproNode->NextNode;
        Node->NextNode = TemproNode->NextNode;
        InputData = TemproNode->Data;
        delete TemproNode;
        return true;
    }
}

bool DeleteSpecificedNodeFromListByData(LinkList*& InputLinkList, int& Position, int InputData)
{
    if (!InputLinkList)
    {
        return false;
    }
    int Index = 0;
    ListNode* Node = InputLinkList;
    ListNode* TemproNode = Node;
    while (Node && Node->NextNode && Node->NextNode->Data != InputData)
    {
        Node = Node->NextNode;
        TemproNode = Node;
        Index++;
    }
    if (!Node || !Node->NextNode)
    {
        InputData = -1;
        return false;
    }
    else
    {
        TemproNode = TemproNode->NextNode;
        Node->NextNode = TemproNode->NextNode;
        Position = Index + 1;
        delete TemproNode;
        return true;
    }
}

void DeleteLinkList(LinkList*& InputLinkList)
{
    if (!InputLinkList)
    {
        return;
    }
    LinkList* TemproNode = InputLinkList;
    while (TemproNode)
    {
        InputLinkList = InputLinkList->NextNode;
        delete TemproNode;
        TemproNode = InputLinkList;
    }
}

void PrintList(LinkList*& InputLinkList)
{
    if (!InputLinkList)
    {
        cout << "链表为空" << endl;
        return;
    }
    ListNode* P = InputLinkList->NextNode;
    while (P != nullptr)
    {
        cout << P->Data << " ";
        P = P->NextNode;
    }
    cout << endl;
}

/*int main()
{
    LinkList* link_list = nullptr;
    InitLinkList(link_list);
    ListNode* list_node = nullptr;
    int InputElement;
    cout << "插入五个元素" << endl;
    for (int i = 0; i < 5; i++)
    {
        InputElement = i;
        if (!InsertNodeInList_Front(link_list, list_node, InputElement))
        {
            cout << "头插失败" << endl;
        }
    }
    PrintList(link_list);

    /*for (int i = 0; i < 5; i++)
    {
        cout << "请输入你想添加的元素" << endl;
        cin >> InputElement;
        if (!InsertNodeInList_Front(link_list, list_node, InputElement))
        {
            cout << "头插失败" << endl;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "请输入你想添加的元素" << endl;
        cin >> InputElement;
        if (!InsertNodeInList_End(link_list, list_node, InputElement))
        {
            cout << "头插失败" << endl;
        }
    }#1#

    int InsertPosition;
    int InputData;
    /*cout << "请输入你想添加的位置和元素" << endl;
    cin >> InsertPosition >> InputData;
    if (!InsertNodeInListAnyPosition(link_list, list_node, InsertPosition, InputData))
    {
        cout << "插入失败" << endl;
    }#1#
    for (int i = 0; i < 2; i++)
    {
        cout << "请输入你想添加的位置和元素" << endl;
        cin >> InsertPosition >> InputData;
        if (!InsertNodeInListAnyPosition(link_list, list_node, InsertPosition, InputData))
        {
            cout << "插入失败" << endl;
        }
    }

    PrintList(link_list);

    //根据Position来获取特定位置的节点
    /*int ReturnData;
    if (!GetElementFromListByIndex(link_list, 7, ReturnData))
    {
        cout << "获取节点失败" << endl;
    }
    else
    {
        cout << "获取的节点数据是:" << ReturnData << endl;
    }#1#

    //根据Data来获取特定位置的节点
    /*int ReturnPosition;
    if (!GetElementFromListByData(link_list, ReturnPosition, 10))
    {
        cout << "获取位置失败" << endl;
    }
    else
    {
        cout << "获取的位置在:" << ReturnPosition << endl;
    }#1#

    //删除特定位置的节点
    /*int ReturnData;
    if (!DeleteSpecificedNodeFromListByPosition(link_list, -1, ReturnData))
    {
        cout << "删除失败" << endl;
    }
    else
    {
        cout << "删除的元素数据是:" << ReturnData << endl;
    }#1#

    //删除特定数据节点
    /*int ReturnPosition;
    if (!DeleteSpecificedNodeFromListByData(link_list, ReturnPosition, -1))
    {
        cout << "删除失败" << endl;
    }
    else
    {
        cout << "删除的元素位置是:" << ReturnPosition << endl;
    }#1#

    DeleteLinkList(link_list);

    PrintList(link_list);

    system("Pause");
    return 0;
}*/

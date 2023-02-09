#include <iostream>
using namespace std;

#define MAX_SIZE 5
typedef int DataType;

typedef struct _QueueNode
{
    DataType QueueData;
    int Priority;
    struct _QueueNode* Next;
} QueueNode;

typedef struct _QueuePriority
{
    int Length = 0;
    struct _QueueNode* Front;
    struct _QueueNode* Rear;
} QueuePriority;


bool InitQueuePriority(QueuePriority*& InputQueueList)
{
    InputQueueList = new QueuePriority;
    if (!InputQueueList)
    {
        return false;
    }
    InputQueueList->Length = 0;
    InputQueueList->Front = InputQueueList->Rear = nullptr;
    return true;
}

bool IsEmpty(QueuePriority*& InputQueueList)
{
    if (!InputQueueList)
    {
        return false;
    }
    if (InputQueueList->Length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsFull(QueuePriority*& InputQueueList)
{
    if (!InputQueueList)
    {
        return false;
    }
    if (InputQueueList->Length == MAX_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PushElementToQueuePriority(QueuePriority*& InputQueuePriority, QueueNode& InputQueueNode)
{
    if (!InputQueuePriority)
    {
        return false;
    }
    if (IsFull(InputQueuePriority))
    {
        return false;
    }

    if (IsEmpty(InputQueuePriority))
    {
        InputQueueNode.Next = nullptr;
        InputQueuePriority->Front = &InputQueueNode;
        InputQueuePriority->Rear = &InputQueueNode;
        InputQueuePriority->Length++;
        return true;
    }
    else
    {
        InputQueueNode.Next = nullptr;
        InputQueuePriority->Rear->Next = &InputQueueNode;
        InputQueuePriority->Rear = &InputQueueNode;
        InputQueuePriority->Length++;
        return true;
    }
}

bool PopElementInQueuePriority(QueuePriority*& InputQueuePriority, DataType& OutputQueueData)
{
    if (!InputQueuePriority)
    {
        return false;
    }

    int MAX_PRIORITY = 0;
    QueueNode* Prev_Node = InputQueuePriority->Front;
    QueueNode* LastNode = InputQueuePriority->Front;
    QueueNode* TempNode = LastNode->Next;
    QueueNode** PrevQueueNode = &(InputQueuePriority->Front);
    //cout << "第一个节点的优先级:" << (*PrevQueueNode)->Priority << endl;
    while (TempNode)
    {
        if (TempNode->Priority > ((*PrevQueueNode)->Priority))
        {
            //cout << "有更大优先级节点出现" << endl;
            PrevQueueNode = &(LastNode->Next);
            Prev_Node = LastNode;
            MAX_PRIORITY = TempNode->Priority;
        }
        LastNode = TempNode;
        TempNode = TempNode->Next;
    }
    //TempNode指向要被删除的节点
    TempNode = *PrevQueueNode;
    OutputQueueData = TempNode->QueueData;
    (*PrevQueueNode) = (*PrevQueueNode)->Next;
    delete TempNode;
    InputQueuePriority->Length--;

    //1.如果删除的链表只有一个节点
    if (InputQueuePriority->Length == 0)
    {
        InputQueuePriority->Front = InputQueuePriority->Rear = nullptr;
    }

    //2.如果删除的是链表最后一个节点
    if (Prev_Node && Prev_Node->Next == nullptr)
    {
        InputQueuePriority->Rear = Prev_Node;
    }
    return true;
}

void PrintQueuePriority(QueuePriority*& InputQueueList)
{
    if (!InputQueueList)
    {
        return;
    }
    QueueNode* TemQueueNode = InputQueueList->Front;
    cout << "队列中的数据为:" << endl;
    while (TemQueueNode != InputQueueList->Rear)
    {
        cout << TemQueueNode->QueueData << ' ';
        TemQueueNode = TemQueueNode->Next;
    }
    cout << TemQueueNode->QueueData << endl;
}

/*int main()
{
    QueuePriority* NewQueueList = nullptr;
    //初始化队列
    if (InitQueuePriority(NewQueueList))
    {
        cout << "初始化队列成功" << endl;
    }

    //添加元素到队列中
    DataType InputDataType;
    cout << "请输入要添加的元素:" << endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        QueueNode* NewQueueNode = new QueueNode;
        if (!NewQueueNode)
        {
            return 0;
        }
        cin >> InputDataType;
        NewQueueNode->QueueData = InputDataType;
        NewQueueNode->Priority = MAX_SIZE - i;
        if (!PushElementToQueuePriority(NewQueueList, *NewQueueNode))
        {
            cout << "添加元素失败" << endl;
        }
    }

    //打印队列
    PrintQueuePriority(NewQueueList);

    //从队列中删除元素
    DataType PoppedData;
    PopElementInQueuePriority(NewQueueList, PoppedData);
    cout << "弹出的元素为:" << PoppedData << ' ';
    cout << endl;
    /*for (int i = 0; i < 4; i++)
    {
        PopElementInQueuePriority(NewQueueList, PoppedData);
        cout << "弹出的元素为:" << PoppedData << ' ';
    }
    cout << endl;#1#

    //再次打印队列
    PrintQueuePriority(NewQueueList);

    return 1;
}*/

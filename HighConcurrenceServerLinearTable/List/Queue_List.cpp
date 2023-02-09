#include <iostream>
using namespace std;

#define MAX_SIZE 5
typedef int DataType;

typedef struct _QueueNode
{
    DataType QueueData;
    struct _QueueNode* Next;
} QueueNode;

typedef struct _QueueList
{
    int Length = 0;
    struct _QueueNode* Front;
    struct _QueueNode* Rear;
} QueueList;


bool InitQueueList(QueueList*& InputQueueList)
{
    InputQueueList = new QueueList;
    if (!InputQueueList)
    {
        return false;
    }
    InputQueueList->Length = 0;
    InputQueueList->Front = InputQueueList->Rear = nullptr;
    return true;
}

bool IsEmpty(QueueList*& InputQueueList)
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

bool IsFull(QueueList*& InputQueueList)
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

bool PushElementToQueueList(QueueList*& InputQueueList, QueueNode& InputQueueNode)
{
    if (!InputQueueList)
    {
        return false;
    }
    if (IsFull(InputQueueList))
    {
        return false;
    }

    if (IsEmpty(InputQueueList))
    {
        InputQueueNode.Next = nullptr;
        InputQueueList->Front = &InputQueueNode;
        InputQueueList->Rear = &InputQueueNode;
        InputQueueList->Length++;
        return true;
    }
    else
    {
        InputQueueNode.Next = nullptr;
        InputQueueList->Rear->Next = &InputQueueNode;
        InputQueueList->Rear = &InputQueueNode;
        InputQueueList->Length++;
        return true;
    }
}

bool PopElementInQueueList(QueueList*& InputQueueList, DataType& OutputQueueData)
{
    if (!InputQueueList)
    {
        return false;
    }

    QueueNode* PoppedQueueNode = InputQueueList->Front;
    InputQueueList->Front = InputQueueList->Front->Next;
    InputQueueList->Length--;
    OutputQueueData = PoppedQueueNode->QueueData;
    delete PoppedQueueNode;
    return true;
}

void PrintQueueList(QueueList*& InputQueueList)
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
    QueueList* NewQueueList = nullptr;
    //初始化队列
    if (InitQueueList(NewQueueList))
    {
        cout << "初始化队列成功" << endl;
    }

    //添加元素到队列中
    DataType InputDataType;
    cout << "请输入要添加的元素:" << endl;
    for (int i = 0; i < 7; i++)
    {
        QueueNode* NewQueueNode = new QueueNode;
        if (!NewQueueNode)
        {
            return 0;
        }
        cin >> InputDataType;
        NewQueueNode->QueueData = InputDataType;
        if (!PushElementToQueueList(NewQueueList, *NewQueueNode))
        {
            cout << "添加元素失败" << endl;
        }
    }

    //打印队列
    PrintQueueList(NewQueueList);

    //从队列中删除元素
    DataType PoppedData;
    for (int i = 0; i < 3; i++)
    {
        PopElementInQueueList(NewQueueList, PoppedData);
        cout << "弹出的元素为:" << PoppedData << ' ';
    }
    cout << endl;

    //再次打印队列
    PrintQueueList(NewQueueList);

    return 1;
}*/

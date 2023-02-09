#include <iostream>
using namespace std;

#define MAX_SIZE 5
typedef int DataType;

typedef struct _Queue
{
    struct _Queue* Prev;
    struct _Queue* Next;
} QueueList, QueueNode;

typedef struct _Data
{
    int FD;
    DataType Data;
    QueueNode Node;
} Data;

//初始化队列
#define InitQueue(InputQueueList) \
InputQueueList.Prev=&InputQueueList;\
InputQueueList.Next=&InputQueueList;

//判断队列是否为空
#define IsEmpty(InputQueueList)\
(&InputQueueList==(InputQueueList.Prev))

//添加元素到队列中
#define AddElementToQueue(InputQueueList,InputQueueNode)\
    InputQueueNode.Prev=&InputQueueList;\
    InputQueueNode.Next=InputQueueList.Next;\
    InputQueueNode.Next->Prev=&InputQueueNode;\
    InputQueueList.Next=&InputQueueNode;

//将元素从队列中删除
#define DeleteElementFromQueue(InputQueueList)\
    QueueNode*DeleteNode=&InputQueueList;\
    while (DeleteNode->Next!=&InputQueueList){\
    DeleteNode=DeleteNode->Next;}\
    DeleteNode->Prev->Next=&InputQueueList;\
    DataType DeleteInterval= offsetof(Data,Node);\
    QueueNode* DeleteSubtractQueueNode = DeleteNode;\
    Data*DeleteTempData=(Data*)((size_t)DeleteSubtractQueueNode-DeleteInterval);\
    delete DeleteTempData;

//打印队列中的元素
#define PrintElementInQueue(InputQueueList)\
    QueueNode* TempQueueNode = InputQueueList.Next;\
    while (TempQueueNode->Next!=&InputQueueList){\
    DataType Interval= offsetof(Data,Node);\
    QueueNode* SubtractQueueNode = TempQueueNode;\
    Data*TempData=(Data*)((size_t)SubtractQueueNode-Interval);\
    TempQueueNode=TempQueueNode->Next;\
    cout << "FD为:" << TempData->FD << endl;}\

int main()
{
    //初始化队列
    Data* P_Data = new Data;
    if (P_Data == nullptr) return 1;
    P_Data->FD = -1;
    P_Data->Data = -1;
    InitQueue(P_Data->Node);

    //查看队列是否为空
    IsEmpty(P_Data->Node);

    //添加元素到队列中
    for (int i = 0; i < 10; i++)
    {
        Data* NewData = new Data;
        if (NewData == nullptr)
        {
            break;
        }
        NewData->Data = i;
        NewData->FD = i;
        AddElementToQueue(P_Data->Node, NewData->Node);
    }

    //打印队列中的元素
    /*QueueNode* TempQueueNode = P_Data->Node.Next;
    while (TempQueueNode->Next != &P_Data->Node)
    {
        DataType Interval = offsetof(Data, Node);
        QueueNode* SubtractQueueNode = TempQueueNode;
        Data* TempData = (Data*)((size_t)SubtractQueueNode - Interval);
        TempQueueNode = TempQueueNode->Next;
        cout << "FD为:" << TempData->FD << endl;
    }*/
    PrintElementInQueue(P_Data->Node);

    //从队列中删除元素
    for (int i = 0; i < 5; i++)
    {
        DeleteElementFromQueue(P_Data->Node);
    }

    return 1;
}

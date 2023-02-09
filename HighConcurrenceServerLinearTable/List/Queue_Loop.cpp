#include <iostream>
using namespace std;

#define MAX_SIZE 8
typedef int DataType;

typedef struct _QueueLoop
{
    DataType Sequence[MAX_SIZE];
    int Front;
    int Rear;
} QueueLoop;

bool QueueLoopIsFull(QueueLoop*& InputQueueLoop)
{
    if (!InputQueueLoop)
    {
        return false;
    }
    if (
        ((InputQueueLoop->Rear + 1) % MAX_SIZE)
        ==
        InputQueueLoop->Front
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QueueLoopIsEmpty(QueueLoop*& InputQueueLoop)
{
    if (!InputQueueLoop)
    {
        return false;
    }
    if (InputQueueLoop->Rear == InputQueueLoop->Front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool InitializeQueueLoop(QueueLoop*& InputQueueLoop)
{
    InputQueueLoop = new QueueLoop;
    if (!InputQueueLoop)
    {
        return false;
    }

    InputQueueLoop->Front = 0;
    InputQueueLoop->Rear = 0;
    return true;
}

bool PushElementToQueueLoop(QueueLoop*& InputQueueLoop, DataType& InputData)
{
    if (!InputQueueLoop)
    {
        return false;
    }
    if (QueueLoopIsFull(InputQueueLoop))
    {
        cout << "队列已满" << endl;
        return false;
    }
    else
    {
        InputQueueLoop->Rear = (++InputQueueLoop->Rear) % MAX_SIZE;
        InputQueueLoop->Sequence[InputQueueLoop->Rear % MAX_SIZE] = InputData;
        return true;
    }
}


bool PopElementFromQueueLoop(QueueLoop*& InputQueueLoop, DataType& InputData)
{
    if (!InputQueueLoop)
    {
        return false;
    }
    if (QueueLoopIsEmpty(InputQueueLoop))
    {
        cout << "队列已经为空,无元素弹出" << endl;
        return false;
    }
    else
    {
        InputQueueLoop->Front += 1;
        InputData = InputQueueLoop->Sequence[InputQueueLoop->Front];
        return true;
    }
}

int GetQueueLength(QueueLoop* InputQueueLoop)
{
    if (InputQueueLoop == nullptr)
    {
        return false;
    }
    return ((InputQueueLoop->Rear - InputQueueLoop->Front) + MAX_SIZE) % MAX_SIZE;
}

void PrintQueueLoop(QueueLoop*& InputQueueLoop)
{
    if (!InputQueueLoop)
    {
        return;
    }
    if (QueueLoopIsEmpty(InputQueueLoop))
    {
        cout << "队列已空" << endl;
        return;
    }
    int i = InputQueueLoop->Front + 1;
    for (; i != InputQueueLoop->Rear; (i++) % MAX_SIZE)
    {
        cout << InputQueueLoop->Sequence[i] << ' ';
    }
    cout << InputQueueLoop->Sequence[i] << endl;
    cout << endl;
}

void MakeQueueArrayLoop(QueueLoop*& InputQueueLoop)
{
    InputQueueLoop->Front = InputQueueLoop->Rear = 0;
}

/*int main()
{
    //初始化循环队列
    QueueLoop* P_QueueLoop = nullptr;
    InitializeQueueLoop(P_QueueLoop);
    if (P_QueueLoop == nullptr)
    {
        return 0;
    }
    //添加元素到循环队列中
    DataType NewDataType = 0;
    for (int i = 0; i < 10; i++)
    {
        NewDataType = i;
        PushElementToQueueLoop(P_QueueLoop, NewDataType);
    }
    //打印循环队列
    cout << "队列长度为:" << GetQueueLength(P_QueueLoop) << endl;
    PrintQueueLoop(P_QueueLoop);

    //从循环队列中弹出元素
    for (int i = 0; i < 8; i++)
    {
        PopElementFromQueueLoop(P_QueueLoop, NewDataType);
    }
    //打印循环链表
    PrintQueueLoop(P_QueueLoop);

    return 1;
}*/

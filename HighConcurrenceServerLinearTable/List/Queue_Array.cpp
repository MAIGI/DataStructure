#include <iostream>
using namespace std;

#define MAX_SIZE 8
typedef int DataType;

typedef struct _QueueArray
{
    DataType Sequence[MAX_SIZE];
    int Front;
    int Rear;
} QueueArray;

bool QueueArrayIsFull(QueueArray*& InputQueueArray)
{
    if (!InputQueueArray)
    {
        return false;
    }
    if (InputQueueArray->Rear == MAX_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QueueArrayIsEmpty(QueueArray*& InputQueueArray)
{
    if (!InputQueueArray)
    {
        return false;
    }
    if (InputQueueArray->Rear == InputQueueArray->Front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool InitializeQueueArray(QueueArray*& InputQueueArray)
{
    InputQueueArray = new QueueArray;
    if (!InputQueueArray)
    {
        return false;
    }

    InputQueueArray->Front = 0;
    InputQueueArray->Rear = 0;
    return true;
}

bool PushElementToQueueArray(QueueArray*& InputQueueArray, DataType& InputData)
{
    if (!InputQueueArray)
    {
        return false;
    }
    if (QueueArrayIsFull(InputQueueArray))
    {
        cout << "队列已满" << endl;
        return false;
    }
    else
    {
        InputQueueArray->Sequence[InputQueueArray->Rear] = InputData;
        InputQueueArray->Rear++;
        return true;
    }
}

bool PopElementFromQueueArray1(QueueArray*& InputQueueArray, DataType& InputData)
{
    if (!InputQueueArray)
    {
        return false;
    }
    if (QueueArrayIsEmpty(InputQueueArray))
    {
        cout << "队列已经为空,无元素弹出" << endl;
        return false;
    }
    else
    {
        InputData = InputQueueArray->Sequence[InputQueueArray->Front];
        for (int i = InputQueueArray->Front; i < InputQueueArray->Rear - 1; i++)
        {
            InputQueueArray->Sequence[i] = InputQueueArray->Sequence[i + 1];
        }
        InputQueueArray->Rear--;
        return true;
    }
}

bool PopElementFromQueueArray2(QueueArray*& InputQueueArray, DataType& InputData)
{
    if (!InputQueueArray)
    {
        return false;
    }
    if (QueueArrayIsEmpty(InputQueueArray))
    {
        cout << "队列已经为空,无元素弹出" << endl;
        return false;
    }
    else
    {
        InputData = InputQueueArray->Sequence[InputQueueArray->Front];
        InputQueueArray->Front++;
        return true;
    }
}

void PrintQueueArray(QueueArray*& InputQueueArray)
{
    if (!InputQueueArray)
    {
        return;
    }
    if (InputQueueArray->Front == InputQueueArray->Rear)
    {
        cout << "队列已空" << endl;
    }
    for (int i = InputQueueArray->Front; i < InputQueueArray->Rear; i++)
    {
        cout << InputQueueArray->Sequence[i] << ' ';
    }
    cout << endl;
}

void MakeQueueArrayEmpty(QueueArray*& InputQueueArray)
{
    InputQueueArray->Front = InputQueueArray->Rear = 0;
}

/*int main()
{
    QueueArray* P_QueueArray = nullptr;
    //初始化队列
    InitializeQueueArray(P_QueueArray);
    //添加元素到队列中
    DataType InputDataType = -1;
    cout << "请输入要添加的元素" << endl;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cin >> InputDataType;
        PushElementToQueueArray(P_QueueArray, InputDataType);
    }
    //打印队列
    PrintQueueArray(P_QueueArray);
    //从队列中弹出元素(方法1)
    DataType PoppedDatay1;
    PopElementFromQueueArray1(P_QueueArray, PoppedDatay1);
    cout << "弹出的元素是:" << PoppedDatay1 << endl;
    PrintQueueArray(P_QueueArray);
    //从队列中弹出元素(方法2)
    DataType PoppedDatay2;
    PopElementFromQueueArray2(P_QueueArray, PoppedDatay2);
    cout << "弹出的元素是:" << PoppedDatay2 << endl;
    PrintQueueArray(P_QueueArray);
    //清空队列
    MakeQueueArrayEmpty(P_QueueArray);
    PrintQueueArray(P_QueueArray);

    return 1;
}*/

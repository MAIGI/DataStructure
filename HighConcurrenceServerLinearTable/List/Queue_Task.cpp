#include <iostream>
using namespace std;

#define MAX_SIZE 5
typedef int DataType;

typedef struct TaskNode
{
    int ID;
    void (*Task)(void);
    struct TaskNode* Next;
} QueueNode;

typedef struct _TaskList
{
    int Length = 0;
    struct TaskNode* Front;
    struct TaskNode* Rear;
} TaskList;

bool InitTaskList(TaskList*& InputTaskList)
{
    InputTaskList = new TaskList;
    if (!InputTaskList)
    {
        return false;
    }
    InputTaskList->Length = 0;
    InputTaskList->Front = InputTaskList->Rear = nullptr;
    return true;
}

bool IsFull(TaskList* InputTaskList)
{
    if (!InputTaskList)
    {
        return false;
    }
    if (InputTaskList->Length == MAX_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsEmpty(TaskList* InputTaskList)
{
    if (!InputTaskList)
    {
        return false;
    }
    if (InputTaskList->Length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PushTaskToTaskList(TaskList* InputTaskList, TaskNode* InputTaskNode)
{
    if (!InputTaskList || !InputTaskNode)
    {
        return false;
    }
    if (IsFull(InputTaskList))
    {
        cout << "队列已满，无法插入" << endl;
        return false;
    }
    if (IsEmpty(InputTaskList))
    {
        InputTaskNode->Next = nullptr;
        InputTaskList->Front = InputTaskList->Rear = InputTaskNode;
        InputTaskList->Length++;
        return true;
    }
    else
    {
        InputTaskNode->Next = nullptr;
        InputTaskList->Rear->Next = InputTaskNode;
        InputTaskList->Rear = InputTaskNode;
        InputTaskList->Length++;
        return true;
    }
}

bool PopTaskFromTaskList(TaskList* InputTaskList)
{
    if (!InputTaskList)
    {
        return false;
    }
    if (InputTaskList->Length <= 0)
    {
        cout << "已经没有可执行任务" << endl;
        return false;
    }
    TaskNode* TempTaskNode = InputTaskList->Front;
    TempTaskNode->Task();
    InputTaskList->Front = InputTaskList->Front->Next;
    InputTaskList->Length--;
    delete TempTaskNode;
    return true;
}

void PrintTaskList(TaskList* InputTaskList)
{
    if (!InputTaskList)
    {
        return;
    }
    cout << "任务链中总共有" << InputTaskList->Length << "个任务" << endl;
}

void Task1()
{
    cout << "这里是任务1哦" << endl;
}

void Task2()
{
    cout << "这里是任务2哦" << endl;
}

/*int main()
{
    //初始化任务序列
    TaskList* P_TaskList = nullptr;
    if (InitTaskList(P_TaskList))
    {
        cout << "初始化任务列表成功" << endl;
    }

    //添加任务1到任务序列中
    TaskNode* P_TaskNode1 = new TaskNode;
    if (!P_TaskNode1)
    {
        return 1;
    }
    P_TaskNode1->ID = 1;
    P_TaskNode1->Task = &Task1;
    PushTaskToTaskList(P_TaskList, P_TaskNode1);

    //添加任务2到任务序列中
    TaskNode* P_TaskNode2 = new TaskNode;
    if (!P_TaskNode2)
    {
        return 1;
    }
    P_TaskNode2->ID = 2;
    P_TaskNode2->Task = &Task2;
    PushTaskToTaskList(P_TaskList, P_TaskNode2);

    //打印队列
    PrintTaskList(P_TaskList);

    //执行任务
    for (int i = 0; i < 5; i++)
    {
        PopTaskFromTaskList(P_TaskList);
    }

    //再次打印队列
    PrintTaskList(P_TaskList);


    return 1;
}*/

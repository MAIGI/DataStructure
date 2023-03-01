/*
#include <iostream>
using namespace std;

typedef struct _DataType
{
    int Priority;
    int Data;
} DataType;

#define IsLess(a,b)\
    (a.Priority<b.Priority)

#define MAX_CAPACITY 16

//堆的数据结构
typedef struct _PriorityHeap
{
    DataType* MaxHeapEntry;
    int Size;
    int Capacity;
} PriorityHeap;

bool InitPriorityHeap(PriorityHeap& InputPriorityHeap, DataType* InputArray, int InputSize);
static void BuildPriorityHeap(PriorityHeap& InputPriorityHeap);
static void AdjustDown(PriorityHeap& InputPriorityHeap, int InputPosition);
bool PushElementToPriorityHeap(PriorityHeap& InputPriorityHeap, DataType InputElement);
bool PopElementToPriorityHeap(PriorityHeap& InputPriorityHeap, DataType& OutputData);
static void AdjustUp(PriorityHeap& InputMaxHeap, int InputPosition);
void DestoryPriorityHeap(PriorityHeap& InputPriorityHeap);
void SortPriorityHeap(PriorityHeap& InputPriorityHeap, DataType* InputDataArray);

bool InitPriorityHeap(PriorityHeap& InputPriorityHeap, DataType* InputArray, int InputSize)
{
    if (InputArray == nullptr && InputSize < 0)
    {
        return false;
    }

    InputPriorityHeap.Capacity = MAX_CAPACITY > InputSize ? MAX_CAPACITY : InputSize;
    InputPriorityHeap.Size = 0;

    InputPriorityHeap.MaxHeapEntry = new DataType[InputPriorityHeap.Capacity];
    if (InputPriorityHeap.MaxHeapEntry == nullptr)
    {
        return false;
    }

    if (InputSize > 0)
    {
        memcpy(InputPriorityHeap.MaxHeapEntry, InputArray, InputSize * sizeof(DataType));
        InputPriorityHeap.Size = InputSize;
        //创建MaxHeap
        BuildPriorityHeap(InputPriorityHeap);
    }
    return true;
}

static void BuildPriorityHeap(PriorityHeap& InputPriorityHeap)
{
    for (int Position = (InputPriorityHeap.Size - 1) / 2; Position >= 0; Position--)
    {
        AdjustDown(InputPriorityHeap, Position);
    }
}

static void AdjustDown(PriorityHeap& InputPriorityHeap, int InputPosition)
{
    DataType CurrentParentValue;
    int Parent, Child;
    for (Parent = InputPosition; (Parent * 2 + 1) < (InputPriorityHeap.Size); Parent = Child)
    {
        CurrentParentValue = InputPriorityHeap.MaxHeapEntry[Parent];
        Child = Parent * 2 + 1;
        //取两个子节点中较大的节点
        if (Child + 1 < InputPriorityHeap.Size && IsLess(InputPriorityHeap.MaxHeapEntry[Child],
                                                         InputPriorityHeap.MaxHeapEntry[Child + 1]))
        {
            Child++;
        }

        //与父节点进行比较，如果子节点更大，则与父节点进行交换
        if (IsLess(CurrentParentValue, InputPriorityHeap.MaxHeapEntry[Child]))
        {
            InputPriorityHeap.MaxHeapEntry[Parent] = InputPriorityHeap.MaxHeapEntry[Child];
            InputPriorityHeap.MaxHeapEntry[Child] = CurrentParentValue;
        }
        else
        {
            break;
        }
    }
}

bool PushElementToPriorityHeap(PriorityHeap& InputMaxHeap, DataType InputElement)
{
    if (InputMaxHeap.Size == InputMaxHeap.Capacity)
    {
        return false;
    }

    InputMaxHeap.MaxHeapEntry[InputMaxHeap.Size++] = InputElement;
    AdjustUp(InputMaxHeap, InputMaxHeap.Size - 1);
    return true;
}

bool PopElementToPriorityHeap(PriorityHeap& InputMaxHeap, DataType& OutputData)
{
    if (InputMaxHeap.Size <= 0)
    {
        return false;
    }
    OutputData = InputMaxHeap.MaxHeapEntry[0];
    InputMaxHeap.MaxHeapEntry[0] = InputMaxHeap.MaxHeapEntry[--InputMaxHeap.Size];
    AdjustDown(InputMaxHeap, 0);
    return true;
}

void AdjustUp(PriorityHeap& InputMaxHeap, int InputPosition)
{
    int Index = InputPosition;
    int ParentPosition;
    DataType ParentValue;
    while (Index > 0)
    {
        ParentPosition = (Index - 1) / 2;
        ParentValue = InputMaxHeap.MaxHeapEntry[ParentPosition];
        if (IsLess(InputMaxHeap.MaxHeapEntry[ParentPosition], InputMaxHeap.MaxHeapEntry[Index]))
        {
            InputMaxHeap.MaxHeapEntry[ParentPosition] = InputMaxHeap.MaxHeapEntry[Index];
            InputMaxHeap.MaxHeapEntry[Index] = ParentValue;
            Index = ParentPosition;
        }
    }
}

void DestoryPriorityHeap(PriorityHeap& InputPriority)
{
    delete []InputPriority.MaxHeapEntry;
}

void SortPriorityHeap(PriorityHeap& InputPriorityHeap, DataType* InputDataArray)
{
    DataType MaxData;
    while (InputPriorityHeap.Size > 0)
    {
        PopElementToPriorityHeap(InputPriorityHeap, MaxData);
        InputPriorityHeap.MaxHeapEntry[InputPriorityHeap.Size - 1] = MaxData;
        InputDataArray[InputPriorityHeap.Size - 1] = MaxData;
        InputPriorityHeap.Size--;
        AdjustDown(InputPriorityHeap, 0);
    }
}

/*int main()
{
    DataType ChaosArray[10];
    for (int i = 0; i < 10; i++)
    {
        ChaosArray[i].Priority = i;
    }
    //初始化堆
    PriorityHeap PrepareHeap;
    if (!InitPriorityHeap(PrepareHeap, ChaosArray, sizeof(ChaosArray) / sizeof(DataType)))
    {
        cout << "初始化堆失败" << endl;
    }

    cout << "最大堆的容量为:" << PrepareHeap.Capacity << endl;
    cout << "最大堆的大小为:" << PrepareHeap.Size << endl;

    //打印最大堆中的元素
    cout << "数值为:";
    for (int i = 0; i < PrepareHeap.Size; i++)
    {
        cout << PrepareHeap.MaxHeapEntry[i].Priority << ' ';
    }
    cout << endl;

    //插入元素到最大堆中
    DataType TemData;
    TemData.Priority = 999;
    TemData.Data = 999;
    if (!PushElementToPriorityHeap(PrepareHeap, TemData))
    {
        cout << "插入元素失败" << endl;
    }

    //打印最大堆中的元素
    cout << "数值为:";
    for (int i = 0; i < PrepareHeap.Size; i++)
    {
        cout << PrepareHeap.MaxHeapEntry[i].Priority << ' ';
    }
    cout << endl;

    //弹出最大堆的最大元素
    cout << "弹出的元素的优先级为:" << endl;

    int LoopTime = PrepareHeap.Size;
    for (int i = 0; i < LoopTime; i++)
    {
        DataType TemData2;
        PopElementToPriorityHeap(PrepareHeap, TemData2);
        cout << TemData2.Priority << ' ';
    }
    cout << endl;

    //堆排序
    SortPriorityHeap(PrepareHeap, ChaosArray);

    //打印排序后的堆
    LoopTime = PrepareHeap.Size;
    for (int i = 0; i < LoopTime; i++)
    {
        cout << ChaosArray[i].Priority << ' ';
    }
    cout << endl;

    return 1;
}#1#
*/

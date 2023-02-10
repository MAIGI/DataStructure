#include <iostream>
using namespace std;

#define MAX_CAPACITY 16

//堆的数据结构
typedef struct _MaxHeap
{
    int* MaxHeapEntry;
    int Size;
    int Capacity;
} MaxHeap;

bool InitMaxHeap(MaxHeap& InputMaxHeap, int* InputArray, int InputSize);
static void BuildHeap(MaxHeap& InputHeap);
static void AdjustDown(MaxHeap& InputMaxHeap, int InputPosition);
bool InsertElementToMaxHeap(MaxHeap& InputMaxHeap, int InputElement);
static void AdjustUp(MaxHeap& InputMaxHeap, int InputPosition);

bool InitMaxHeap(MaxHeap& InputMaxHeap, int* InputArray, int InputSize)
{
    if (InputArray == nullptr && InputSize < 0)
    {
        return false;
    }

    InputMaxHeap.Capacity = MAX_CAPACITY > InputSize ? MAX_CAPACITY : InputSize;
    InputMaxHeap.Size = 0;

    InputMaxHeap.MaxHeapEntry = new int[InputMaxHeap.Capacity];
    if (InputMaxHeap.MaxHeapEntry == nullptr)
    {
        return false;
    }

    if (InputSize > 0)
    {
        memcpy(InputMaxHeap.MaxHeapEntry, InputArray, InputSize * sizeof(int));
        InputMaxHeap.Size = InputSize;
        //创建MaxHeap
        BuildHeap(InputMaxHeap);
    }
    return true;
}

static void BuildHeap(MaxHeap& InputHeap)
{
    for (int Position = (InputHeap.Size - 1) / 2; Position >= 0; Position--)
    {
        AdjustDown(InputHeap, Position);
    }
}

static void AdjustDown(MaxHeap& InputMaxHeap, int InputPosition)
{
    int CurrentParentValue;
    int Parent, Child;
    for (Parent = InputPosition; (Parent * 2 + 1) < (InputMaxHeap.Size); Parent = Child)
    {
        CurrentParentValue = InputMaxHeap.MaxHeapEntry[Parent];
        Child = Parent * 2 + 1;
        //取两个子节点中较大的节点
        if (Child + 1 < InputMaxHeap.Size && InputMaxHeap.MaxHeapEntry[Child + 1] > InputMaxHeap.MaxHeapEntry[Child])
        {
            Child++;
        }

        //与父节点进行比较，如果子节点更大，则与父节点进行交换
        if (CurrentParentValue < InputMaxHeap.MaxHeapEntry[Child])
        {
            InputMaxHeap.MaxHeapEntry[Parent] = InputMaxHeap.MaxHeapEntry[Child];
            InputMaxHeap.MaxHeapEntry[Child] = CurrentParentValue;
        }
        else
        {
            break;
        }
    }
}

bool InsertElementToMaxHeap(MaxHeap& InputMaxHeap, int InputElement)
{
    if (InputMaxHeap.Size == InputMaxHeap.Capacity)
    {
        return false;
    }

    InputMaxHeap.MaxHeapEntry[InputMaxHeap.Size++] = InputElement;
    AdjustUp(InputMaxHeap, InputMaxHeap.Size - 1);
    return true;
}

void AdjustUp(MaxHeap& InputMaxHeap, int InputPosition)
{
    int Index = InputPosition;
    int ParentPosition;
    int ParentValue;
    while (Index > 0)
    {
        ParentPosition = (Index - 1) / 2;
        ParentValue = InputMaxHeap.MaxHeapEntry[ParentPosition];
        if (InputMaxHeap.MaxHeapEntry[Index] > InputMaxHeap.MaxHeapEntry[ParentPosition])
        {
            InputMaxHeap.MaxHeapEntry[ParentPosition] = InputMaxHeap.MaxHeapEntry[Index];
            InputMaxHeap.MaxHeapEntry[Index] = ParentValue;
            Index = ParentPosition;
        }
    }
}

/*int main()
{
    int ChaosArray[]{0, 1, 2, 3, 4, 5, 6, 7, 8};
    //初始化堆
    MaxHeap PrepareHeap;
    if (!InitMaxHeap(PrepareHeap, ChaosArray, sizeof(ChaosArray) / sizeof(int)))
    {
        cout << "初始化堆失败" << endl;
    }

    cout << "最大堆的容量为:" << PrepareHeap.Capacity << endl;
    cout << "最大堆的大小为:" << PrepareHeap.Size << endl;

    //打印最大堆中的元素
    cout << "数值为:";
    for (int i = 0; i < PrepareHeap.Size; i++)
    {
        cout << PrepareHeap.MaxHeapEntry[i] << ' ';
    }
    cout << endl;

    //插入元素到最大堆中
    if (!InsertElementToMaxHeap(PrepareHeap, 999))
    {
        cout << "插入元素失败" << endl;
    }

    //打印最大堆中的元素
    cout << "数值为:";
    for (int i = 0; i < PrepareHeap.Size; i++)
    {
        cout << PrepareHeap.MaxHeapEntry[i] << ' ';
    }
    cout << endl;

    return 1;
}*/

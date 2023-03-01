/*
#include "QuickSort.h"

#include <iostream>
using namespace std;

int Partition(int* InputArray, int Low, int High)
{
    if (InputArray == nullptr)
    {
        return -1;
    }
    int Front = Low;
    int Rear = High;
    const int BaseValue = InputArray[Front];
    if (Low < High)
    {
        while (Front < Rear)
        {
            while (Front < Rear && InputArray[Rear] >= BaseValue)
            {
                Rear--;
            }
            if (Front < Rear)
            {
                InputArray[Front++] = InputArray[Rear];
            }

            while (Front < Rear && InputArray[Front] <= BaseValue)
            {
                Front++;
            }
            if (Front < Rear)
            {
                InputArray[Rear--] = InputArray[Front];
            }
        }
        InputArray[Front] = BaseValue;
        return Front;
    }
    return 0;
}

void CustomQuickSort(int* InputArray, int Low, int High)
{
    if (InputArray == nullptr || Low >= High)
    {
        return;
    }

    int BaseIndex = Partition(InputArray, Low, High);
    CustomQuickSort(InputArray, Low, BaseIndex - 1);
    CustomQuickSort(InputArray, BaseIndex + 1, High);
}

int main()
{
    int NewArray[]{10, 6, 2, 99, 7, 14, 5, 6, 999, 1};
    constexpr int Length = sizeof(NewArray) / sizeof(NewArray[0]);
    Partition(NewArray, 0, Length - 1);
    for (int i = 0; i < Length; i++)
    {
        cout << NewArray[i] << ' ';
    }
    cout << endl;
    return 1;
}
*/

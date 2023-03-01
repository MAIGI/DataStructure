/*
#include <iostream>
using namespace std;

void Swap(int* A, int* B)
{
    const int Temp = *A;
    *A = *B;
    *B = Temp;
}

void SelectionSort(int* InputArray, int Length)
{
    if (InputArray == nullptr)
    {
        return;
    }
    int MinIndex = 0;
    for (int i = 0; i < Length; i++)
    {
        MinIndex = i;
        for (int j = i + 1; j < Length; j++)
        {
            if (InputArray[j] < InputArray[MinIndex])
            {
                MinIndex = j;
            }
        }
        if (MinIndex != i)
        {
            Swap(&InputArray[MinIndex], &InputArray[i]);
        }
    }
}

int main()
{
    int NewArray[]{78, 98, 12, 2, 4, 6, 19, 7,199,54,999};
    constexpr int Length = size(NewArray);
    SelectionSort(NewArray, Length);
    for (int i = 0; i < Length; i++)
    {
        cout << NewArray[i] << ' ';
    }
    cout << endl;
    return 1;
}
*/

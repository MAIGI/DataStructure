/*
#include <iostream>
using namespace std;

void Swap(int* A, int* B)
{
    const int Temp = *A;
    *A = *B;
    *B = Temp;
}

void IntersectionSort(int* InputArray, int Length)
{
    if (InputArray == nullptr)
    {
        return;
    }
    for (int i = 1; i < Length; i++)
    {
        int CurrentValue = InputArray[i];
        int PreIndex = i - 1;
        while (PreIndex >= 0 && CurrentValue < InputArray[PreIndex])
        {
            InputArray[PreIndex + 1] = InputArray[PreIndex];
            PreIndex--;
        }
        InputArray[PreIndex + 1] = CurrentValue;
    }
}

int main()
{
    int NewArray[]{78, 98, 12, 2, 4, 6, 19, 7, 199, 54, 999};
    constexpr int Length = sizeof(NewArray) / sizeof(NewArray[0]);
    IntersectionSort(NewArray, Length);
    for (int i = 0; i < Length; i++)
    {
        cout << NewArray[i] << ' ';
    }
    cout << endl;
    return 1;
}
*/

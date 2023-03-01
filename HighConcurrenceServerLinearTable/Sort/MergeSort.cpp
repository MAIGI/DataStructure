/*
#include <iostream>
using namespace std;

void MergeAdd(int* InputArray, int Left, int Middle, int Right, int* TempArray)
{
    if (InputArray == nullptr || TempArray == nullptr)
    {
        return;
    }
    const int Length = Right - Left + 1;
    int L = Left;
    int M = Middle;
    int Index = Left;
    while (L < Middle && M <= Right)
    {
        if (InputArray[L] < InputArray[M])
        {
            TempArray[Index++] = InputArray[L++];
        }
        else
        {
            TempArray[Index++] = InputArray[M++];
        }
    }

    while (L < Middle)
    {
        TempArray[Index++] = InputArray[L++];
    }

    while (M <= Right)
    {
        TempArray[Index++] = InputArray[M++];
    }

    memcpy(InputArray + Left, TempArray + Left, sizeof(int) * Length);
}

void MergeSort(int* InputArray, int Left, int Right, int* Temp)
{
    cout << Left << ' ' << Right << endl;
    if (InputArray == nullptr)
    {
        return;
    }
    const int Middle = Left + (Right - Left) / 2;

    if (Left < Right)
    {
        MergeSort(InputArray, Left, Middle, Temp);
        MergeSort(InputArray, Middle + 1, Right, Temp);
        MergeAdd(InputArray, Left, Middle + 1, Right, Temp);
    }
}

int main()
{
    int NewArray[]{4, 6, 2, 99, 7, 14, 5, 6, 999, 10};
    constexpr int Length = sizeof(NewArray) / sizeof(NewArray[0]);
    int Left = 0;
    int Right = Length - 1;
    int Middle = Left + (Right - Left) / 2;
    int* TempArray = new int[Length];
    if (TempArray == nullptr)
    {
        return 0;
    }
    MergeSort(NewArray, 0, Right, TempArray);
    for (int i = 0; i < Length; i++)
    {
        cout << NewArray[i] << ' ';
    }
    cout << endl;
    return 1;
}
*/

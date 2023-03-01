#include <iostream>
using namespace std;

void Swap(int* A, int* B)
{
    const int Temp = *A;
    *A = *B;
    *B = Temp;
}

void BubbleSort(int* InputArray, int Length)
{
    bool bSorted = true;
    if (InputArray == nullptr)
    {
        return;
    }
    for (int i = 0; i < Length - 1; i++)
    {
        for (int j = 0; j < Length - i - 1; j++)
        {
            if (InputArray[j] > InputArray[j + 1])
            {
                Swap(&InputArray[j], &InputArray[j + 1]);
                bSorted = false;
            }
        }
        if (bSorted == true)
        {
            break;
        }
    }
}

int main()
{
    int NewArray[]{78, 98, 12, 2, 4, 6, 19, 7, 199, 54, 999};
    constexpr int Length = size(NewArray);
    BubbleSort(NewArray, Length);
    for (int i = 0; i < Length; i++)
    {
        cout << NewArray[i] << ' ';
    }
    cout << endl;
    return 1;
}

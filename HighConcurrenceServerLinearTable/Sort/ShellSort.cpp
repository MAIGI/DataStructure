/*
#include <iostream>
using namespace std;

void CustomShellSort(int* InputArray, int Length)
{
    int Gap = Length / 2;
    for (; Gap >= 1; Gap = Gap / 2)
    {
        for (int i = Gap; i < Length; i++)
        {
            const int CurrentValue = InputArray[i];
            int j;
            for (j = i - Gap; j >= 0 && InputArray[j] > CurrentValue; j -= Gap)
            {
                InputArray[j + Gap] = InputArray[j];
            }
            InputArray[j + Gap] = CurrentValue;
        }
    }
}

int main()
{
    int NewArray[]{78, 98, 12, 2, 4, 6, 19, 7, 199, 54, 999};
    constexpr int Length = sizeof(NewArray) / sizeof(NewArray[0]);
    CustomShellSort(NewArray, Length);
    for (int i = 0; i < Length; i++)
    {
        cout << NewArray[i] << ' ';
    }
    cout << endl;
    return 1;
}
*/

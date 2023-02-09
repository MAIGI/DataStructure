#pragma once
#include <ctime>

#define MAX_SIZE 100

typedef struct
{
    int FD;
    time_t TimeOut;
} _TimeOut;

typedef struct
{
    _TimeOut* ElementEntry;
    int Length;
    int Size;
} LinearTable;

//顺序表接口
bool TableIsFull(LinearTable& InputLinearTable);
bool TableIsEmpty(LinearTable& InputLinearTable);
bool InitTable(LinearTable& InputLinearTable);
bool AddElementInTable(LinearTable& InputLinearTable, _TimeOut Element);
bool InsertElementInTable(LinearTable& InputLinearTable, int Position, _TimeOut Element);
bool RemoveElementInTable(LinearTable& InputLinearTable, int Position);
void DestroyTable(LinearTable& InputLinearTable);
void PrintTable(LinearTable& InputLinearTable);

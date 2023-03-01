#include <iostream>
using namespace std;

typedef int DataType;

typedef struct _BinaryNode
{
    struct _BinaryNode* Child_L;
    struct _BinaryNode* Child_R;
    DataType Data;
} BinaryTree, BinaryNode;

#define IsLess(A,B) (A->Data<B->Data)
#define IsGreater(A,B) (A->data>B->Data)
#define IsEqual(A,B) (A->Data==B->Data)

bool InitCustomBinaryTree(BinaryTree*& InputBinaryTree)
{
    InputBinaryTree = new BinaryNode;
    if (InputBinaryTree == nullptr)
    {
        return false;
    }
    InputBinaryTree->Data = -1;
    InputBinaryTree->Child_L = nullptr;
    InputBinaryTree->Child_R = nullptr;
    return true;
}

bool InsertElementToCustomBinaryTree(BinaryTree* InputBinaryTree, BinaryNode* InputBinaryNode)
{
    if (InputBinaryTree == nullptr || InputBinaryNode == nullptr)
    {
        return false;
    }

    //清空InputBinaryNode的左右子树的指针
    InputBinaryNode->Child_L = nullptr;
    InputBinaryNode->Child_R = nullptr;

    //如果二叉搜索树是空树
    BinaryNode* TempNode = nullptr;
    BinaryNode* ParentNode = nullptr;
    if (InputBinaryTree->Data == -1)
    {
        InputBinaryTree->Data = InputBinaryNode->Data;
        InputBinaryTree->Child_L = InputBinaryNode->Child_L;
        InputBinaryTree->Child_R = InputBinaryNode->Child_R;
        return true;
    }
    else
    {
        TempNode = InputBinaryTree;
    }

    //插入节点
    bool bInsertLeft;
    while (TempNode != nullptr)
    {
        ParentNode = TempNode;
        if (IsLess(InputBinaryNode, TempNode))
        {
            TempNode = TempNode->Child_L;
            bInsertLeft = true;
        }
        else
        {
            TempNode = TempNode->Child_R;
            bInsertLeft = false;
        }
    }
    if (bInsertLeft)
    {
        ParentNode->Child_L = InputBinaryNode;
    }
    else
    {
        ParentNode->Child_R = InputBinaryNode;
    }
    return true;
}

DataType FindMax(BinaryNode* InputBinaryNode)
{
    if (InputBinaryNode->Child_R == nullptr)
    {
        return InputBinaryNode->Data;
    }
    return FindMax(InputBinaryNode->Child_R);
}

BinaryNode* DeleteNodeFromCustomBinaryTree(BinaryTree* InputBinaryTree, DataType InputData)
{
    if (InputBinaryTree == nullptr)
    {
        return nullptr;
    }

    if (InputData < InputBinaryTree->Data)
    {
        InputBinaryTree->Child_L = DeleteNodeFromCustomBinaryTree(InputBinaryTree->Child_L, InputData);
        return InputBinaryTree;
    }
    if (InputData > InputBinaryTree->Data)
    {
        InputBinaryTree->Child_R = DeleteNodeFromCustomBinaryTree(InputBinaryTree->Child_R, InputData);
        return InputBinaryTree;
    }

    //如果是叶节点，直接删除
    if (InputBinaryTree->Child_L == nullptr && InputBinaryTree->Child_R == nullptr)
    {
        return nullptr;
    }

    //如果是左子树有节点，右子树没有节点
    if (InputBinaryTree->Child_L != nullptr && InputBinaryTree->Child_R == nullptr)
    {
        return InputBinaryTree->Child_L;
    }

    //如果是右子树有节点，左子树没有节点
    if (InputBinaryTree->Child_R != nullptr && InputBinaryTree->Child_L == nullptr)
    {
        return InputBinaryTree->Child_R;
    }

    //如果是左右子树都有节点，那就去左子树最大的节点，或者右子树最小的节点，这里我们取左子树最大的节点
    if (InputBinaryTree->Child_L != nullptr && InputBinaryTree->Child_R != nullptr)
    {
        int MaxValue = FindMax(InputBinaryTree->Child_L);
        InputBinaryTree->Data = MaxValue;
        InputBinaryTree->Child_L = DeleteNodeFromCustomBinaryTree(InputBinaryTree->Child_L, MaxValue);
        return InputBinaryTree;
    }

    return nullptr;
}

BinaryNode* SearchNodeFromBinaryTree_Recursion(BinaryTree* InputBinaryTree, DataType CompareData)
{
    //方法1：递归
    if (InputBinaryTree == nullptr || CompareData == InputBinaryTree->Data)
    {
        return InputBinaryTree;
    }
    if (CompareData < InputBinaryTree->Data)
    {
        SearchNodeFromBinaryTree_Recursion(InputBinaryTree->Child_L, CompareData);
    }
    if (CompareData > InputBinaryTree->Data)
    {
        SearchNodeFromBinaryTree_Recursion(InputBinaryTree->Child_R, CompareData);
    }

    return nullptr;
}

BinaryNode* SearchNodeFromBinaryTree_Loop(BinaryTree* InputBinaryTree, DataType CompareData)
{
    //方法2：循环
    while (InputBinaryTree != nullptr)
    {
        if (CompareData < InputBinaryTree->Data)
        {
            InputBinaryTree = InputBinaryTree->Child_L;
            continue;
        }
        if (CompareData > InputBinaryTree->Data)
        {
            InputBinaryTree = InputBinaryTree->Child_R;
            continue;
        }
        if (CompareData == InputBinaryTree->Data)
        {
            return InputBinaryTree;
            break;
        }
    }

    return nullptr;
}

void PrintBinaryTree_For(BinaryTree* InputBinaryTree)
{
    if (InputBinaryTree == nullptr)
    {
        return;
    }
    cout << InputBinaryTree->Data << ' ';
    PrintBinaryTree_For(InputBinaryTree->Child_L);
    PrintBinaryTree_For(InputBinaryTree->Child_R);
}

void PrintBinaryTree_Middle(BinaryTree* InputBinaryTree)
{
    if (InputBinaryTree == nullptr)
    {
        return;
    }
    PrintBinaryTree_Middle(InputBinaryTree->Child_L);
    cout << InputBinaryTree->Data << ' ';
    PrintBinaryTree_Middle(InputBinaryTree->Child_R);
}

void PrintBinaryTree_Post(BinaryTree* InputBinaryTree)
{
    if (InputBinaryTree == nullptr)
    {
        return;
    }
    PrintBinaryTree_Post(InputBinaryTree->Child_L);
    PrintBinaryTree_Post(InputBinaryTree->Child_R);
    cout << InputBinaryTree->Data << ' ';
}

/*int main()
{
    //初始化二叉搜索树
    DataType InputArray[]{19, 7, 25, 5, 11, 21, 61, 15};
    BinaryNode* NewBinaryTree;
    if (!InitCustomBinaryTree(NewBinaryTree))
    {
        cout << "树初始化失败" << endl;
        return 0;
    }

    //添加元素到二叉搜索树中
    for (int i = 0; i < size(InputArray); i++)
    {
        BinaryNode* NewBinaryNode = new BinaryNode;
        NewBinaryNode->Data = InputArray[i];
        if (!InsertElementToCustomBinaryTree(NewBinaryTree, NewBinaryNode))
        {
            cout << "插入节点失败" << endl;
        }
    }

    //打印树
    PrintBinaryTree_Post(NewBinaryTree);
    cout << endl;

    /#1#/从树中删除节点
    DeleteNodeFromCustomBinaryTree(NewBinaryTree, 19);
    cout << endl;

    //打印树
    PrintBinaryTree_For(NewBinaryTree);
    cout << endl;

    //从树中查找元素
    BinaryNode* SearchedNode = nullptr;
    SearchedNode = SearchNodeFromBinaryTree_Loop(NewBinaryTree, 7);
    if (SearchedNode == nullptr)
    {
        cout << "未找到元素" << endl;
    }
    else
    {
        cout << "找到元素的值为:" << SearchedNode->Data << endl;
    }

    SearchedNode = SearchNodeFromBinaryTree_Loop(NewBinaryTree, 100);
    if (SearchedNode == nullptr)
    {
        cout << "未找到元素" << endl;
    }
    else
    {
        cout << "找到元素的值为:" << SearchedNode->Data << endl;
    }

    SearchedNode = SearchNodeFromBinaryTree_Loop(NewBinaryTree, 61);
    if (SearchedNode == nullptr)
    {
        cout << "未找到元素" << endl;
    }
    else
    {
        cout << "找到元素的值为:" << SearchedNode->Data << endl;
    }#1#

    //打印树
    //前序
    cout << "先序:" << endl;
    PrintBinaryTree_For(NewBinaryTree);
    cout << endl;
    //中序
    cout << "中序:" << endl;
    PrintBinaryTree_Middle(NewBinaryTree);
    cout << endl;
    //后序
    cout << "后序:" << endl;
    PrintBinaryTree_Post(NewBinaryTree);
    cout << endl;

    return 1;
}*/

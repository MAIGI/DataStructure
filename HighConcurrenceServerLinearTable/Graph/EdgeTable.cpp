/*
#include <iostream>
#include <queue>
using namespace std;

#define Max_Size 1024

bool Visited[Max_Size]{false};

typedef struct _NodeEdge
{
    int EdgeVertexNode; //邻接的顶点
    int Weight; //权重
    struct _NodeEdge* Next; //下一条边
} NodeEdge;

typedef struct _VertexNode
{
    char Data; //数据
    NodeEdge* FirstEdge; //第一条边
} VertexList, VertexNode;

typedef struct _EdgeGraph
{
    int NumberOfEdge; //边的数量
    int NumberOfNode; //顶点的数量
    VertexNode* NodeList; //顶点数组
} EdgeGraph;

static int FindLocation(EdgeGraph* InputEdgeGraph, char InputData)
{
    for (int i = 0; i < InputEdgeGraph->NumberOfNode; i++)
    {
        if (InputEdgeGraph->NodeList[i].Data == InputData)
        {
            return i;
        }
    }

    return -1;
}

bool InitGraph(EdgeGraph*& InputEdgeGraph)
{
    //创建图
    InputEdgeGraph = new EdgeGraph;
    if (InputEdgeGraph == nullptr)
    {
        return false;
    }
    InputEdgeGraph->NumberOfNode = 0;
    InputEdgeGraph->NumberOfEdge = 0;
    InputEdgeGraph->NodeList = nullptr;
    return true;
}

void DeepFirSearch_Single(EdgeGraph* InputEdgeGraph, int InputIndex)
{
    if (InputEdgeGraph == nullptr)
    {
        return;
    }
    if (Visited[InputIndex] == true)
    {
        return;
    }
    cout << InputEdgeGraph->NodeList[InputIndex].Data << ' ';
    Visited[InputIndex] = true;
    NodeEdge* TempNode = InputEdgeGraph->NodeList[InputIndex].FirstEdge;
    int NextEdge = -1;
    while (TempNode)
    {
        NextEdge = TempNode->EdgeVertexNode;
        if (Visited[NextEdge] == false)
        {
            DeepFirSearch_Single(InputEdgeGraph, NextEdge);
        }
        TempNode = TempNode->Next;
    }
}

void DeepFirstSearch_Main(EdgeGraph* InputEdgeGraph)
{
    if (InputEdgeGraph == nullptr)
    {
        return;
    }
    for (int i = 0; i < InputEdgeGraph->NumberOfNode; i++)
    {
        if (Visited[i] == false)
        {
            DeepFirSearch_Single(InputEdgeGraph, i);
        }
    }
}

void BreadthFirstSearch_Single(EdgeGraph* InputEdgeGraph, int InputIndex)
{
    if (InputEdgeGraph == nullptr)
    {
        return;
    }

    queue<int> NodeEdgeQueue;
    NodeEdgeQueue.push(InputIndex);
    int OutputIndex = -1;
    NodeEdge* TempEdge = InputEdgeGraph->NodeList[InputIndex].FirstEdge;
    while (!NodeEdgeQueue.empty())
    {
        OutputIndex = NodeEdgeQueue.front();
        if (Visited[OutputIndex] == false)
        {
            cout << InputEdgeGraph->NodeList[OutputIndex].Data << ' ';
            Visited[OutputIndex] = true;
            NodeEdgeQueue.pop();
        }
        while (TempEdge)
        {
            NodeEdgeQueue.push(TempEdge->EdgeVertexNode);
            TempEdge = TempEdge->Next;
        }
    }
}

void BreadthFirstSearch_Main(EdgeGraph* InputEdgeGraph)
{
    if (InputEdgeGraph == nullptr)
    {
        return;
    }
    for (int i = 0; i < InputEdgeGraph->NumberOfNode; i++)
    {
        if (Visited[i] == false)
        {
            BreadthFirstSearch_Single(InputEdgeGraph, i);
        }
    }
}

bool CreateGraph(EdgeGraph*& InputEdgeGraph)
{
    //用户输入节点
    cout << "请输入节点数和边数:";
    cin >> InputEdgeGraph->NumberOfNode >> InputEdgeGraph->NumberOfEdge;
    const int NumberOfNode = InputEdgeGraph->NumberOfNode;
    if (NumberOfNode > Max_Size)
    {
        cout << "超出最大节点数限制" << endl;
        return false;
    }
    InputEdgeGraph->NodeList = new VertexNode[NumberOfNode];
    if (InputEdgeGraph->NodeList == nullptr)
    {
        return false;
    }
    cout << "请输入节点数据:";
    for (int i = 0; i < NumberOfNode; i++)
    {
        cin >> InputEdgeGraph->NodeList[i].Data;
        InputEdgeGraph->NodeList[i].FirstEdge = nullptr;
    }

    //按照节点的关联度进行设置
    char Node1, Node2;
    int Index1, Index2;
    cout << "请输入临近的节点:" << endl;
    for (int i = 0; i < InputEdgeGraph->NumberOfEdge; i++)
    {
        cin >> Node1 >> Node2;
        Index1 = FindLocation(InputEdgeGraph, Node1);
        Index2 = FindLocation(InputEdgeGraph, Node2);
        if (Index1 != -1 && Index2 != -1)
        {
            NodeEdge* NewNodeEdge = new NodeEdge;
            if (NewNodeEdge == nullptr)
            {
                return false;
            }
            NewNodeEdge->EdgeVertexNode = Index2;
            NewNodeEdge->Next = InputEdgeGraph->NodeList[Index1].FirstEdge;
            InputEdgeGraph->NodeList[Index1].FirstEdge = NewNodeEdge;
        }
    }
    return true;
}


int main()
{
    //初始化图
    EdgeGraph* NewEdgeGraph = nullptr;
    if (!InitGraph(NewEdgeGraph))
    {
        cout << "初始化图失败" << endl;
    }

    //创建图
    CreateGraph(NewEdgeGraph);

    //遍历图(深度遍历)
    //DeepFirstSearch_Main(NewEdgeGraph);

    //遍历图(广度遍历)
    BreadthFirstSearch_Main(NewEdgeGraph);

    return 0;
}
*/

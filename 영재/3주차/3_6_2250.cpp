// 매우 오래 걸린 문제.  +++ 입력이 루트노드부터 순차적으로 들어올 것이라 안일하게 생각하여 푸는데 시간이 더 걸림.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이방법(쓸데없이 복잡한 방법) : 
//입력을 받고 -> 1.이진트리를 구성함 -> 2.각 노드별로 left child num, right child num을 구함. 
// 3.루트부터 왼쪽, 오른쪽 자식노드 갯수를 통해 자신의 위치를 결정.
// 4.이후 레벨별로 너비를 구함.

struct node
{
    int parent;
    int index;
    int left;
    int right;
};

void findMyCol(int left, int right, int index);
int findChildNum(node startNode);
int* levelList;
int* leftNumList;
int* rightNumList;
node* nodeList;
int rootNodeIndex;


vector<vector<int> > level;

int main()
{
    int nodeNum;
    cin >> nodeNum;
    levelList = new int[nodeNum]();
    leftNumList = new int[nodeNum]();
    rightNumList = new int[nodeNum]();
    nodeList = new node[nodeNum];

    for(int i = 0; i < nodeNum; i++)
    {
        node tmpNode = {-1, -1, -1, -1};
        nodeList[i] = tmpNode;
        vector<int> tmp;
        level.push_back(tmp);
    }

    // 1.
    for(int i = 0; i < nodeNum; i++)
    {
        int root, left, right;
        cin >> root >> left >> right;

        if(nodeList[root-1].index == -1)
        {
            nodeList[root-1].index = root - 1;
        }

        if(left != -1)
        {
            nodeList[left-1].parent = root-1;
            nodeList[left-1].index = left-1;
            nodeList[root-1].left = left - 1;
        }
        
        if(right != -1)
        {
            nodeList[right-1].parent = root-1;
            nodeList[right-1].index = right-1;
            nodeList[root-1].right = right - 1;
        }

    }

    // 루트 노트 찾기
    for(int i = 0; i < nodeNum; i++)
    {
        if(nodeList[i].parent == -1)
        {
            rootNodeIndex = i;
            break;
        }
    }

    levelList[rootNodeIndex] = 0;

    // 2.
    findChildNum(nodeList[rootNodeIndex]);

    // 3.
    findMyCol(0, nodeNum - 1, rootNodeIndex);

    int maxNum = 0;
    int levelIndex = 0;

    // 4.
    for(int i = 0; i < nodeNum; i++)
    {
        if(level[i].empty())
        {
            break;
        }
        else
        {
            sort(level[i].begin(), level[i].end());
            int dif = abs(level[i].front() - level[i].back()) + 1;
            if(maxNum < dif)
            {
                maxNum = dif;
                levelIndex = i;
            }
        }
        
    }

    cout << levelIndex+1 << " " << maxNum;

    return 0;
}

int findChildNum(node startNode)
{
    int leftNum, rightNum;
    if(startNode.index != rootNodeIndex)
    {
        levelList[startNode.index] = levelList[startNode.parent] + 1;
    }

    if(startNode.left != -1)
    {
        leftNum = findChildNum(nodeList[startNode.left]);
    }
    else
    {
        leftNum = 0;
    }
    
    if(startNode.right != -1)
    {
        rightNum = findChildNum(nodeList[startNode.right]);
    }
    else
    {
        rightNum = 0;
    }

    leftNumList[startNode.index] = leftNum;
    rightNumList[startNode.index] = rightNum;

    return leftNum + rightNum + 1;
    
}

void findMyCol(int left, int right, int index)
{
    int leftNum = leftNumList[index];

    int myCol = left + leftNum;

    level[levelList[index]].push_back(myCol);

    if(nodeList[index].left != -1)
    {
        findMyCol(left, myCol-1, nodeList[index].left);
    }
    if(nodeList[index].right != -1)
    {
        findMyCol(myCol + 1, right, nodeList[index].right);
    }
}
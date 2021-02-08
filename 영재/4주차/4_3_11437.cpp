#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool* visitNode;
vector<vector<int> > nodeList;
vector<pair<int, int> > problemList;
vector<int> answer;
int* levelList;
int* rootList;

void findEqualParent(queue<int> q);
void fillLevel(int level, queue<int> q);

int main()
{
    int nodeNum;
    cin >> nodeNum;

    
    visitNode = new bool[nodeNum+1]();
    levelList = new int[nodeNum+1]();
    rootList = new int[nodeNum+1]();

    for(int i = 0; i <= nodeNum; i++)
    {
        vector<int> tmpNode;
        nodeList.push_back(tmpNode);
    }

    for(int i = 0; i < nodeNum - 1; i++)
    {
        int front, back;
        cin >> front >> back;
        nodeList[front].push_back(back);
        nodeList[back].push_back(front);
    }

    int times;
    cin >> times;
    for(int i = 0; i < times; i++)
    {
        int front, back;
        cin >> front >> back;
        problemList.push_back(make_pair(front, back));
    }

    // 레벨 측정 및 parent 노드를 찾기 위한 준비.
    queue<int> startQ;
    visitNode[1] = true;
    for(int i = 0; i < nodeList[1].size(); i++)
    {
        startQ.push(nodeList[1][i]);
        rootList[nodeList[1][i]] = 1;
        visitNode[nodeList[1][i]] = true;
    }
    fillLevel(1, startQ);



    for(int i = 0; i < times; i++)
    {
        fill(visitNode, visitNode + nodeNum+1, false);
        queue<int> q;
        int first, second;
        first = problemList[i].first;
        second = problemList[i].second;

        // 매우 중요한 작업. 둘의 레벨이 차이 날경우 같은 레벨로 맞춰주고 조상찾기 시작.
        // 이 작업을 안해주면 94%에서 시간초과 발생.
        while(levelList[first] != levelList[second])
        {
            if(levelList[first] < levelList[second])
            {
                visitNode[second] = true;
                second = rootList[second];
            }
            else
            {
                visitNode[first] = true;
                first = rootList[first];
            }        
        }

        q.push(first);
        q.push(second);
        findEqualParent(q);
    }

    for(int i = 0; i < times; i++)
    {
        cout << answer[i] << "\n";
    }

}

// 두 노드가 위로 올라가면서 공통 조상이 나올때 까지 조사.
void findEqualParent(queue<int> q)
{
    queue<int> nextQ;
    while(!q.empty())
    {
        int nowNode;
        nowNode = q.front();

        q.pop();

        if(visitNode[nowNode] == true)
        {
            answer.push_back(nowNode);
            return;
        }
        else
        {
            visitNode[nowNode] = true;
            if(rootList[nowNode] != 0)
            {
                nextQ.push(rootList[nowNode]);
            }
        }
    }
    findEqualParent(nextQ);
}

// 각 노드의 레벨(깊이)를 기록하고 parentNode를 찾는다.
void fillLevel(int level, queue<int> q)
{
    queue<int> nextQ;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        levelList[node] = level;

        for(int i = 0; i < nodeList[node].size(); i++)
        {
            if(visitNode[nodeList[node][i]] == true)
            {
                continue;
            }
            else
            {
                rootList[nodeList[node][i]] = node;
                visitNode[nodeList[node][i]] = true;
                nextQ.push(nodeList[node][i]);
            }
        }
    }
    if(!nextQ.empty())
    {
        fillLevel(level+1, nextQ);
    }
}
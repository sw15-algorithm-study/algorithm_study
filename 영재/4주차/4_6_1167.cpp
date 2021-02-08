// * 풀이 방법 *
// 특정 정점A로 부터 가장 먼 노드 B를 찾는다.
// 노드 B로 부터 가장 먼 노드 C를 찾으면 B-C의 거리가 트리의 지름.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool* visitNode;
int maxDist;
int lastNode;
vector<vector<pair<int,int> > > childList;

void dfs(int node, int nowDist);

int main()
{
    int nodeNum;
    cin >> nodeNum;

    visitNode = new bool[nodeNum+1]();
    for(int i = 0; i <= nodeNum; i++)
    {
        visitNode[i] = false;
        vector<pair<int,int> > tmpVector;
        childList.push_back(tmpVector);
    }

    int root = 0;

    for(int i = 1; i <= nodeNum; i++)
    {
        int nodeIndex;
        cin >> nodeIndex;

        int child, dist;
        while(true)
        {
            cin >> child;
            if(child == -1)
            {
                break;
            }
            cin >> dist;
            childList[nodeIndex].push_back(make_pair(child, dist));
        }
    }

    // 1번 노드랑 가장 먼 노드 찾기
    visitNode[1] = true;
    maxDist = 0;
    // 가장 먼 노드 = lastNode
    lastNode = 0;
    for(int i = 0; i < childList[1].size(); i++)
    {
        if(maxDist < childList[1][i].second)
        {
            maxDist = childList[1][i].second;
            lastNode = childList[1][i].first;
        }
        visitNode[childList[1][i].first] = true;
        dfs(childList[1][i].first, childList[1][i].second);
    }

    // lastNode로 부터 제일 먼 거리 측정
    for(int i = 0; i <= nodeNum; i++)
    {
        visitNode[i] = false;
    }
    root = lastNode;
    visitNode[root] = true;
    for(int i = 0; i < childList[root].size(); i++)
    {
        if(maxDist < childList[root][i].second)
        {
            maxDist = childList[root][i].second;
        }
        visitNode[childList[root][i].first] = true;
        dfs(childList[root][i].first, childList[root][i].second);
    }

    cout << maxDist;
}

void dfs(int node, int nowDist)
{
    for(int i = 0; i < childList[node].size(); i++)
    {
        int nextNode = childList[node][i].first;
        if(!visitNode[nextNode])
        {
            visitNode[nextNode] = true;
            if(maxDist < nowDist + childList[node][i].second)
            {
                lastNode = nextNode;
                maxDist = nowDist + childList[node][i].second;
            }
            dfs(nextNode, nowDist + childList[node][i].second);
        }
    }
}
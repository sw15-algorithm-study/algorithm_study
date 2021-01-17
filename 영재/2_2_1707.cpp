#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool BFS(int c, int node);

vector<vector<vector<int> > > caseList;
int** visitedNode;

int main()
{
    int caseNum = 0;

    cin >> caseNum;

    visitedNode = new int*[caseNum]();

    for(int i = 0; i < caseNum; i++)
    {
        vector<vector<int> > list;
        caseList.push_back(list);
        int v = 0, e = 0;
        int x, y;
        cin >> v >> e;
        
        visitedNode[i] = new int[v+1]();
        
        for(int j = 0; j < v+1; j++)
        {
            vector<int> node;
            caseList[i].push_back(node);
        }

        for(int k = 0; k < e; k++)
        {
            cin >> x >> y;
            caseList[i][x].push_back(y);
            caseList[i][y].push_back(x);
        }

    }

    for(int c = 0; c < caseNum; c++)
    {
        bool result;
        result = BFS(c, 1);

        for(int k = 1; k < caseList[c].size(); k++)
        {
            if(!result)
            {
                break;
            }
            else if(visitedNode[c][k] == 0)
            {
                result = BFS(c, k);
            }
        }

        if(result)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        
    }

}

bool BFS(int c, int node)
{
    queue<pair<int,int> > visitQueue;
    bool isBipartite = true;

    visitQueue.push(make_pair(node,0));
    visitedNode[c][node] = 1;

    while (!visitQueue.empty())
    {
        int nowNode = visitQueue.front().first;
        int preNode = visitQueue.front().second;

        visitQueue.pop();

        for(int i = 0; i < caseList[c][nowNode].size(); i++)
        {
            int nextNode = caseList[c][nowNode][i];
            if(nextNode == preNode)
            {
                continue;
            }
            else
            {
                if(visitedNode[c][nextNode] == 0)
                {
                    visitedNode[c][nextNode] = visitedNode[c][nowNode] * -1;
                    visitQueue.push(make_pair(nextNode, nowNode));
                }
                else
                {
                    if(visitedNode[c][nextNode] == visitedNode[c][nowNode])
                    {
                        isBipartite = false;
                        return isBipartite;
                    }
                }
            }
            
        }
    }
    return isBipartite;
}

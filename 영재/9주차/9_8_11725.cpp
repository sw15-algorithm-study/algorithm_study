#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int nodeNum;
    cin >> nodeNum;

    vector<vector<int> > nodes;
    queue<int> q;
    int* parent = new int[nodeNum+1]();

    for(int i = 0; i <= nodeNum; i++)
    {
        vector<int> tmpVector;
        nodes.push_back(tmpVector);
    }

    for(int i = 0; i < nodeNum - 1; i++)
    {
        int front, back;
        cin >> front >> back;
        nodes[front].push_back(back);
        nodes[back].push_back(front);
    }

    parent[1] = -1;
    q.push(1);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int i = 0; i < nodes[node].size(); i++)
        {
            int childNode = nodes[node][i];
            if(parent[childNode] == 0)
            {
                parent[childNode] = node;
                q.push(childNode);
            }
        }
    }

    for(int i = 2; i <= nodeNum; i++)
    {
        cout << parent[i] << "\n";
    }
}
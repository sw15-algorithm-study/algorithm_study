#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

int v;
bool visited[100001];
vector<pair<int, int>> graph[100001];

int diameter = 0;
int farthestNode = 0;

void DFS(int node, int cost)
{
        if (visited[node])
                 return;
        visited[node] = true;
        if (diameter < cost){
            diameter = cost;
            farthestNode = node;
        }
        for (int i = 0; i < graph[node].size(); i++)
            DFS(graph[node][i].first, cost + graph[node][i].second);
}

int main(void)
{
    scanf("%d", &v);
    for (int i = 0; i < v; i++){
        int node;
        scanf("%d", &node);
        while (1){
            int node2, cost;
            scanf("%d", &node2);
            if (node2 == -1)
                break;
            scanf("%d", &cost);
            graph[node].push_back({ node2, cost });
        }
    }
    memset(visited, false, sizeof(visited));
    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    diameter = 0;
    DFS(farthestNode, 0);
    printf("%d", diameter);
    return 0;
}
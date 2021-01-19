#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, tmp1, tmp2;
vector<int> graph[32001];
int check[32001] = {0};
queue<int> q;

void bfs(){
    for(int i = 1; i <= n; i++)
        if(check[i] == 0)
            q.push(i);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        printf("%d ", a);
        for(int i = 0; i < graph[a].size(); i++){
            check[graph[a][i]]--;
            if(check[graph[a][i]] == 0)             //앞에 와야될 숫자가 없으면
                q.push(graph[a][i]);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &tmp1, &tmp2);
        graph[tmp1].push_back(tmp2);
        check[tmp2]++;                              //앞에 와야할 숫자의 갯수
    }
    bfs();
}
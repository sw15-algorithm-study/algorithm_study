#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> tree(100001);
vector<bool> visited(100001, false);
vector<int> parent(100001, 0);

void dfs(int start){
    for(int i = 0; i < tree[start].size(); i++){
        //루트부터 시작하여 자식 노드들 탐색
        int target = tree[start][i];
        
        //만약 자식 노드를 방문하지 않았다면 dfs 탐색
        if(!visited[target]){
            visited[target] = true;
            parent[target] = start;
            dfs(target);
        }
    }
}

int main(void){
    cin >> N;

    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    //루트가 1이기 때문에 루트부터 시작
    dfs(1);

    for(int i = 2; i <= N; i++){
        cout << parent[i] << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//노드 정보
vector<vector<int>> node(50001);
//부모 노드의 정보
vector<int> parent(50001);
//각 노드의 깊이
vector<int> depth(50001);
// 각 노드의 방문 여부
vector<bool> visited(50001);


//각 노드의 depth 구하기
void dfs(int start, int dpt){
    visited[start] = true;
    depth[start] = dpt;

    for(int i = 0; i < node[start].size(); i++){
        if(visited[node[start][i]]){
            continue;
        }
        parent[node[start][i]] = start;
        dfs(node[start][i], dpt + 1);
    }
}

//LCA 찾기
int lca(int a, int b){
    //a와 b의 depth가 같을 때까지 노드 이동
    while(depth[a] != depth[b]){
        if(depth[a] > depth[b]){
            a = parent[a];
        }
        else{
            b = parent[b];
        }
    }

    //동일한 depth에서 공통 조상 찾기
    while(a != b){
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main(void){
    int N, M;

    cin >> N;

    for(int i = 1; i < N; i++){
        int n1, n2;
        cin >> n1 >> n2;
        
        node[n1].push_back(n2);
        node[n2].push_back(n1);
    }

    //루트는 1이기 때문에 1부터 시작하여 각 노드의 depth 구하기
    dfs(1, 0);

    cin >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}
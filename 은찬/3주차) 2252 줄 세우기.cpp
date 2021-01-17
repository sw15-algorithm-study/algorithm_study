#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(void){
    int N, M;
    queue<int> q;
    vector<int> answer;

    cin >> N >> M;

    //위상을 나타내는 v 벡터
    vector<int> v(N + 1, 0);
    //그래프를 그리는 graph 벡터
    vector<vector<int>> graph(N + 1);
    //방문 여부를 나타내는 visited 벡터
    vector<bool> visited(N + 1, false);

    //그래프 그리면서 위상 변경하기
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        v[b]++;
        graph[a].push_back(b);
    }

    //위상이 0인 정점 큐에 넣기
    for(int i = 1; i <= N; i++){
        if(v[i] == 0){
            q.push(i);
        }
    }

    //큐를 확인하면서 
    for(int i = 1; i <= N; i++){
        int tmp = q.front();
        q.pop();
        answer.push_back(tmp);

        for(int j = 0; j < graph[tmp].size(); j++){
            int edge = graph[tmp][j];

            if(--v[edge] == 0){
                q.push(edge);
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }
    return 0;
}
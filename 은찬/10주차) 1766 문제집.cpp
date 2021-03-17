#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    //위상정렬 이용
    int N, M;
    //작은 수가 먼저 앞에 나와야하므로 greater<int> 사용
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> answer;

    cin >> N >> M;

    //위상과 그래프
    vector<int> topology(N + 1, 0);
    vector<vector<int>> graph(N + 1);

    for(int i = 0; i < M; i++){
        //위상이 0인 문제를 먼저 풀어야 한다.
        //먼저 풀어야 하는 문제 = a,
        //a를 풀고 풀어야 하는 문제 = b
        //b의 위상을 올려주고, graph[a]에 b 문제를 넣어서 순서를 정해준다.
        int a, b;

        cin >> a >> b;
        topology[b]++;
        graph[a].push_back(b);
    }

    //위상이 0인 문제부터 큐에 넣기
    for(int i = 1; i <= N; i++){
        if(topology[i] == 0){
            pq.push(i);
        }
    }

    for(int i = 1; i <= N; i++){
        //주어진 조건대로 문제 풀기
        int tmp = pq.top();
        answer.push_back(tmp);
        pq.pop();

        //우선순위큐이기 때문에 작은 수가 먼저 앞에 오게된다.
        //위상을 확인하면서 순서를 정하면 된다.
        for(int j = 0; j < graph[tmp].size(); j++){
            int node = graph[tmp][j];

            if(--topology[node] == 0){
                pq.push(node);
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }

    return 0;
}
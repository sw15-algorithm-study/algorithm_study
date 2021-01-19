#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(void){
    int N, M;
    queue<int> q;
    vector<int> answer;

    cin >> N >> M;

    vector<int> v(N + 1, 0);
    vector<vector<int>> graph(N + 1);

    //순서 입력 받기
    for(int i = 0; i < M; i++){
        int t;
        vector<int> list;
        cin >> t;

        for(int j = 0; j < t; j++){
            int s;
            cin >> s;
            list.push_back(s);
        }

        for(int j = 0; j < t; j++){
            for(int k = j + 1; k < t; k++){
                v[list[k]]++;
                graph[list[j]].push_back(list[k]);
            }
        }
    }

    //위상이 0인 번호 큐에 넣기
    for(int i = 1; i <= N; i++){
        if(v[i] == 0){
            q.push(i);
        }
    }

    //그래프를 돌면서 순서 정렬하기
    while(!q.empty()){
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

    //답이 나오지 않은 경우 0 출력
    //아니면 순서 출력
    if(answer.size() != N){
        cout << 0 << endl;
    }
    else{
        for(int i = 0; i < N; i++){
            cout << answer[i] << endl;
        }
    }

    return 0;
}
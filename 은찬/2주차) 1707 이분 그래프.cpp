#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    int K, V, E;

    cin >> K;

    for(int i = 0; i < K; i++){
        cin >> V >> E;
        
        vector<int> visited(V + 1, 0);
        vector<int> graph[V + 1];
        bool check = false;

        for(int j = 0; j < E; j++){
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(int j = 1; j <= V; j++){
            if(visited[j] == 0){
                queue<int> q;
                int color = 1;

                visited[j] = 1;
                q.push(j);

                while(!q.empty()){
                    int current = q.front();
                    q.pop();

                    if(visited[current] == 1){
                        color = 2;
                    }
                    else if(visited[current] == 2){
                        color = 1;
                    }

                    for(int k = 0; k < graph[current].size(); k++){
                        int next = graph[current][k];
                        if(visited[next] == 0){
                            visited[next] = color;
                            q.push(next);
                        }
                    }
                }
            }
        }

        for(int j = 1; j <= V; j++){
            for(int k = 0; k < graph[j].size(); k++){
                int next = graph[j][k];
                if(visited[j] == visited[next]){
                    check = true;
                    break;
                }
            }

            if(check){
                break;
            }
        }

        if(!check){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
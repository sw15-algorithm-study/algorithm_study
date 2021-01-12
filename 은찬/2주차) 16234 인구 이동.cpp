#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> tmp;
queue<pair<int, int>> q;
int N, L, R;
int arr[50][50];
int border_x[4] = {-1, 1, 0, 0};
int border_y[4] = {0, 0, -1, 1};

void dfs(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N){
        return;
    }

    for(int i = 0; i < 4; i++){
        if(x + border_x[i] >= 0 && x + border_x[i] < N && y + border_y[i] >= 0 && y + border_y[i] < N && !tmp[x + border_x[i]][y + border_y[i]]){
            int diff = abs(arr[x][y] - arr[x + border_x[i]][y + border_y[i]]);
            if(diff >= L && diff <= R){
                q.push(make_pair(x + border_x[i], y + border_y[i]));
                tmp[x + border_x[i]][y + border_y[i]] = true;
                dfs(x + border_x[i], y + border_y[i]);
            }
        }
    }
}

void bfs(){
    while(!q.empty()){
        int sum = 0;
        int size = q.size();
        vector<pair<int, int>> v;

        for(int i = 0; i < size; i++){    
            int x = q.front().first;
            int y = q.front().second;

            v.push_back(make_pair(x, y));
            q.pop();

            sum += arr[x][y];
        }
        sum /= size;

        for(int i = 0; i < size; i++){
            arr[v[i].first][v[i].second] = sum;
        }
    }
}

int main(void){
    int answer = 0;
    vector<vector<bool>> visited(50, vector<bool>(50, false));


    cin >> N >> L >> R;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    while(1){
        bool check = false;
        tmp = visited;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!tmp[i][j]){
                    tmp[i][j] = true;
                    q.push(make_pair(i, j));
                    dfs(i, j);

                    if(q.size() == 1){
                        q.pop();
                    }
                    else{
                        bfs();
                        check = true;
                    }
                }
            }
        }

        if(!check){
            break;
        }
        else{
            answer++;
        }
    }
    
    cout << answer;
    return 0;
}
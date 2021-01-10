#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
int N = 0;
int M = 0;
int answer = 9999;
int max_virus = 0;
bool check[10] = {false, };
int arr[10] = {0, };
int board[50][50];
vector<vector<bool>> visited(50, vector<bool>(50, false));
vector<int> combination;
vector<pair<int, int>> v;

void dfs(int, int);
void bfs();

void dfs(int start, int count){
    if(count == M){
        for(int i = 0; i < M; i++){
            combination.push_back(arr[i]);
        }
        bfs();
        return;
    }

    for(int i = start; i < cnt; i++){
        if(!check[i]){
            check[i] = true;
            arr[count] = i;
            dfs(i + 1, count + 1);
            check[i] = false;
        }
    }
}

void bfs(){
    queue<pair<int, int>> q;
    vector<vector<bool>> tmp = visited;
    int time = -1, virus = 0;

    for(int i = 0; i < M; i++){
        q.push(v[arr[i]]);
        tmp[v[arr[i]].first][v[arr[i]].second] = true;
        virus++;
    }

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
            if(x - 1 >= 0 && !tmp[x - 1][y]){
                q.push(make_pair(x - 1, y));
                tmp[x - 1][y] = true;
                virus++;
            }
            if(y + 1 < N && !tmp[x][y + 1]){
                q.push(make_pair(x, y + 1));
                tmp[x][y + 1] = true;
                virus++;
            }
            if(x + 1 < N && !tmp[x + 1][y]){
                q.push(make_pair(x + 1, y));
                tmp[x + 1][y] = true;
                virus++;
            }
            if(y - 1 >= 0 && !tmp[x][y - 1]){
                q.push(make_pair(x, y - 1));
                tmp[x][y - 1] = true;
                virus++;
            }
        }
        time++;
    }
    
    if(virus == max_virus){
        answer = answer < time ? answer : time;
    }
}

int main(void){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];

            if(board[i][j] != 1){
                if(board[i][j] == 2){
                cnt++;
                v.push_back(make_pair(i, j));
                }
                max_virus++;
            }
            else{
                visited[i][j] = true;
            }
        }
    }

    dfs(0, 0);

	if(answer == 9999){
		cout << -1;
	}
	else{
		cout << answer;	
	}
    return 0;
}
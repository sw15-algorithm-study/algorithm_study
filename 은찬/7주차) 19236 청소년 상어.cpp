#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//중앙과 8방향 (중앙 = 0, 0)
int direct_x[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int direct_y[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int ans = 0;

void swap(vector<vector<int>> &v, int x, int y, int target_x, int target_y){
    int val = v[x][y];
    v[x][y] = v[target_x][target_y];
    v[target_x][target_y] = val;
}

void move(vector<vector<int>> &tmp_board, vector<vector<int>> &tmp_direct, vector<vector<int>> &tmp_check, map<int, pair<int, int>> &tmp_fishes){
    //물고기들을 각자의 진행방향으로 이동.
    //빈칸이 있거나 물고기가 있는 경우 서로 바꿔준다.
    for(int i = 1; i <= 16; i++){
        //i번의 물고기가 -1, -1이라면 잡아 먹힌 경우
        if(tmp_fishes[i].first == -1 && tmp_fishes[i].second == -1){
            continue;
        }
        int fish_x = tmp_fishes[i].first;
        int fish_y = tmp_fishes[i].second;
        int &fish_dir = tmp_direct[fish_x][fish_y];

        for(int j = 0; j < 7; j++){
            if(fish_dir == 0 || fish_dir == 9){
                fish_dir = 1;
            }

            int target_x = fish_x + direct_x[fish_dir];
            int target_y = fish_y + direct_y[fish_dir];

            // 물고기가 이동할 수 있는지 검사하여 이동시키기
            if(target_x >= 0 && target_x < 4 && target_y >= 0 && target_y < 4 && tmp_check[target_x][target_y] != -1 && tmp_board[target_x][target_y] != -1){
                if(tmp_check[target_x][target_y]){
                    tmp_fishes[tmp_board[target_x][target_y]] = make_pair(fish_x, fish_y);
                }
                tmp_fishes[i] = make_pair(target_x, target_y);
                
                swap(tmp_board, fish_x, fish_y, target_x, target_y);
                swap(tmp_direct, fish_x, fish_y, target_x, target_y);
                swap(tmp_check, fish_x, fish_y, target_x, target_y);
                
                break;
            }
            else{
                fish_dir++;
            }
        }
    }
}

void dfs(int shark_x, int shark_y, int sum, vector<vector<int>> tmp_board, vector<vector<int>> tmp_direct, vector<vector<int>> tmp_check, map<int, pair<int, int>> tmp_fishes){
    int dir = tmp_direct[shark_x][shark_y];
    int x = shark_x;
    int y = shark_y;
    
    //상어가 물고기를 잡아먹은 후 물고기들이 이동.
    //잡아먹은 물고기는 (-1, -1)로 초기화 하여 움직이지 않도록 한다.
    sum += tmp_board[shark_x][shark_y];
    tmp_fishes[tmp_board[shark_x][shark_y]].first = -1;
    tmp_fishes[tmp_board[shark_x][shark_y]].second = -1;
    tmp_board[shark_x][shark_y] = -1;
    tmp_direct[shark_x][shark_y] = 0;
    tmp_check[shark_x][shark_y] = -1;
    move(tmp_board, tmp_direct, tmp_check, tmp_fishes);
	
    //상어는 최대 3번 이동할 수 있다.
    //상어가 잡아먹은 물고기의 방향으로 이동 가능한지 검사한다.
    //만약 빈칸이 있다면, 빈칸을 넘어 다음 칸으로 이동 가능한지 검사하여 DFS 진행.
    for(int i = 0; i < 3; i++){
        shark_x += direct_x[dir];
        shark_y += direct_y[dir];

        if(shark_x >= 0 && shark_x < 4 && shark_y >= 0 && shark_y < 4){
            if(tmp_board[shark_x][shark_y] == 0){
                continue;
            }
            tmp_board[x][y] = 0;
            tmp_check[x][y] = 0;
            dfs(shark_x , shark_y, sum, tmp_board, tmp_direct, tmp_check, tmp_fishes);
            tmp_board[x][y] = -1;
            tmp_check[x][y] = -1;
        }
        else{
            break;
        }
    }

    ans = ans < sum ? sum : ans;
}

int main(void){
    vector<vector<int>> board(4, vector<int>(4, 0));
    vector<vector<int>> direct(4, vector<int>(4, 0));
    vector<vector<int>> check(4, vector<int>(4, 1));
    map<int, pair<int, int>> fishes;

    // 물고기 번호와 방향 초기화
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int a, b;
            cin >> a >> b;
            board[i][j] = a;
            direct[i][j] = b;
            fishes[a] = make_pair(i, j);
        }
    }

    dfs(0, 0, 0, board, direct, check, fishes);

    cout << ans;

    return 0;
}
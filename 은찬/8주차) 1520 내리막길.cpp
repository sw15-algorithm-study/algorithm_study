#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int M, N;
vector<vector<int>> board(501, vector<int>(501, 0));
vector<vector<int>> dp(501, vector<int>(501, -1));
int direct_x[4] = {-1, 1, 0, 0};
int direct_y[4] = {0, 0, -1, 1};

int dfs(int x, int y){
    if(x == M -1 && y == N - 1){
        return 1;
    }

    if(dp[x][y] == -1){
        dp[x][y] = 0;
        
        for(int i = 0; i < 4; i++){
            int target_x = x + direct_x[i];
            int target_y = y + direct_y[i];

            if(target_x >= 0 && target_x < M && target_y >= 0 && target_y < N){
                if(board[x][y] > board[target_x][target_y]){
                    dp[x][y] += dfs(target_x, target_y);
                }
            }
        }
    }    
    
    return dp[x][y];
}

int main(void){
    cin >> M >> N;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    cout << dfs(0, 0);

    return 0;
}
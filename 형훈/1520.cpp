#include <iostream>

using namespace std;

int m, n, h = 0;
int map[501][501];
int dp[501][501] = {0,};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int dfs(int y, int x){
    if(y == m-1 && x == n-1)        //도착지점 도달하면
        return 1;
    if(dp[y][x] != -1)              //한번도 안가본 길 이면
        return dp[y][x];
    dp[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(0 <= yy && yy < m && 0 <= xx && xx < n)
            if(map[y][x] > map[yy][xx])
                dp[y][x] += dfs(yy, xx);
    }
    return dp[y][x];
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;
        }
    printf("%d", dfs(0,0));
}
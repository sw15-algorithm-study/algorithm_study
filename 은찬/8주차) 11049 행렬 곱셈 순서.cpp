#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main(void){
    int N;

    cin >> N;

    vector<pair<int, int>> arr(N + 1);
    vector<vector<pair<pair<int, int>, int>>> dp(N + 1, vector<pair<pair<int, int>, int>>(N + 1));

    for(int i = 1; i <= N; i++){
        int r, c;
        
        cin >> r >> c;
        arr[i] = make_pair(r, c);
    }

    //각 부분마다 최소값을 저장
    for(int i = 1; i < N; i++){
        for(int x = 1; x + i <= N; x++){
            int y = x + i;
            dp[x][y].second = INT_MAX;

            for(int j = x; j < y; j++){
                dp[x][y].second = min(dp[x][y].second, dp[x][j].second + dp[j + 1][y].second + arr[x].first * arr[j].second * arr[y].second);
            }
        }
    }
    
    cout << dp[1][N].second << endl;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(void){
    int N, ans = 0;

    cin >> N;

    vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, INT_MIN));

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> v[i][j];
        }
    }

    dp[1][1] = v[1][1];

    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1){
                dp[i][j] = dp[i - 1][j] + v[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i - 1][j - 1] + v[i][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j - 1] + v[i][j], dp[i - 1][j] + v[i][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        ans = max(ans, dp[N][i]);
    }

    cout << ans;
    
    return 0;
}
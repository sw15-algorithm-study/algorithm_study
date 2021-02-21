#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(void){
    int T, ans = 0;

    cin >> T;

    for(int t = 0; t < T; t++){
        int K;
        cin >> K;
    
        vector<vector<int>> dp(K + 1, vector<int>(K + 1, 0));
        vector<int> cost(K + 1, 0);
        vector<int> sum(K + 1, 0);

        for(int i = 1; i <= K; i++){
            cin >> cost[i];
            //1 ~ i까지의 부분합
            sum[i] = sum[i - 1] + cost[i];
        }

        for(int i = 1; i < K; i++){
            for(int x = 1; x + i <= K; x++){
                int y = x + i;
                dp[x][y] = INT_MAX;
                
                for(int j = x; j < y; j++){
                    dp[x][y] = min(dp[x][y], dp[x][j] + dp[j + 1][y] + sum[y] - sum[x - 1]);
                }
            }
        }

        cout << dp[1][K] << endl;
    }
    
    return 0;
}
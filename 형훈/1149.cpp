#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000][3] = {0};

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
    for(int i = 1; i < n; i++){
        dp[i][0] = min(dp[i][0] + dp[i-1][1], dp[i][0] + dp[i-1][2]);
        dp[i][1] = min(dp[i][1] + dp[i-1][0], dp[i][1] + dp[i-1][2]);
        dp[i][2] = min(dp[i][2] + dp[i-1][0], dp[i][2] + dp[i-1][1]);
    }
    printf("%d", min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}));
    return 0;
}
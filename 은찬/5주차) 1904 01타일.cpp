#include <iostream>

using namespace std;

long long int dp[1000001];

int main(void){
    int N;
	long long int ans = 0;
	
    cin >> N;
    
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
	
	ans = dp[N] % 15746;
	
    cout << ans;

    return 0;
}
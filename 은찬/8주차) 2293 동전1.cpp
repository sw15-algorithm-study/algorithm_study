#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, k, ans = 0;
    vector<int> coin;
    vector<int> dp(10001, 0);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        
        //k원 이하인 동전만 수집
        if(tmp <= k){
            coin.push_back(tmp);
        }
    }

    dp[0] = 1;

    for(int i = 0; i < coin.size(); i++){
        for(int j = coin[i]; j <= k; j++){
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[k];

    return 0;
}
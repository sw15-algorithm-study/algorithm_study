#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(void){
    int N, ans = 0;

    cin >> N;

    vector<vector<int>> house(N, vector<int>(3, 0));
    vector<vector<int>> dp(N, vector<int>(3, INT_MAX));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> house[i][j];
        }
    }

    //dp 테이블의 0번째 값을 house의 0번째 값으로 대입
    dp[0] = house[0];

    //현재 집과 이전, 다음 집의 색이 같지 않은 경우는 각 집의 인덱스가 같지 않다는 뜻.
    //그 경우를 제외하고 더 작은 비용을 저장.
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j != k){
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + house[i][j]);
                }
            }
        }
    }

    ans = min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
    cout << ans;
    
    return 0;
}
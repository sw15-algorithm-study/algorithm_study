#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n, answer;
    int arr[100001], dp[100001];
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    answer = arr[0];
    
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        answer = max(dp[i], answer);
    }
    
    cout << answer;
    return 0;
}
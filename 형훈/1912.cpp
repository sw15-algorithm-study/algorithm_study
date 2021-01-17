#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001] = {};
int main(){
    int result;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    dp[0] = arr[0];
    for(int i = 0; i < n; i++)
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
    result = *max_element(dp, dp + n);
    printf("%d", result);
}  

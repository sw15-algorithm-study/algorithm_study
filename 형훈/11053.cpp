#include <iostream>
#include <algorithm> 
 
using namespace std;

int n;
int dp[1000] = {};
int arr[1000] = {};
int sum = 0;
int main()
{ 
    scanf("%d", &n); 
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]); 
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        sum = max(sum, dp[i]);
    }
    printf("%d", sum);
}
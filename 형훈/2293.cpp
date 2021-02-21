#include <iostream>
using namespace std;

int n, k;
int dp[10001];
int value[101];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &value[i]);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = value[i]; j <= k; j++)
            dp[j] += dp[j - value[i]];          //해당금액이 들어가면서 대체되는 경우의 수만큼 더해집니다.
    printf("%d", dp[k]);
}
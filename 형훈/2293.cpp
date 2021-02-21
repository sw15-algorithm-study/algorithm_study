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
            dp[j] += dp[j - value[i]];          //�ش�ݾ��� ���鼭 ��ü�Ǵ� ����� ����ŭ �������ϴ�.
    printf("%d", dp[k]);
}
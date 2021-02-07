#include <iostream>
#include <algorithm>

using namespace std;

int n, maximum = 0;
int t[16],p[16], dp[16] = {0};

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &t[i], &p[i]);
    for(int i = 0; i < n; i++){
        maximum = *max_element(dp, dp + i);         //일이 추가되는 곳 이전시점에 수익중 가장 큰값
        if(i+t[i] <= n){
            dp[i+t[i]-1] = max(maximum + p[i], dp[i+t[i]-1]);       //t만큼의 시간 후 얻을수 있다고 가정
        }
    }
    maximum = *max_element(dp, dp + n);
    printf("%d", maximum);
}
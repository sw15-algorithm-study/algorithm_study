#include <iostream>

using namespace std;

int n = 1;
long long result;
long long dp[31][31] = {0,};

long long eat(int w, int h){
    if(w < 0) 
        return 0;
    if(dp[w][h] > 0) 
        return dp[w][h];
    if(w == 0 && h == 0)
        return 1;
    if(w > 0)
        dp[w][h] += eat(w - 1, h + 1);    
    if(h > 0)
        dp[w][h] += eat(w, h - 1);
    return dp[w][h];
}

int main(){
    while(1){
        scanf("%d", &n);
        if(n == 0)
            break;
        printf("%lld\n", eat(n,0));
    }
}
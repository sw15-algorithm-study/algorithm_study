#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int dp[21][21][21] = {0, };

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }

    if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }

    if(dp[a][b][c] != 0){
        return dp[a][b][c];
    }

    if(a < b && b < c){
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else{
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    return dp[a][b][c];
}

int main(void){
    int a, b, c;

    while(1){
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1){
            break;
        }
        
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }

    return 0;
}
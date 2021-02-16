#include <iostream>
#include <vector>

using namespace std;

long long dp[31][31] = {0, };

long long search(int w, int h){
    //알약을 조각낼 수 없을 때
    if(w < 0){
        return 0;
    }

    //이미 구해져 있는 경우
    if(dp[w][h] > 0){
        return dp[w][h];
    }

    //알약이 없을 때
    if(w == 0 && h == 0){
        return 1;
    }

    //알약을 조각낼 수 있을 때
    if(w > 0){
        dp[w][h] += search(w - 1, h + 1);
    }

    //조각난 알약이 남았을 때
    if(h > 0){
        dp[w][h] += search(w, h - 1);
    }

    return dp[w][h];
}

int main(void){
    int n;

    while(1){
        cin >> n;

        if(n == 0){
            break;
        }

        cout << search(n, 0) << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
int N = 0;
vector<int> T, P;

void dfs(int day, int sum){
    if(day == N){
        ans = max(ans, sum);
        return;
    }

    //현재 진료날 선택했을 때
    if(day + T[day] <= N){
        dfs(day + T[day], sum + P[day]);
    }
    
    //현재 진료날 선택 안하고 다음 진료날로 선택했을 때
    if(day + 1 <= N){
        dfs(day + 1, sum);
    }
}

int main(void){

    cin >> N;

    for(int i = 0; i < N; i++){
        int t, p;

        cin >> t >> p;

        T.push_back(t);
        P.push_back(p);
    }

    dfs(0, 0);

    cout << ans;

    return 0;

}
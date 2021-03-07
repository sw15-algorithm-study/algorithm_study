#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> worker(1001);
vector<int> available(1001, 0);
vector<bool> check(1001, false);

bool dfs(int number){
    for(int i = 0; i < worker[number].size(); i++){
        int work = worker[number][i];

        //일이 이미 매칭된 경우 continue
        if(check[work]){
            continue;
        }

        check[work] = true;
        
        //일이 아무도 매칭되어있지 않거나, 직원이 현재 일 외에 다른 일을 할 수 있는 경우 찾기
        if(available[work] == 0 || dfs(available[work])){
            available[work] = number;
            return true;
        }
    }
    return false;
}

int main(void){
    int ans = 0, N, M;

    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        int num;

        cin >> num;

        for(int j = 0; j < num; j++){
            int tmp;
            
            cin >> tmp;
            worker[i].push_back(tmp);
        }
    }

    //이분매칭
    for(int i = 1;  i <= N; i++){
        //최대한 모든 일을 해야하기 때문에 false로 바꿔주어 최대로 매칭하기
        fill(check.begin(), check.end(), false);
        if(dfs(i)){
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}
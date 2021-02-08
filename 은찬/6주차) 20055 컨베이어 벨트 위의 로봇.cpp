#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N, K, cnt = 0, ans = 0;
    deque<int> moving, waiting;
    
    cin >> N >> K;

    for(int i = 0; i < 2 * N; i++){
        int tmp;
        cin >> tmp;
        if(i < N){
            moving.push_back(tmp);
        }
        else{
            waiting.push_front(tmp);
        }
    }

    deque<bool> check(N, false);

    while(cnt < K){
        // 벨트 한 칸 회전
        moving.push_front(waiting.front());
        waiting.push_back(moving.back());
        check.push_front(false);
        moving.pop_back();
        waiting.pop_front();
        check.pop_back();

        // 벨트 확인하여 로봇 올리기
        if(!check.front() && moving.front() > 0){
            check[0] = true;
            moving[0]--;

            if(moving[0] == 0){
                cnt++;
            }
        }

        // 벨트 확인하여 로봇 내리기
        if(check.back()){
            check[N - 1] = false;
        }

        // 로봇 이동
        for(int i = N - 1; i > 1; i--){
            if(!check[i] && check[i - 1] && moving[i] > 0){
                check[i - 1] = false;
                check[i] = true;
                moving[i]--;

                if(moving[i] == 0){
                    cnt++;
                }
            }
        }
        
        ans++;
    }

    cout << ans;

    return 0;
}
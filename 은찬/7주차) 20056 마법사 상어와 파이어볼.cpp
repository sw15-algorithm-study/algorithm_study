#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    //[r, c] = pair(m, pair(s, d))
    queue<pair<pair<int, int>, pair<int, pair<int, int>>>> order;
    int N, M, K;
    int direct_x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int direct_y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int ans = 0;

    cin >> N >> M >> K;
    
    vector<vector<queue<pair<int, pair<int, int>>>>> board(N + 1, vector<queue<pair<int, pair<int, int>>>>(N + 1));

    for(int i = 0; i < M; i++){
        int r, c, m, s, d;

        cin >> r >> c >> m >> s >> d;
        order.push(make_pair(make_pair(r, c),make_pair(m, make_pair(s, d))));
    }

    for(int i = 0; i < K; i++){
        //K번 명령하기
        while(!order.empty()){
            //target_x, target_y = 파이어볼의 위치
            //m = 질량, s = 속력(이동 칸 수), d = 방향
            int m = order.front().second.first;
            int s = order.front().second.second.first;
            int d = order.front().second.second.second;
            int current_x = order.front().first.first;
            int current_y = order.front().first.second;
            int target_x = current_x + direct_x[d] * s;
            int target_y = current_y + direct_y[d] * s;
            
            order.pop();
            
            if(target_x < 1){
                target_x += N;
            }
            else if(target_x > N){
                target_x -= N;
            }

            if(target_y < 1){
                target_y += N;
            }
            else if(target_y > N){
                target_y -= N;
            }
            
            board[target_x][target_y].push(make_pair(m, make_pair(s, d)));
        }

        //파이어볼 합치고 나누기
        for(int r = 1; r <= N; r++){
            for(int c = 1; c <= N; c++){
                if(board[r][c].empty()){
                    continue;
                }
                
                if(board[r][c].size() == 1){
                    int m = board[r][c].front().first;
                    int s = board[r][c].front().second.first;
                    int d = board[r][c].front().second.second;
                    board[r][c].pop();
                    order.push(make_pair(make_pair(r, c), make_pair(m, make_pair(s, d))));
                }
                else if(board[r][c].size() > 1){
                    int sum_m = 0;
                    int sum_s = 0;
                    int d = 0;
                    int fire_ball = 0;
                    bool odd = false, even = false, other = false;

                    while(!board[r][c].empty()){
                        sum_m += board[r][c].front().first;
                        sum_s += board[r][c].front().second.first;
                        d = board[r][c].front().second.second;
                        fire_ball++;

                        if(d % 2){
                            if(!even && !other){
                                odd = true;
                            }
                            else{
                                other = true;
                            }
                        }
                        else{
                            if(!odd && !other){
                                even = true;
                            }
                            else{
                                other = true;
                            }
                        }
                        
                        board[r][c].pop();
                    }

                    sum_m /= 5;
                    sum_s /= fire_ball;

                    if(sum_m > 0){
                        if(!other){
	                        order.push(make_pair(make_pair(r, c), make_pair(sum_m, make_pair(sum_s, 0))));
	                        order.push(make_pair(make_pair(r, c), make_pair(sum_m, make_pair(sum_s, 2))));
	                        order.push(make_pair(make_pair(r, c), make_pair(sum_m, make_pair(sum_s, 4))));
	                        order.push(make_pair(make_pair(r, c), make_pair(sum_m, make_pair(sum_s, 6))));
                        }
                        else{
                            order.push(make_pair(make_pair(r, c), make_pair(sum_m, make_pair(sum_s, 1))));
                            order.push(make_pair(make_pair(r, c), make_pair(sum_m, make_pair(sum_s, 3))));
                            order.push(make_pair(make_pair(r, c), make_pair(sum_m, make_pair(sum_s, 5))));
                            order.push(make_pair(make_pair(r, c), make_pair(sum_m, make_pair(sum_s, 7))));
                        }
                    }
                }
            }
        }
    }

    while(!order.empty()){
        ans += order.front().second.first;
        order.pop();
    }

    cout << ans;

    return 0;
}
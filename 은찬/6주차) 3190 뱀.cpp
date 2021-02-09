#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void){
    int N, K, L, ans = 0, current_time = 1;
    int current_x = 1, current_y = 1;
    int state = 3;
    int direct_x[4] = {-1, 1, 0, 0};
    int direct_y[4] = {0, 0, -1, 1};
    deque<pair<int, int>> snake;

    cin >> N;
    cin >> K;

    vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));

    //뱀의 시작 위치
    //보드의 칸이 -1이면 사과가 있다.
    //보드의 칸이 0이면 빈 칸이다.
    //보드의 칸이 1이면 뱀의 몸이 있다.
    snake.push_front(make_pair(1, 1));
    
    for(int i = 0; i < K; i++){
        //사과 놓기
        int x, y;
        cin >> x >> y;

        board[x][y] = -1;
    }

    cin >> L;

    for(int i = 0; i < L; i++){
        int X;
        char C;

        cin >> X >> C;

        for(int j = current_time; j <= X; j++){
            ans++;

            //이동하려고 하는 칸이 벽인지 검사
            if(current_x + direct_x[state] >= 1 && current_x + direct_x[state] <= N && current_y + direct_y[state] >= 1 && current_y + direct_y[state] <= N){
                current_x += direct_x[state];
                current_y += direct_y[state];

                if(board[current_x][current_y] == -1){
                    //이동하려는 칸이 사과인 경우
                    board[current_x][current_y] = 1;
                    snake.push_front(make_pair(current_x, current_y));
                }
                else if(board[current_x][current_y] == 0){
                    //이동하려는 칸이 빈 칸인 경우
                    board[snake.back().first][snake.back().second] = 0;
                    board[current_x][current_y] = 1;
                    snake.push_front(make_pair(current_x, current_y));
                    snake.pop_back();
                }
                else if(board[current_x][current_y] == 1){
                    //이동하려는 칸이 뱀의 몸인 경우
                    cout << ans;
                    return 0;
                }
            }
            else{
                //벽에 부딪힌 경우
                cout << ans;
                return 0;
            }
        }

        if(state == 0){
            if(C == 'L'){
                state = 2;
            }
            else{
                state = 3;
            }
        }
        else if(state == 1){
            if(C == 'L'){
                state = 3;
            }
            else{
                state = 2;
            }
        }
        else if(state == 2){
            if(C == 'L'){
                state = 1;
            }
            else{
                state = 0;
            }
        }
        else{
            if(C == 'L'){
                state = 0;
            }
            else{
                state = 1;
            }
        }

        current_time = X + 1;
    }

    while(1){
        ans++;

        //이동하려고 하는 칸이 벽인지 검사
        if(current_x + direct_x[state] >= 1 && current_x + direct_x[state] <= N && current_y + direct_y[state] >= 1 && current_y + direct_y[state] <= N){
            current_x += direct_x[state];
            current_y += direct_y[state];

            if(board[current_x][current_y] == -1){
                //이동하려는 칸이 사과인 경우
                board[current_x][current_y] = 1;
                snake.push_front(make_pair(current_x, current_y));
            }
            else if(board[current_x][current_y] == 0){
                //이동하려는 칸이 빈 칸인 경우
                board[snake.back().first][snake.back().second] = 0;
                board[current_x][current_y] = 1;
                snake.push_front(make_pair(current_x, current_y));
                snake.pop_back();
            }
            else if(board[current_x][current_y] == 1){
                //이동하려는 칸이 뱀의 몸인 경우
                cout << ans;
                return 0;
            }
        }
        else{
            //벽에 부딪힌 경우
            cout << ans;
            return 0;
        }
    }

    return 0;
}
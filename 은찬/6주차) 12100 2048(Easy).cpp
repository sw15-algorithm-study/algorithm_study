#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int ans = 0;
int N;

void dfs(vector<vector<int>> tmp_board, int cnt, int direction){
    if(cnt > 5){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans = ans < tmp_board[i][j] ? tmp_board[i][j] : ans;
            }
        }
        return;
    }

    //0 = 위, 1 = 아래, 2 = 왼쪽, 3 = 오른쪽 방향으로 이동
    if(direction == 0){
        for(int j = 0; j < N; j++){
            deque<int> d;
            bool changed = false;

            for(int i = 0; i < N; i++){
                if(tmp_board[i][j] != 0){
                    if(d.empty()){
                        d.push_back(tmp_board[i][j]);
                    }
                    else{
                        if(d.back() == tmp_board[i][j]){
                            if(!changed){
                                d.pop_back();
                                d.push_back(tmp_board[i][j] * 2);
                                changed = true;
                            }
                            else{
                                d.push_back(tmp_board[i][j]);
                                changed = false;
                            }
                        }
                        else{
                            d.push_back(tmp_board[i][j]);
                            changed = false;
                        }
                    }
                }
                
            }

            for(int i = 0; i < N; i++){
                if(!d.empty()){
                    tmp_board[i][j] = d.front();
                    d.pop_front();
                }
                else{
                    tmp_board[i][j] = 0;
                }
            }
        }
    }
    else if(direction == 1){
        for(int j = 0; j < N; j++){
            deque<int> d;
            bool changed = false;

            for(int i = N - 1; i >= 0; i--){
                if(tmp_board[i][j] != 0){
                    if(d.empty()){
                        d.push_front(tmp_board[i][j]);
                    }
                    else{
                        if(d.front() == tmp_board[i][j]){
                            if(!changed){
                                d.pop_front();
                                d.push_front(tmp_board[i][j] * 2);
                                changed = true;
                            }
                            else{
                                d.push_front(tmp_board[i][j]);
                                changed = false;
                            }
                            
                        }
                        else{
                            d.push_front(tmp_board[i][j]);
                            changed = false;
                        }
                    }
                }
            }

            for(int i = N - 1; i >= 0; i--){
                if(!d.empty()){
                    tmp_board[i][j] = d.back();
                    d.pop_back();
                }
                else{
                    tmp_board[i][j] = 0;
                }
            }
        }
    }
    else if(direction == 2){
        for(int i = 0; i < N; i++){
            deque<int> d;
            bool changed = false;

            for(int j = 0; j < N; j++){
                if(tmp_board[i][j] != 0){
                    if(d.empty()){
                        d.push_back(tmp_board[i][j]);
                    }    
                    else{
                        if(d.back() == tmp_board[i][j]){
                            if(!changed){
                                d.pop_back();
                                d.push_back(tmp_board[i][j] * 2);
                                changed = true;
                            }
                            else{
                                d.push_back(tmp_board[i][j]);
                                changed = false;
                            }
                        }
                        else{
                            d.push_back(tmp_board[i][j]);
                            changed = false;
                        }
                    }
                }
            }

            for(int j = 0; j < N; j++){
                if(!d.empty()){
                    tmp_board[i][j] = d.front();
                    d.pop_front();
                }
                else{
                    tmp_board[i][j] = 0;
                }
            }
        }
    }
    else if(direction == 3){
        for(int i = 0; i < N; i++){
            deque<int> d;
            bool changed = false;

            for(int j = N - 1; j >= 0; j--){
                if(tmp_board[i][j] != 0){
                    if(d.empty()){
                      d.push_front(tmp_board[i][j]);
                    }
                    else{
                        if(d.front() == tmp_board[i][j]){
                            if(!changed){
                                d.pop_front();
                                d.push_front(tmp_board[i][j] * 2);
                                changed = true;
                            }
                            else{
                                d.push_front(tmp_board[i][j]);
                                changed = false;
                            }
                        }
                        else{
                            d.push_front(tmp_board[i][j]);
                            changed = false;
                        }
                    }
                }
            }

            for(int j = N - 1; j >= 0; j--){
                if(!d.empty()){
                    tmp_board[i][j] = d.back();
                    d.pop_back();
                }
                else{
                    tmp_board[i][j] = 0;
                }
            }
        }
    }
    
    dfs(tmp_board, cnt + 1, 0);
    dfs(tmp_board, cnt + 1, 1);
    dfs(tmp_board, cnt + 1, 2);
    dfs(tmp_board, cnt + 1, 3);
}

int main(void){
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    dfs(board, 1, 0);
    dfs(board, 1, 1);
    dfs(board, 1, 2);
    dfs(board, 1, 3);

    cout << ans;
    
    return 0;
}
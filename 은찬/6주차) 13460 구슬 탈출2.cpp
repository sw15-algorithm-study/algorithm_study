/*
구슬의 위치를 이용해 상하좌우로 보드를 기울인다.
기울이기 전과 후가 같으면 큐에 넣지 않는다.
마찬가지로 파란공이 빠졌을 때도 큐에 넣지 않는다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int goal_x, goal_y;
vector<string> board;

pair<int, int> up(int current_x, int current_y, int target_x){
    int after_x = current_x;

    for(after_x = current_x; after_x > target_x; after_x--){
        if(board[after_x - 1][current_y] == '#'){
            return make_pair(after_x, current_y);
        }
        if(after_x - 1 == goal_x && current_y == goal_y){
            return make_pair(goal_x, goal_y);
        }
    }
    return make_pair(after_x + 1, current_y);
}

pair<int, int> down(int current_x, int current_y, int target_x){
    int after_x = current_x;

    for(after_x = current_x; after_x < target_x; after_x++){
        if(board[after_x + 1][current_y] == '#'){
            return make_pair(after_x, current_y);
        }
        if(after_x + 1 == goal_x && current_y == goal_y){
            return make_pair(goal_x, goal_y);
        }
    }
    return make_pair(after_x - 1, current_y);
}

pair<int, int> left(int current_x, int current_y, int target_y){
    int after_y = current_y;

    for(after_y = current_y; after_y > target_y; after_y--){
        if(board[current_x][after_y - 1] == '#'){
            return make_pair(current_x, after_y);
        }
        if(current_x == goal_x && after_y - 1 == goal_y){
            return make_pair(goal_x, goal_y);
        }
    }
    return make_pair(current_x, after_y + 1);
}

pair<int, int> right(int current_x, int current_y, int target_y){
    int after_y = current_y;

    for(after_y = current_y; after_y < target_y; after_y++){
        if(board[current_x][after_y + 1] == '#'){
            return make_pair(current_x, after_y);
        }
        if(current_x == goal_x && after_y + 1 == goal_y){
            return make_pair(goal_x, goal_y);
        }
    }
    return make_pair(current_x, after_y - 1);
}

int main(void){
    int cnt = 0;
    int red_x, red_y, blue_x, blue_y;

    cin >> N >> M;

    queue<pair<pair<pair<int, int>, pair<int, int>>, char>> q;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == '.' || board[i][j] == '#'){
                continue;
            }

            if(board[i][j] == 'R'){
                red_x = i;
                red_y = j;
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B'){
                blue_x = i;
                blue_y = j;
                board[i][j] = '.';
            }
            else if(board[i][j] == 'O'){
                goal_x = i;
                goal_y = j;
                board[i][j] = '.';
            }
        }
    }

    q.push(make_pair(make_pair(make_pair(red_x, red_y), make_pair(blue_x, blue_y)), '0'));

    while(cnt <= 10){
        cnt++;
        
        if(cnt > 10 || q.empty()){
        	cout << -1;
        	break;
        }
        
        int size = q.size();

        for(int i = 0; i < size; i++){
            pair<int, int> current_red;
            pair<int, int> current_blue;
            pair<int, int> after_red;
            pair<int, int> after_blue;
            char before = q.front().second;

            current_red.first = q.front().first.first.first;
            current_red.second = q.front().first.first.second;
            current_blue.first = q.front().first.second.first;
            current_blue.second = q.front().first.second.second;
			
            q.pop();

            //위로 기울기
            if(before != 'd'){
                if(current_red.second == current_blue.second){
                    if(current_red.first < current_blue.first){
                        after_red = up(current_red.first, current_red.second, 0);
                        after_blue = up(current_blue.first, current_blue.second, after_red.first);
                    }
                    else{
                        after_blue = up(current_blue.first, current_blue.second, 0);
                        after_red = up(current_red.first, current_red.second, after_blue.first);
                    }
                }
                else{
                    after_red = up(current_red.first, current_red.second, 0);
                    after_blue = up(current_blue.first, current_blue.second, 0);
                }
                
                if(after_red.first == goal_x && after_red.second == goal_y){
                    if(after_blue.first != goal_x || after_blue.second != goal_y){
                        cout << cnt;
                        return 0;
                    }
                }
                else{
                    if(after_red.first != current_red.first || after_red.second != current_red.second || after_blue.first != current_blue.first || after_blue.second != current_blue.second){
                        if(!(after_blue.first == goal_x && after_blue.second == goal_y)){
                        	q.push(make_pair(make_pair(make_pair(after_red.first, after_red.second), make_pair(after_blue.first, after_blue.second)), 'u'));
                        }
                    }
                }
            }

            //아래로 기울기
            if(before != 'u'){
                if(current_red.second == current_blue.second){
                    if(current_red.first > current_blue.first){
                        after_red = down(current_red.first, current_red.second, N);
                        after_blue = down(current_blue.first, current_blue.second, after_red.first);
                    }
                    else{
                        after_blue = down(current_blue.first, current_blue.second, N);
                        after_red = down(current_red.first, current_red.second, after_blue.first);
                    }
                }
                else{
                    after_red = down(current_red.first, current_red.second, N);
                    after_blue = down(current_blue.first, current_blue.second, N);
                }

                if(after_red.first == goal_x && after_red.second == goal_y){
                    if(after_blue.first != goal_x || after_blue.second != goal_y){
                        cout << cnt;
                        return 0;
                    }
                }
                else{
                    if(after_red.first != current_red.first || after_red.second != current_red.second || after_blue.first != current_blue.first || after_blue.second != current_blue.second){
                        if(!(after_blue.first == goal_x && after_blue.second == goal_y)){
                            q.push(make_pair(make_pair(make_pair(after_red.first, after_red.second), make_pair(after_blue.first, after_blue.second)), 'd'));
                        }
                    }
                }
            }
            
            //왼쪽으로 기울기
            if(before != 'r'){
                if(current_red.first == current_blue.first){
                    if(current_red.second < current_blue.second){
                        after_red = left(current_red.first, current_red.second, 0);
                        after_blue = left(current_blue.first, current_blue.second, after_red.second);
                    }
                    else{
                        after_blue = left(current_blue.first, current_blue.second, 0);
                        after_red = left(current_red.first, current_red.second, after_blue.second);
                    }
                }
                else{
                    after_red = left(current_red.first, current_red.second, 0);
                    after_blue = left(current_blue.first, current_blue.second, 0);
                }
				
                if(after_red.first == goal_x && after_red.second == goal_y){
                    if(after_blue.first != goal_x || after_blue.second != goal_y){
                        cout << cnt;
                        return 0;
                    }
                }
                else{
                    if(after_red.first != current_red.first || after_red.second != current_red.second || after_blue.first != current_blue.first || after_blue.second != current_blue.second){
                        if(!(after_blue.first == goal_x && after_blue.second == goal_y)){
                            q.push(make_pair(make_pair(make_pair(after_red.first, after_red.second), make_pair(after_blue.first, after_blue.second)), 'l'));
                        }
                    }
                }
            }

            //오른쪽으로 기울기
            if(before != 'l'){
                if(current_red.first == current_blue.first){
                    if(current_red.second > current_blue.second){
                        after_red = right(current_red.first, current_red.second, M);
                        after_blue = right(current_blue.first, current_blue.second, after_red.second);
                    }
                    else{
                        after_blue = right(current_blue.first, current_blue.second, M);
                        after_red = right(current_red.first, current_red.second, after_blue.second);
                    }
                }
                else{
                    after_red = right(current_red.first, current_red.second, M);
                    after_blue = right(current_blue.first, current_blue.second, M);
                }
				
                if(after_red.first == goal_x && after_red.second == goal_y){
                    if(after_blue.first != goal_x || after_blue.second != goal_y){
                        cout << cnt;
                        return 0;
                    }
                }
                else{
                    if(after_red.first != current_red.first || after_red.second != current_red.second || after_blue.first != current_blue.first || after_blue.second != current_blue.second){
                        if(!(after_blue.first == goal_x && after_blue.second == goal_y)){
                            q.push(make_pair(make_pair(make_pair(after_red.first, after_red.second), make_pair(after_blue.first, after_blue.second)), 'r'));
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
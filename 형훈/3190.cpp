#include <iostream>
#include <queue>
using namespace std;

int n, k, l, dir = 0, count = 0;
bool end_game;
int board[101][101] = {0};      //몸통은 1, 사과는 2
queue<pair<int,int>> q;

bool move(){
    int x, y;
    y = q.back().first;         
    x = q.back().second;
    if(dir == 0){               //오른쪽 방향 진행
        q.push({y, x+1});       //다음 머리의 좌표
        if(0 <= q.back().first && q.back().first < n && 0 <= q.back().second && q.back().second < n){   //보드를 벗어나지 않았다면
            if(board[q.back().first][q.back().second] == 1)             //진행한 곳의 뱀의 몸통이 있다면
                return true;
            if(board[q.back().first][q.back().second] == 2)             //진행한 곳에 사과가 있다면
                board[q.back().first][q.back().second] = 0;             //사과 제거
            else{                                                       //사과가 없다면
                board[q.front().first][q.front().second] = 0;           //뱀의 꼬리 제거
                q.pop();                                                //꼬리가 위치한 칸을 비워줌
            }
            board[q.back().first][q.back().second] = 1;                 //뱀의 머리 추가
        }
        else                    //보드를 벗어났다면
            return true;
    }
    else if(dir == 1){          //아래 방향 진행
        q.push({y+1, x});
        if(0 <= q.back().first && q.back().first < n && 0 <= q.back().second && q.back().second < n){   //보드를 벗어나지 않았다면
            if(board[q.back().first][q.back().second] == 1)             //진행한 곳의 뱀의 몸통이 있다면
                return true;
            if(board[q.back().first][q.back().second] == 2)             //진행한 곳에 사과가 있다면
                board[q.back().first][q.back().second] = 0;             //사과 제거
            else{                                                       //사과가 없다면
                board[q.front().first][q.front().second] = 0;           //뱀의 꼬리 제거
                q.pop();                                                //꼬리가 위치한 칸을 비워줌
            }
            board[q.back().first][q.back().second] = 1;                 //뱀의 머리 추가
        }
        else                    //보드를 벗어났다면
            return true;
    }
    else if(dir == 2){          //왼쪽 방향 진행
        q.push({y, x-1});
        if(0 <= q.back().first && q.back().first < n && 0 <= q.back().second && q.back().second < n){   //보드를 벗어나지 않았다면
            if(board[q.back().first][q.back().second] == 1)             //진행한 곳의 뱀의 몸통이 있다면
                return true;
            if(board[q.back().first][q.back().second] == 2)             //진행한 곳에 사과가 있다면
                board[q.back().first][q.back().second] = 0;             //사과 제거
            else{                                                       //사과가 없다면
                board[q.front().first][q.front().second] = 0;           //뱀의 꼬리 제거
                q.pop();                                                //꼬리가 위치한 칸을 비워줌
            }
            board[q.back().first][q.back().second] = 1;                 //뱀의 머리 추가
        }
        else                    //보드를 벗어났다면
            return true;
    }
    else if(dir == 3){          //위쪽 방향 진행
        q.push({y-1, x});
        if(0 <= q.back().first && q.back().first < n && 0 <= q.back().second && q.back().second < n){   //보드를 벗어나지 않았다면
            if(board[q.back().first][q.back().second] == 1)             //진행한 곳의 뱀의 몸통이 있다면
                return true;
            if(board[q.back().first][q.back().second] == 2)             //진행한 곳에 사과가 있다면
                board[q.back().first][q.back().second] = 0;             //사과 제거
            else{                                                       //사과가 없다면
                board[q.front().first][q.front().second] = 0;           //뱀의 꼬리 제거
                q.pop();                                                //꼬리가 위치한 칸을 비워줌
            }
            board[q.back().first][q.back().second] = 1;                 //뱀의 머리 추가
        }
        else                    //보드를 벗어났다면
            return true;
    }
    return false;               //게임이 끝나지 않으면 false
}

int main(){
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int tmp1, tmp2; 
        scanf("%d %d", &tmp1, &tmp2);
        board[tmp1-1][tmp2-1] = 2;
    }
    q.push({0,0});
    board[0][0] = 1;                //1은 뱀의 몸
    scanf("%d", &l);
    int before_time = 0;
    for(int i = 0; i < l; i++){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        int current_time = x - before_time;
        for(int j = current_time; j > 0; j--){
            count++;
            end_game = move();
            if(end_game){
                printf("%d", count);
                return 0;
            }
        }
        if(c == 'D')                //다음 진행 방향이 D일때
            dir = (dir + 1) % 4;
        else if(c == 'L')           //다음 진행 방향이 L일때
            dir = (dir + 4 - 1) % 4;
        before_time = x;            //지금까지의 시간 기록
    }
    while(!end_game){
        count++;
        end_game = move();
    }
    printf("%d", count);
    return 0;
}
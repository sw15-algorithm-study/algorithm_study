#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N, M, x, y, K;
    //주사위는 0부터 차례대로 윗면, 뒷면, 오른쪽면, 왼쪽면, 앞면, 바닥면이다.
    vector<int> dice(6, 0);
    int direct_x[5] = {0, 0, 0, -1, 1};
    int direct_y[5] = {0, 1, -1, 0, 0};

    cin >> N >> M >> x >> y >> K;

    vector<vector<int>> board(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < K; i++){
        int dir;

        cin >> dir;

        //주사위가 지도를 넘어가는지 검사
        if(x + direct_x[dir] >= 0 && x + direct_x[dir] < N && y + direct_y[dir] >= 0 && y + direct_y[dir] < M){
            int ceil = dice[0];
            int back = dice[1];
            int right = dice[2];
            int left = dice[3];
            int front = dice[4];
            int bottom = dice[5];
            
            //주사위 이동
            x += direct_x[dir];
            y += direct_y[dir];

            //1: 동, 2: 서, 3: 북, 4: 남
            //동, 서로 이동할 경우 주사위는 위, 아래, 좌, 우에 있는 숫자가 바뀌게 된다.
            //북, 남으로 이동할 경우 주사위는 위, 아래, 앞, 뒤에 있는 숫자가 바뀌게 된다.
            if(dir == 1){
                dice[0] = left;
                dice[2] = ceil;
                dice[3] = bottom;
                dice[5] = right;
            }
            else if(dir ==2){
                dice[0] = right;
                dice[2] = bottom;
                dice[3] = ceil;
                dice[5] = left;
            }
            else if(dir == 3){
                dice[0] = front;
                dice[1] = ceil;
                dice[4] = bottom;
                dice[5] = back;
            }
            else{
                dice[0] = back;
                dice[1] = bottom;
                dice[4] = ceil;
                dice[5] = front;
            }

            if(board[x][y] == 0){
                board[x][y] = dice[5];
            }
            else{
                dice[5] = board[x][y];
                board[x][y] = 0;
            }

            //주사위 윗면 출력
            cout << dice[0] << endl;
        }
    }

    return 0;
}
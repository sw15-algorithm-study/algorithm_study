#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(void){
    int N, M, D, ans = 0;

    cin >> N >> M >> D;

    vector<vector<int>> board(N + 2, vector<int>(M + 2, 0));
    vector<vector<int>> copyBoard(N + 2, vector<int>(M + 2, 0));
    vector<pair<int, int>> archers(3, pair<int, int>(make_pair(N + 1, 0)));

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> board[i][j];
        }
    }
    

    //궁수 배치
    for(int i = 1; i <= M; i++){
        archers[0].second = i;

        for(int j = i + 1; j <= M; j++){
            archers[1].second = j;
            
            for(int k = j + 1; k <= M; k++){
                int current = 0;
                vector<pair<int, int>> enemies(3);
                //원래 적의 위치를 copy_board에 복사
                copyBoard = board;
                archers[2].second = k;

                for(int turn = 0; turn <= N; turn++){
                    for(int p = 0; p < 3; p++){
                        //맵에 존재하는 적의 위치 중 D 이하인 적의 거리 구하기.
                        int distance = INT_MAX;
                        int targetX = INT_MAX, targetY = INT_MAX;

                        for(int x = N; x > 0; x--){
                            for(int y = 1; y <= M; y++){
                                if(abs(archers[p].first - x) + abs(archers[p].second - y) <= D){
                                    if(copyBoard[x][y]){
                                        if(distance >= abs(archers[p].first - x) + abs(archers[p].second - y)){
                                            if(distance == abs(archers[p].first - x) + abs(archers[p].second - y)){
                                                if(y < targetY){
                                                    targetX = x;
                                                    targetY = y;
                                                }
                                            }
                                            else{
                                                distance = abs(archers[p].first - x) + abs(archers[p].second - y);
                                                targetX = x;
                                                targetY = y;
                                            }
                                            
                                        }
                                    }
                                }
                            }
                        }

                        //만약 적의 위치가 INT_MAX인 경우 없다는 뜻이므로 0, 0으로 저장.
                        //아닌 경우 적의 위치를 저장.
                        if(targetX == INT_MAX || targetY == INT_MAX){
                            enemies[p].first = 0;
                            enemies[p].second = 0;    
                        }
                        else{
                            enemies[p].first = targetX;
                            enemies[p].second = targetY;
                        }
                    }

                    //적 제거
                    for(int p = 0; p < 3; p++){
                        if(copyBoard[enemies[p].first][enemies[p].second]){
                            copyBoard[enemies[p].first][enemies[p].second] = 0;
                            current++;
                        }
                    }
                    
                    //적 이동
                    for(int x = N; x > 0; x--){
                        copyBoard[x] = copyBoard[x - 1];
                    }
                }
                ans = ans < current ? current : ans;
            }
        }
    }

    cout << ans;

    return 0;
}
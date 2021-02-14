#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int N, ans = 0;
    int shark_x = 0, shark_y = 0, shark_size = 2, feed = 0;
    //상어가 먹을 수 있는 물고기들을 나타내는 벡터인 target
    vector<pair<pair<int, int>, int>> target;
    int direct_x[4] = {-1, 1, 0, 0};
    int direct_y[4] = {0, 0, -1, 1};

    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            
            if(board[i][j] == 9){
                board[i][j] = 0;
                shark_x = i;
                shark_y = j;
            }
        }
    }

    while(1){
        queue<pair<int, int>> q;
        //현재 상어의 위치에서부터 먹이까지 거리를 나타내는 2차원 벡터
        vector<vector<int>> distance(N, vector<int>(N, 0));
        //최소 거리
        int min_distance = 400;

        q.push(make_pair(shark_x, shark_y));
        target.clear();

        while(!q.empty()){
            int current_x = q.front().first;
            int current_y = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                //현재 상어의 위치에서부터 상하좌우에 자신보다 작은 크기의 물고기가 있는지 검사
                int target_x = current_x + direct_x[i];
                int target_y = current_y + direct_y[i];

                //상하좌우의 위치가 맵을 벗어나지 않은 경우 검사
                if(target_x >= 0 && target_x < N && target_y >= 0 && target_y < N){
                    //이동한 위치가 현재 상어의 크기보다 같거나 작은 경우 이동한 거리를 distance에 저장하면서 체크
                    if(distance[target_x][target_y] == 0 && board[target_x][target_y] <= shark_size){
                        distance[target_x][target_y] = distance[current_x][current_y] + 1;

                        //상어가 물고기를 잡아먹을 수 있을 때 target에 ((이동 거리, 먹이의 x 좌표), 먹이의 y 좌표)로 push
                        if(board[target_x][target_y] > 0 && board[target_x][target_y] < shark_size){
                            if(min_distance >= distance[target_x][target_y]){
                                min_distance = distance[target_x][target_y];
                                target.push_back(make_pair(make_pair(min_distance, target_x), target_y));
                            }
                        }
                        q.push(make_pair(target_x, target_y));
                    }
                }
            }
        }

        //만약 target이 비어있다면 아무것도 먹을 수 없기 때문에 종료.
        //target을 sort하면 최단 거리에 있는 먹이를 알아서 오름차순으로 정렬한다.
        //sort 후 target의 맨 앞에 있는 결과가 현재로부터 가장 가까운 먹이가 된다.
        if(!target.empty()){
            sort(target.begin(), target.end());
            
            int target_x = target[0].first.second;
            int target_y = target[0].second;

            feed++;
            ans += target[0].first.first;
            board[target_x][target_y] = 0;
            shark_x = target_x;
            shark_y = target_y;

            if(feed == shark_size){
                shark_size++;
                feed = 0;
            }
        }
        else{
            break;
        }
    }

    cout << ans;

    return 0;
}
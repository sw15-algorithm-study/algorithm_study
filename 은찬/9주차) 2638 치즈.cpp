#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int N = 0, M = 0, ans = 0;
    int direct_x[4] = {-1, 1, 0, 0};
    int direct_y[4] = {0, 0, -1, 1};

    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[N][M];
        }
    }

    while(1){
        queue<pair<int, int>> q;
        vector<vector<int>> check(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        bool melted = false;

        q.push(make_pair(0, 0));

        //외부 공기와 맞닿는 치즈를 찾아서 카운트하기
        //만약 다음 상하좌우의 좌표 중 치즈가 있다면 해당 좌표에 맞닿은 횟수 늘리기.
        //다음 좌표가 치즈면 치즈의 내부로 들어가기 때문에 큐에 넣지 않는다.
        //치즈가 아니라면 외부 공기이기 때문에 큐에 넣기.
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(visited[x][y]){
                continue;
            }
            visited[x][y] = true;

            for(int j = 0; j < 4; j++){
                int nx = x + direct_x[j];
                int ny = y + direct_y[j];

                if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                    if(board[nx][ny]){
                        check[nx][ny]++;
                    }
                    else{
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }

        //치즈의 변 중 2개 이상이 외부 공기와 맞닿았으면 녹이고 외부 공기(0)로 바꾸기
        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                if(check[i][j] >= 2){
                    board[i][j] = 0;
                    melted = true;
                }
            }
        }

        if(!melted){
            break;
        }

        ans++;
    }

    cout << ans;

    return 0;
}
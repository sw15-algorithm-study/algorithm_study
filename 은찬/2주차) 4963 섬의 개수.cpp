#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    int w, h;
    int arr_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int arr_y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    while(1){
        bool map[50][50];
        queue<pair<int, int>> q;
        int answer = 0;

        cin >> w >> h;

        vector<vector<bool>> visited(h, vector<bool>(w, false));

        if(w == 0 && h == 0){
            return 0;
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j] && !visited[i][j]){
                    q.push(make_pair(i, j));
                    visited[i][j] = true;

                    while(!q.empty()){
                        int size = q.size();
                        
                        for(int s = 0; s < size; s++){
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();

                            for(int k = 0; k < 8; k++){
                                if(x + arr_x[k] >= 0 && x + arr_x[k] < h && y + arr_y[k] >= 0 && y + arr_y[k] < w && map[x + arr_x[k]][y + arr_y[k]] && !visited[x + arr_x[k]][y + arr_y[k]]){
                                    q.push(make_pair(x + arr_x[k], y + arr_y[k]));
                                    visited[x + arr_x[k]][y + arr_y[k]] = true;
                                }
                            }
                        }
                    }
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }

    return 0;
}
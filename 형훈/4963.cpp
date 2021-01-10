#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int w, h;                   
int island[51][51] = {0};   //섬 지도
bool visit[51][51] = {false};    //방문여부
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int count = 1;

void bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y,x});
    visit[y][x] = true;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(0 <= yy && yy < h && 0 <= xx && xx < w){
                if(visit[yy][xx] == false && island[yy][xx] == 1){
                    visit[yy][xx] = true;
                    island[yy][xx] = count;
                    q.push({yy,xx});
                }
            }
        }
    }
    count++;
}

int main(){
    while(1){
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0){
            break;
        }
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                scanf("%d", &island[i][j]);
        for(int i = 0; i < h; i++)     
            for(int j = 0; j < w; j++)
                if(visit[i][j] == false && island[i][j] == 1)
                    bfs(i, j);
        printf("%d\n", count - 1);
        memset(island, 0, sizeof(island)); // island 초기화
        memset(visit, 0, sizeof(visit)); // visit 초기화
        count = 1;
    }
}
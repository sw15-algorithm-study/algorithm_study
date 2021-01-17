#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, l;
int x1, y1, x2, y2;
int visit[301][301] = {0};          //방문하기까지 걸린 거리
int dy[8] = {-2,-2,-1,-1,1,1,2,2};  //나이트가 움직일 수 있는 y좌표
int dx[8] = {1,-1,2,-2,2,-2,1,-1};  //나이트가 움직일 수 있는 x좌표

int bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == y2 && x == x2)          //도착하면 기존 거리와 비교후 최소거리 저장
            return visit[y][x];
        for(int i = 0; i < 8; i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(0 <= yy && yy < l && 0 <= xx && xx < l){
                if(visit[yy][xx] == 0){
                    q.push({yy,xx});
                    visit[yy][xx] = visit[y][x] + 1;    //출발지점거리 + 1
                }
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &l);
        scanf("%d %d", &y1, &x1);
        scanf("%d %d", &y2, &x2);
        if(y1 == y2 && x1 == x2)          //출발지점과 도착지점이 같으면 거리 0리턴
            printf("0\n");
        else
            printf("%d\n", bfs(y1, x1));
        memset(visit, 0, sizeof(visit)); // visit 초기화
    }
}
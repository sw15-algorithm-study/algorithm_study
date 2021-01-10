#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int map[51][51], tmp_map[51][51];   //지도와, 임시로 사용할 지도
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
vector<pair<int,int>> v;            //바이러스 좌표 값 저장
bool check[11] = {false};           //바이러스 개수
int result = 2500;                  //결과값

int find_max(){                     //배열에서 가장 큰 값 찾기
    int value = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            value = max(value, tmp_map[i][j]);
    return value;
}
bool check_zero(){                  //최종결과여부
    bool final = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(tmp_map[i][j] == 0)
                final = false;      
    return final;                   //false면 - 1 출력
}
void bfs(){
    bool visit[51][51] = {false};                   //방문여부
    memcpy(tmp_map, map, sizeof(map));              //임시지도에 지도복사
    queue<pair<int,int>> q;
    for(int i = 0; i < 11; i++){
        if(check[i] == true){                       //바이러스가 있는 위치이면
            q.push({v[i].first,v[i].second});       //큐에 좌표추가
            visit[v[i].first][v[i].second] = true;
        }
    }
    //여기까지 바이러스가 시작하는 m개점의 좌표가 q에 들어가있다. 이제부터 전체 확산하데 걸리는 시간 구하면 됩니다.
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(0 <= yy && yy < n && 0 <= xx && xx < n){
                if(visit[yy][xx] == false && tmp_map[yy][xx] != 1){ //아직 방문하지 않았고 벽이 아닌경우
                    tmp_map[yy][xx] = tmp_map[y][x] + 1;            //이동전에 있었던 값에 + 1
                    visit[yy][xx] = true;                           //방문여부 check
                    q.push({yy,xx});
                }
            }
        }
    }
}

void virus_dfs(int index, int cnt){
    if(cnt == m){
        bfs();
        if(check_zero())                        //바이러스가 모두 퍼졌다면
            result = min(result, find_max());   //그 배열에서 찾은 최댓값(바이러스가 퍼지는데 걸리는값)과 기존값중 작은값선택
        return;
    }
    for(int i = index; i < v.size(); i++){
        check[i] = true;                //q에서 바이러스 시작점인곳 체크
        virus_dfs(i+1,cnt+1);
        check[i] = false;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2)
                v.push_back({i,j});
        }
    virus_dfs(0,0);

    if(result == 2500)              //result가 시작값과 같다면 바이러스가 퍼질수 없으므로
        printf("-1");
    else
        printf("%d", result - 2);   //0부터가아니라 2부터 값이 시작했으므로 -2
}
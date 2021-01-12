#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, l, r;
int contry[51][51];
bool visit[51][51];
int dy[4] = {1,0,0,-1};
int dx[4] = {0,1,-1,0};
bool roop = true;
int result = 0;                         //결과값

void bfs(int y, int x){
    int sum = 0;
    vector<pair<int,int>> v;            //연합좌표
    queue<pair<int,int>> q;
    v.push_back({y,x});
    q.push({y,x});
    visit[y][x] = true;
    while(!q.empty()){
        int yy = q.front().first;
        int xx = q.front().second;
        sum += contry[yy][xx];          //연합으로 이루어질 좌표들의 합을 저장함
        q.pop();
        for(int i = 0; i < 4; i ++){
            int yyy = yy + dy[i];
            int xxx = xx + dx[i];
            int dif = abs(contry[yy][xx] - contry[yyy][xxx]);   //기존나라좌표와 이동나라좌표 사이의 차이
            if(0 <= yyy && yyy < n && 0 <= xxx && xxx < n && visit[yyy][xxx] == false && l <= dif && dif <= r){     //범위안에있고, 아직방문하지않았을 때, 차이가 l와 r사이
                v.push_back({yyy,xxx});
                q.push({yyy,xxx});
                visit[yyy][xxx] = true;
            }
        }
    }
    //while이 끝나면 bfs() 의 시작점 나라과 연합나라들을 돌았음
    if(v.size() >= 2){                          //연합국이 있다는 뜻
        for(int i = 0; i < v.size(); i++)
            contry[v[i].first][v[i].second] = sum / v.size();
        roop = true;
    }
}

int main(){
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &contry[i][j]);
    while(roop){
        roop = false;                           //bfs가 한번도 실행되지 않았다면 roop값은 false이므로 while문이 안돌아감
        memset(visit, false, sizeof(visit));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(visit[i][j] == false)
                    bfs(i,j);
        if(!roop)
            break;
        result++;
    }
    printf("%d", result);
}
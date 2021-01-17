#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, u, v;
int board[101] = {0};           //보드판
int visit[101] = {0};           //방문여부, 횟수
int dice[6] = {1,2,3,4,5,6};    //주사위 이동
queue<int> q;

int bfs(){
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int next = x + dice[i];     //다음으로 갈 수 있는 곳
            if(next == 100)
                return visit[x] + 1;            //100이면 도착이므로 직전 횟수 + 1을 리턴 
            if(board[next] != next)
                next = board[next];             //next 값을 뱀이나 사다리가 있을 수도 있으므로 다르면 값을 변경
            if(visit[next] == 0){               //아직 방문하지 않았다면
                visit[next] = visit[x] + 1;     //이전 횟수에 +1
                q.push(next);                   //q에 push
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 100; i++)
        board[i] = i;           //index i번째는 i를 가르킴
    for(int i = 0; i < n+m; i++){
        scanf("%d %d", &u, &v);
        board[u] = v;           //index u는 v로 이동하므로 u번째는 v를 가르킴
    }
    printf("%d", bfs());
    return 0;
}
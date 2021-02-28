#include <iostream>
#include <set>
#include <queue>

using namespace std;

int n,m, input;
int graph[201][201];
bool visit[201] = {false,};
set<int> s;
queue<int> q;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &graph[i][j]);
    for(int i = 1; i <= m; i++){
        scanf("%d", &input);
        s.insert(input);                
    }
    q.push(input);                  //아무 도시나 queue에 대입              
    s.erase(input);                 //해당 도시 set에서 제거
    visit[input] = true;
    while(!q.empty()){
        int city = q.front();
        q.pop();
        s.erase(city);                                      //집합에서 도시 제거
        for(int i = 1; i <= n; i++){
            if(graph[city][i] && visit[i] == false){     //도시와 길이 연결된 곳 && 아직 방문하지 않은 곳
                q.push(i);                                  //queue에 도시 추가
                visit[i] = true;                            //방문여부 체크
            }
        }
    }
    if(s.empty())
        printf("YES");
    else
        printf("NO");
}
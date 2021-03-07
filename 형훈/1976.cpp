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
    q.push(input);                  //�ƹ� ���ó� queue�� ����              
    s.erase(input);                 //�ش� ���� set���� ����
    visit[input] = true;
    while(!q.empty()){
        int city = q.front();
        q.pop();
        s.erase(city);                                      //���տ��� ���� ����
        for(int i = 1; i <= n; i++){
            if(graph[city][i] && visit[i] == false){     //���ÿ� ���� ����� �� && ���� �湮���� ���� ��
                q.push(i);                                  //queue�� ���� �߰�
                visit[i] = true;                            //�湮���� üũ
            }
        }
    }
    if(s.empty())
        printf("YES");
    else
        printf("NO");
}
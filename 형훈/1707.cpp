#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int k,v,e;
int tmp1,tmp2;
bool result = true;
vector<vector<int>> vec;
vector<int> visit;

void bfs(int a){
    queue<int> q;   
    q.push(a);           //마지막으로 대입한 점 한개를 queue에 대입
    visit[a] = 1;        //방문여부를  체크
    while(!q.empty()){
        int next = q.front();   //q의 첫번째 값
        q.pop();                //q에서 제외
        for(int i = 0; i < vec[next].size(); i++){      //해당 점과 연결되있는 선 갯수 만큼
            if(visit[vec[next][i]] == 0){       //아직 방문을 안했다면
                q.push(vec[next][i]);
                visit[vec[next][i]] = 3 - visit[next];    //3 에서 값을 빼면 를 하면 1과 2중 하나의 값이 반복되며 나옴
            }
            else{   //이미 방문했던 점이라면
                if(visit[vec[next][i]] != 3 - visit[next])  //3에서 뺀값이 다르다면 이분그래프가 아님
                    result = false;
            }
        }
    }
}

int main(){
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d", &v, &e);
        vec.assign(v+1, vector<int>(0,0));      //vec 초기화
        visit.assign(v+1, 0);                   //visit 초기화
        result = true;
        for(int j = 0; j < e; j++){
            scanf("%d %d", &tmp1, &tmp2);
            vec[tmp1].push_back(tmp2);
            vec[tmp2].push_back(tmp1);
        }
        for(int j = 1; j <= v; j++)
            if(visit[j] == 0 && vec[j].size() > 0)
                bfs(j);
        if(result)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
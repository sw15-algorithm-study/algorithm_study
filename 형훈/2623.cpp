#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<int> v[1001];
int in[1001];
int visit[1001][1001];

queue<int> q;
vector<int> r;

int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        int before;
        for(int j = 0; j < num; j++) {
            int temp;
            scanf("%d", &temp);
            if(j == 0) 
                before = temp;
            else{          //중복 체크
                visit[before][temp] = 1;
                in[temp]++;
                v[before].push_back(temp);
                before = temp;
            }
        }
    }
  // in개수세기
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        r.push_back(cur);
        for(int i = 0; i < v[cur].size(); i++) {
            in[v[cur][i]]--;
            if(in[v[cur][i]] == 0)
            q.push(v[cur][i]);
        }
    }
    if(r.size() != n)
        printf("0");
    else
        for(int i = 0; i < n; i++)
            printf("%d\n", r[i]);
}
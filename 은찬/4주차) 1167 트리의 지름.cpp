#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[100001];
vector<bool> visited(100001, false);
int answer = 0;
int V = 0;
int end_point = 0;

void dfs(int start, int sum){
    if(visited[start]){
        return;
    }

    visited[start] = true;

    if(answer < sum){
        answer = sum;
        end_point = start;
    }

    for(int i = 0; i < tree[start].size(); i++){
        dfs(tree[start][i].first, sum + tree[start][i].second);
    }
}

int main(void){
    cin >> V;

    //트리 만들기
    for(int i = 0; i < V; i++){
        int N, tmp, target = 0, dist = 0;

        cin >> N;

        while(1){
            cin >> target;
            
            if(target == -1){
                break;
            }
            cin >> dist;
            tree[N].push_back(make_pair(target, dist));
        }    
    }

    //임의의 정점에서 가장 멀리 있는 정점 구하기
    dfs(1, 0);
    answer = 0;
    
    //방문 여부 초기화
    for(int i = 1; i <= V; i++){
        visited[i] = false;
    }

    //end_point와 가장 멀리 있는 정점 구하기
    dfs(end_point, 0);
    
    cout << answer << endl;
    return 0;
}
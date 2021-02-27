#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    int N, M;
    bool check = false;
    vector<vector<int>> city(201, vector<int>(201, 0));
    vector<bool> visited(201, false);
    vector<int> plan;
    queue<int> q;
    
    cin >> N >> M;

    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> city[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        int tmp;
        cin >> tmp;
        plan.push_back(tmp);
    }

    q.push(plan[0]);

    //BFS
    while(!q.empty()){
        int start = q.front();
        q.pop();

        visited[start] = true;

        for(int i = 1; i <= N; i++){
            if(city[start][i] && !visited[i]){
                q.push(i);
            }
        }
    }

    for(int i = 0; i < plan.size(); i++){
        if(!visited[plan[i]]){
            check = true;
            break;
        }
    }

	if(!check){
		cout << "YES";
	}
	else{
		cout << "NO";
	}

    return 0;
}
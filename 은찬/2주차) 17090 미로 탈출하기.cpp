#include <iostream>
#include <vector>
#include <string>

using namespace std;

char board[500][500];
vector<vector<int>> visited(500, vector<int>(500, -1));
int N, M;
int answer = 0;

int dfs(int x, int y){
	if(x < 0 || x >= N || y < 0 || y >= M){
		return 1;
	}
	
	if(visited[x][y] != -1){
		return visited[x][y];	
	}
	else{
		visited[x][y] = 0;
	}
	
	if(board[x][y] == 'U'){
		return visited[x][y] = dfs(x - 1, y);
	}
	else if(board[x][y] == 'R'){
		return visited[x][y] = dfs(x, y + 1);
	}
	else if(board[x][y] == 'D'){
		return visited[x][y] = dfs(x + 1, y);
	}
	else if(board[x][y] == 'L'){
		return visited[x][y] = dfs(x, y - 1);
	}
}

int main() {
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		
		for(int j = 0; j < M; j++){
			board[i][j] = s[j];
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			answer += dfs(i, j);
		}
	}
	cout << answer;
	return 0;
}
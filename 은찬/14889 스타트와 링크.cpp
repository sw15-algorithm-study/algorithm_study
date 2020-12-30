#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool team[20];
int board[20][20];
int answer = 9999999999;
int n = 0;

void dfs(int start, int count){
	if(count == n / 2){
		vector<int> s, l;
		int ss = 0, ls = 0;
		
		for(int i = 0; i < n; i++){
			if(team[i]){
				s.push_back(i);
			}
			else{
				l.push_back(i);
			}
		}
		
		for(int i = 0; i < n / 2; i++){
			for(int j = 0; j < n / 2; j++){
				ss += board[s[i]][s[j]];
				ls += board[l[i]][l[j]];
			}
		}
		
		if(abs(ss - ls) < answer){
			answer = abs(ss - ls);
		}
		return;
	}
	else{
		for(int i = start; i < n; i++){
			if(!team[i]){
				team[i] = true;
				dfs(i, count + 1);
				team[i] = false;
			}
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	
	dfs(0, 0);
	cout << answer;
	return 0;
}
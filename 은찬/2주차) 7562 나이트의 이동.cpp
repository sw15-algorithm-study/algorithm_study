#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, I, current_x, current_y, target_x, target_y;
	int arr_x[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int arr_y[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> I;
		cin >> current_x >> current_y;
		cin >> target_x >> target_y;
		
		vector<vector<bool>> visited(I, vector<bool>(I, false));
		queue<pair<int, int>> q;
		int answer = 0;
		bool exit = false;
		
		q.push(make_pair(current_x, current_y));
		visited[current_x][current_y] = true;

		while(!q.empty()){
			int size = q.size();
			for(int j = 0; j < size; j++){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				
				if(x == target_x && y == target_y){
					cout << answer << endl;
					exit = true;
					break;
				}
				else{
					for(int k = 0; k < 8; k++){
						if(x + arr_x[k] >= 0 && x + arr_x[k] < I && y + arr_y[k] >= 0 && y + arr_y[k] < I && !visited[x + arr_x[k]][y + arr_y[k]]){
							q.push(make_pair(x + arr_x[k], y + arr_y[k]));
							visited[x + arr_x[k]][y + arr_y[k]] = true;
						}
					}
				}
			}

			if(exit){
				break;
			}
			answer++;
		}
	}
	return 0;
}
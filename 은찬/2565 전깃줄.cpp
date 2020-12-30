#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector<pair<int, int>> v;
	vector<int> dp(501, 1);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(v[j].second < v[i].second){
				if(dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	
	cout << n - *max_element(dp.begin(), dp.end()) << endl;
	return 0;
}
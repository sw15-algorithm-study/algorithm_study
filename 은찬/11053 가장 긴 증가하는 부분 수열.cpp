#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int arr[1001];
	vector<int> dp(1001, 0);
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++){
		if(dp[i] == 0){
			dp[i] = 1;
		}
		for(int j = 0; j < n; j++){
			if(arr[j] < arr[i]){
				if(dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}
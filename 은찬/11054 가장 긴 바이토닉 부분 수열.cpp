#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, answer = 0;
	vector<int> left(1001, 1), right(1001, 1);
	int arr[1001];
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(arr[j] < arr[i]){
				if(left[i] < left[j] + 1){
					left[i] = left[j] + 1;
				}
			}
		}
	}
	
	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j >= i; j--){
			if(arr[j] < arr[i]){
				if(right[i] < right[j] + 1){
					right[i] = right[j] + 1;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		if(answer < left[i] + right[i]){
			answer = left[i] + right[i];
		}
	}
	cout << answer - 1;
	return 0;
}
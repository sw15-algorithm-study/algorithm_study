#include <iostream>
using namespace std;
int zero_one[41][3] = { {1,0},{0,1},{1,1} };
int main() {
	int t;	
	int n;
	scanf("%d", &t);
	for (int i = 3; i < 41; i++) {
		zero_one[i][0] = zero_one[i - 1][0] + zero_one[i - 2][0]; 
		zero_one[i][1] = zero_one[i - 1][1] + zero_one[i - 2][1]; 
	}
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d %d\n", zero_one[n][0], zero_one[n][1]);
	}
	return 0;
}

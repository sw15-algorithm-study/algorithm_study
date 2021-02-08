#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{	
	int arr[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
	int sum = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); ++i) {
		int index = s[i] - 65;
		sum += arr[index];
	}
	printf("%d", sum);
	return 0;
}
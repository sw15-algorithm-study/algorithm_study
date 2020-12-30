#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	int n;
	int arr[26] = {0, };
	stack<double> operand;
	string s;
	
	cin >> n;
	cin >> s;
	
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z'){
			operand.push(arr[s[i] - 'A']);
		}
		else{
			double b = operand.top();
			operand.pop();
			double a = operand.top();
			operand.pop();
			
			if(s[i] == '+'){
				operand.push(a + b);
			}
			else if(s[i] == '-'){
				operand.push(a - b);
			}
			else if(s[i] == '*'){
				operand.push(a * b);
			}
			else if(s[i] == '/'){
				operand.push(a / b);
			}
		}
	}
	printf("%.2f", operand.top());
	return 0;
}
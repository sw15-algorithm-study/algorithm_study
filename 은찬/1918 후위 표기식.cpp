#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string s;
	stack<char> stk;
	
	cin >> s;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z'){
			cout << s[i];
		}
		else{
			if(stk.empty()){
				stk.push(s[i]);
			}
			else{
				if(s[i] == '('){
					stk.push(s[i]);
				}
				else if(s[i] == ')'){
					while(stk.top() != '('){
						cout << stk.top();
						stk.pop();
					}
					stk.pop();
				}
				else if(s[i] == '+' || s[i] == '-'){
					while(1){
						if(stk.empty() || stk.top() == '('){
							stk.push(s[i]);
							break;
						}
						else{
							cout << stk.top();
							stk.pop();
						}
					}
				}
				else if(s[i] == '*' || s[i] == '/'){
					if(stk.top() == '('){
						stk.push(s[i]);
					}
					else if(stk.top() == '*' || stk.top() == '/'){
						cout << stk.top();
						stk.pop();
						stk.push(s[i]);
					}
					else{
						stk.push(s[i]);
					}
				}
			}
		}
	}
	
	while(!stk.empty()){
		cout << stk.top();
		stk.pop();
	}
	return 0;
}
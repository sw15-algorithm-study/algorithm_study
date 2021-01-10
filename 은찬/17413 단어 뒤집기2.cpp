#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
	string s, answer = "";
	stack<char> stk;
	bool check = false;
	
	getline(cin, s);
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '<'){
			while(!stk.empty()){
				answer += stk.top();
				stk.pop();
			}
			check = true;
			answer += '<';
		}
		else if(s[i] == '>'){
			check = false;
			answer += '>';
		}
		else{
			if(check){
				answer += s[i];
			}
			else{
				if(s[i] == ' '){
					while(!stk.empty()){
						answer += stk.top();
						stk.pop();
					}
					answer += ' ';
				}
				else{
					stk.push(s[i]);	
				}
			}
			
		}
	}
	while(!stk.empty()){
		answer += stk.top();
		stk.pop();
	}
	cout << answer << endl;
	return 0;
}
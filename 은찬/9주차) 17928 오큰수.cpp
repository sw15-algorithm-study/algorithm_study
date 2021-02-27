#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void){
    int n;

    cin >> n;
    
    vector<int> NGE(n);
    vector<int> ans(n);
    stack<int> stk;
    
    for(int i = 0; i < n; i++){
        cin >> NGE[i];
    }

    stk.push(0);

    for(int i = 1; i < n; i++){
        if(stk.empty()){
            stk.push(i);
        }

        while(!stk.empty() && NGE[stk.top()] < NGE[i]){
            ans[stk.top()] = NGE[i];
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()){
        ans[stk.top()] = -1;
        stk.pop();
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
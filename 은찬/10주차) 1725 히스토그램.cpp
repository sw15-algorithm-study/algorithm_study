// 이해 못해서 참고한 사이트 https://j2wooooo.tistory.com/74
// 스택과 분할 정복 사용
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N, ans = 0;
    stack<int> stk;

    cin >> N;

    vector<int> histogram(N + 2, 0);

    for(int i = 1; i <= N; i++){
        cin >> histogram[i];
    }

    stk.push(0);

    for(int i = 1; i <= N + 1; i++){
        while(!stk.empty() && histogram[stk.top()] > histogram[i]){
            int height = histogram[stk.top()];
            stk.pop();
            int width = i - stk.top() - 1;

            ans = max(ans, height * width);
        }
        stk.push(i);
    }

    cout << ans;

    return 0;
}
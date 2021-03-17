#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, result = 0, input;
vector<int> v;
stack<int> s;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        v.push_back(input);
    }
    v.push_back(0);
    for(int i = 0; i < v.size(); i++){
        while(!s.empty() && v[s.top()] >= v[i]){
            int idx = s.top();
            s.pop();
            int width;
            if(s.empty())               //idx번째 판자 왼쪽에 판자가 하나도 안남은 경우
                width = i;
            else
                width = (i-s.top() - 1);
            result = max(result, v[idx] * width);
        }
        s.push(i);
    }
    printf("%d", result);
}
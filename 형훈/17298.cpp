#include<iostream>
#include<vector>
#include<stack>
 
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    vector<int> v(n), ret(n);
    stack<int> s;
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && s.top() <= v[i])
            s.pop();
        if (s.empty())
            ret[i] = -1;
        else
            ret[i] = s.top();
        s.push(v[i]);
    }
    for(auto a : ret)
        printf("%d ",a);
}

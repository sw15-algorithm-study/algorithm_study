#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n, input, result = 0;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
        result += v[i] * (n-i);
    printf("%d", result);
}
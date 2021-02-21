#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;

int main(){
    int t, n;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    for(int i = 3; i < 100; i++)
        v.push_back(v[i-2] + v[i-3]);
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        printf("%lld\n", v[n-1]);
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<long long> v;
int main(){
    int n;
    scanf("%d", &n);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    for(int i = 3; i <= n; i++){
        v.push_back((v[i-1]+v[i-2])%15746);
    }
    printf("%d", v[n]);
    return 0;
}
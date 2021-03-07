#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, ans = 0;
    vector<int> v;

    cin >> N;

    for(int i = 0; i < N; i++){
        int w;
        cin >> w;
        v.push_back(w);
    }

    sort(v.rbegin(), v.rend());

    for(int i = 0; i < N; i++){
        int weight = v[i] * (i + 1);
        
        ans = ans < weight ? weight : ans;
    }

    cout << ans;
    
    return 0;
}
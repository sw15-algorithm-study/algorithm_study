#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void){
    int N;
    long long ans = 0, max = LONG_MAX;
    vector<long long> oil, city;

    cin >> N;
    
    //거리
    for(int i = 0; i < N - 1; i++){
        int tmp;
        cin >> tmp;
        city.push_back(tmp);
    }

    //기름값
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        oil.push_back(tmp);
    }

    //greedy
    for(int i = 0; i < N; i++){
        if(max > oil[i]){
            max = oil[i];
        }
        ans += max * city[i];
    }
    cout << ans;
    
    return 0;
}
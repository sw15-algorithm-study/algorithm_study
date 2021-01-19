#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    long long N, M;
    long long left = 0, right = 0, mid = 0, before = 0, answer = 0;
    vector<long long> v;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        long long t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    right = v.back() * M;

    while(1){
        long long tmp = 0;
        mid = (left + right) / 2;

        for(int i = 0; i < N; i++){
            tmp += mid / v[i];
        }

        if(before == mid){
            answer = mid + 1;
            break;
        }
        else if(tmp < M){
            left = mid;
        }
        else{
            right = mid;
        }
        before = mid;
    }
    cout << answer;
    return 0;
}
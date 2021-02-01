#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, K, ans = 0, index = 0;
    vector<int> v;

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        
        //K보다 큰 동전 버리기
        if(tmp <= K){
            v.push_back(tmp);
        }
    }

    //내림차순 정렬
    sort(v.rbegin(), v.rend());

    //그리디 알고리즘
    while(current != K){
        int q = K / v[index];
        current += q * v[index];
        ans += q;
        K /= v[index++];
    }

    cout << ans;

    return 0;
}
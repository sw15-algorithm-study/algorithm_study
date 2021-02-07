#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N, ans = 0;
    vector<int> time;

    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        time.push_back(tmp);
    }

    //오름차순 정렬
    sort(time.begin(), time.end());

    //최소 시간 구하기
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            ans += time[j];
        }
    }
    cout << ans;

    return 0;
}
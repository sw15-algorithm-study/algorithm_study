#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N;
    vector<pair<int, int>> f(40);

    cin >> N;

    f[0].first = 1;
    f[0].second = 0;
    f[1].first = 0;
    f[1].second = 1;

    //DP로 미리 40까지 0과 1의 개수를 구해놓기
    for(int i = 2; i <= 40; i++){
        f[i].first = f[i - 1].first + f[i - 2].first;
        f[i].second = f[i - 1].second + f[i - 2].second;
    }

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        
        cout << f[tmp].first << " " << f[tmp].second << endl;
    }
    return 0;
}
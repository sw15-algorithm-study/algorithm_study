#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N, K;
    int W[101], C[101];
    vector<vector<int>> v(101, vector<int>(100001, 0));
    
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++){
        cin >> W[i] >> C[i];
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(W[i] > j){
                v[i][j] = v[i - 1][j];
            }
            else{
                v[i][j] = max(C[i] + v[i - 1][j - W[i]], v[i - 1][j]);
            }
        }
    }
    cout << v[N][K];
    return 0;
}
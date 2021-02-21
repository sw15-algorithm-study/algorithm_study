#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(void){
    int T;
    long long v[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

    cin >> T;

    for(int i = 11; i < 101; i++){
        v[i] = v[i - 2] + v[i - 3];
    }

    for(int i = 0; i < T; i++){
        int tmp;
        cin >> tmp;
        cout << v[tmp] << endl;
    }

    return 0;
}
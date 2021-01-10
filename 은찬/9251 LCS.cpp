#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    vector<vector<int>> v(1001, vector<int>(1001, 0));
    string a, b;
    
    cin >> a >> b;
    
    if(a.size() > b.size()){
        swap(a, b);
    }
    
    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i - 1] == b[j - 1]){
                v[i][j] = v[i - 1][j - 1] + 1;
            }
            else{
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    cout << v[a.size()][b.size()];
    return 0;
}
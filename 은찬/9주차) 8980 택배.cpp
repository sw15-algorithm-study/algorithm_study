#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool asc(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.first.second == b.first.second){
        return a.first.first < b.first.first;
    }
    else{
        return a.first.second < b.first.second;
    }
}

int main(void){
    int N, C, M, current = 0, ans = 0;

    cin >> N >> C >> M;

    vector<pair<pair<int, int>, int>> box;
    vector<int> v(N + 1, 0);

    for(int i = 0; i < M; i++){
        int start, target, weight;
        cin >> start >> target >> weight;
        box.push_back({{start, target}, weight});
    }
    
    sort(box.begin(), box.end(), asc);

    for(int i = 0; i < box.size(); i++){
        int current = 0;
        int start = box[i].first.first;
        int target = box[i].first.second;
        int weight = box[i].second;

        for(int j = start; j < target; j++){
            current = max(current, v[j]);
        }

        current = min(C - current, weight);
        ans += current;

        for(int j = start; j < target; j++){
            v[j] += current;
        }
    }
    
    cout << ans;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool asc(pair<int, int> a, pair<int, int> b){
    //끝나는 시간을 기준으로 오름차순
    //만약 끝나는 시간이 같다면 시작 시간을 기준으로 오름차순
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(void){
    int N, ans = 0, last_time = 0;
    vector<pair<int, int>> v;

    cin >> N;

    for(int i = 0; i < N; i++){
    	int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), asc);

    for(int i = 0; i < v.size(); i++){
    	if(last_time <= v[i].first){
    		last_time = v[i].second;
    		ans++;
    	}
    }
    
    cout << ans;

    return 0;
}
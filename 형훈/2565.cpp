#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
int n;
int line[500];
int dp[100];
int main(){
    int tmp1, tmp2, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &tmp1, &tmp2);
        v.push_back(make_pair(tmp1, tmp2));
    }
    sort(v.begin(), v.end());       //first값으로 배열 정렬
    for(int i = 0; i < n; i++){     //가장 긴 오름차순 길이 구함
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[i].second > v[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        sum = max(sum, dp[i]);
    }
    printf("%d", n - sum);
}
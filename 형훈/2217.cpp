#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum = 0, max_value;
vector<int> v;

int main(){
    scanf("%d", &n);
    int input;
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        sum += input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());                       //내림차순 정렬
    for(int i = 0; i < v.size(); i++)
        max_value = max(max_value, v[i] * n--);     //로프를 n개 사용했을 때 들수 있는 최대중량 계산
    printf("%d", max_value);
}
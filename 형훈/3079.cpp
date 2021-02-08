#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[100001];
long long low, high, result;

int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    sort(arr, arr + n);
    low = 0;
    high = m * arr[n - 1];                  
    result = m * arr[n - 1];
    while(low <= high){
        long long mid = (low + high) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++)
            sum += mid / arr[i];        //mid시간안에 몇명이 입국심사대를 통과할 수 있나
        if (sum >= m) {                 //통과할 수 있는 사람이 통과해야할 사람보다 적다면
            result = min(result, mid); 
            high = mid - 1; 
        }
        else
            low = mid + 1;
    }
    printf("%lld", result);
}
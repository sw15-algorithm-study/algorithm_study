#include <iostream>

using namespace std;

int n, k, count, result = 0;
int arr[11];
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    count = n-1;                //가장 큰 숫자 부터
    while(k > 0){
        if(arr[count] <= k){
            k -= arr[count];
            result++;
        }
        if(arr[count] > k)
            count--;
    }
    printf("%d", result);
}
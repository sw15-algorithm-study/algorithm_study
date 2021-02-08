#include <iostream>

using namespace std;

int n, b, c;
int a[1000001];
long long result;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d %d", &b, &c);
    for(int i = 0; i < n; i++){
        a[i] -= b;              //주감독관 감독 가능학생
        result++;               //감독관 + 1
        if(a[i] > 0){
            result += (a[i] / c);   //부감독관 감독 가능학생
            if(a[i] % c > 0)        //나누어 떨어지지 않으면
                result++;           //부감독관 + 1
        }
    }
    printf("%lld", result);
}
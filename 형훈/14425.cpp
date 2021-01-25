#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int n, m;
string str;
map<string, bool> mp;
int result = 0;

int main(){
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++){
        cin >> str;
        mp[str] = true;            // == mp = {{str,true}}
    }
    for(int i = 0; i < m; i++){
        cin >> str;
        if(mp[str])
            result++;
    }
    printf("%d", result);
}
/*
1. map<타입, 타입> 변수명 :: 선언 방식
2. 변수명이 m이라고 가정할 때
m[0] = 1과 m1 = { {0,1} }은 같은 의미
그 외에는 Vector STL과 같은 함수 방식을 이루고 있다.
3. 특이한 점이 있다면 map STL에서는 map<string, 타입> m;을 설정하면
m["abc"] = 값 이런식으로 [ ]사이에 string이 들어갈 수 있다.
*/
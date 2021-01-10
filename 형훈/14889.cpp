#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int s[20][20] = {0};
int team[20] = {0};  //같은팀 표시
int value = 10000;
void maketeam(int a, int num){
    int sum_start = 0, sum_link = 0;
    vector<int> start_v;
    vector<int> link_v;
    if(num == n/2){       //n/2명이 한팀으로 정해지면
        for(int i = 0; i < n; i++){
            if(team[i])     //같은팀끼리 한벡터에 넣기
                start_v.push_back(i);
            else{
                link_v.push_back(i);
            }       
        }
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                sum_start += s[start_v[i]][start_v[j]];
                sum_link += s[link_v[i]][link_v[j]];
            }
        }
        value = min(value, abs(sum_start-sum_link));    //현재 값과 팀능력치의 차이중 작은값을 저장
        return;
    }
    for(int i = a; i < n; i++){
        if(team[i])
            continue;
        else{
            team[i] = 1;
            maketeam(i, num+1);
            team[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &s[i][j]);
    maketeam(0,0);
    printf("%d", value);
    return 0;
}
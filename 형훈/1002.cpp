#include <iostream>
using namespace std;

int t, x1, y1, r1, x2, y2, r2;

int main(){
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int a = (x1-x2)*(x1-x2);
        int b = (y1-y2)*(y1-y2);
        int dis = a+b;
        int minus_r = (r1-r2)*(r1-r2);
        int plus_r = (r1+r2)*(r1+r2);
        if(dis == 0){                               //두 원의 점이 같을 때
            if(minus_r == 0)
                printf("-1\n");                     //거리의 차가 0이면 같은 두개의 원
            else
                printf("0\n");                      //거리의 차가 0이 아니면 하나의 원이 나머지 원 안에 존제;
        }
        else if(dis > minus_r && dis < plus_r)      //원이 2점에서 접할 때    
            printf("2\n");
        else if(dis == minus_r || dis == plus_r)    //거리의 합 또는 차가 거리와 같을 때 (외접or내접)
            printf("1\n");
        else                                        
            printf("0\n");
    }
}
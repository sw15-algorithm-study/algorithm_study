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
        if(dis == 0){                               //�� ���� ���� ���� ��
            if(minus_r == 0)
                printf("-1\n");                     //�Ÿ��� ���� 0�̸� ���� �ΰ��� ��
            else
                printf("0\n");                      //�Ÿ��� ���� 0�� �ƴϸ� �ϳ��� ���� ������ �� �ȿ� ����;
        }
        else if(dis > minus_r && dis < plus_r)      //���� 2������ ���� ��    
            printf("2\n");
        else if(dis == minus_r || dis == plus_r)    //�Ÿ��� �� �Ǵ� ���� �Ÿ��� ���� �� (����or����)
            printf("1\n");
        else                                        
            printf("0\n");
    }
}
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, d, max_value = 0;
int map[16][16];
int real_map[16][16];
int result = 0;
void copymap(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            map[i][j] = real_map[i][j];
}
pair<int,int> find(int i, int a){    //y��ǥ, �ü��� ��ġ
    pair<int,int> p;
    p.first = 100;
    if(map[i][a]){                  //�ٷξտ� ���� ������
        p.first = i;                //������ �� ���
        p.second = a;
    }
    else{                           //�Ÿ��ȿ� �����ֳ� Ȯ��
        int check = true;
        for(int j = 1; j < d; j++){
            int x = 0;
            while(check && x <= j){
                if(0 <= i-x && i-x < n && 0 <= a-(j-x) && a-(j-x) < m){
                    if(map[i-x][a-(j-x)]){
                        p.first = i-x;
                        p.second = a-(j-x);
                        x++;
                        check = false;
                    }
                    else
                        x++;
                }
                else
                    x++;
            }
            x--;
            while(check && x >= 0){
                if(0 <= i-x && i-x < n && 0 <= a+(j-x) && a+(j-x) < m){
                    if(map[i-x][a+(j-x)]){
                        p.first = i-x;
                        p.second = a+(j-x);
                        x--;
                        check = false;
                    }
                    else
                        x--;
                }
                else
                    x--;
            }
        }
    }
    return p;
}
void defense(int a, int b, int c){
    pair<int,int> p1, p2, p3;
    for(int i = n-1; i >= 0; i--){      //�Ʒ��� ���� ����
        p1 = find(i,a);                 //������ ��ǥ �޾ƿ�
        p2 = find(i,b);
        p3 = find(i,c);
        if(p1.first != 100){                            //������ ���� �ִٸ�
            result++;
            map[p1.first][p1.second] = 0;       
        }
        if(p2.first != 100 && map[p2.first][p2.second]){//������ ���� �ְ� �տ��� ������ ǥ���� �ƴϸ�
            result++;
            map[p2.first][p2.second] = 0;  
        }
        if(p3.first != 100 && map[p3.first][p3.second]){//������ ���� �ְ� �տ��� ������ ǥ���� �ƴϸ�
            result++;
            map[p3.first][p3.second] = 0;  
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &d);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &real_map[i][j]);
    for(int i = 0; i < m; i++)
        for(int j = i+1; j < m; j++)
            for(int k = j+1; k < m; k++){
                result = 0;
                copymap();
                defense(i,j,k);
                max_value = max(max_value, result);
            }
    printf("%d", max_value);
}
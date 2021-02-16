#include <iostream>
using namespace std;

int n, m, x, y, k, input, current_x, current_y;
int map[21][21] = {0,};
int dice_index[6] = {0,4,5,1,2,3};  //�ʱ� �ֻ������� -> ��[0], ��[1], �Ʒ�[2], ��[3], ������[4], ����[5]
int dice[6] = {0,};
void change_index(int dir){     //�ֻ��� ����(����) ����
    if(dir == 1){               //����
        int tmp1, tmp2;
        tmp1 = dice_index[0];
        tmp2 = dice_index[2];
        dice_index[0] = dice_index[5];
        dice_index[2] = dice_index[4];
        dice_index[4] = tmp1;
        dice_index[5] = tmp2;
    }
    else if(dir == 2){          //����
        int tmp1, tmp2;
        tmp1 = dice_index[0];
        tmp2 = dice_index[2];
        dice_index[0] = dice_index[4];
        dice_index[2] = dice_index[5];
        dice_index[4] = tmp2;
        dice_index[5] = tmp1;
    }
    else if(dir == 3){          //����
        int tmp;
        tmp = dice_index[0];
        dice_index[0] = dice_index[1];
        dice_index[1] = dice_index[2];
        dice_index[2] = dice_index[3];
        dice_index[3] = tmp;
    }
    else if(dir == 4){          //����
        int tmp;
        tmp = dice_index[3];
        dice_index[3] = dice_index[2];
        dice_index[2] = dice_index[1];
        dice_index[1] = dice_index[0];
        dice_index[0] = tmp;
    }
}
void change_value(){            //���� ���� �ٴ� �� ��
    if(map[current_x][current_y] == 0)                  //���� �� 0�̸�
        map[current_x][current_y] = dice[dice_index[2]]; 
    else{                                               //���� �� 0�ƴϸ�
        dice[dice_index[2]] = map[current_x][current_y];
        map[current_x][current_y] = 0;
    }
}
void move(int num){
    if(num == 1){               //����
        if(0 <= current_x && current_x < n && 0 <= current_y+1 && current_y+1 < m){     //�����ȿ�������
            current_y++;                                    //��ǥ�̵�                        
            change_index(num);                              //�ֻ��� ���º���                           
            change_value();                                 //���� ���� �ٴ� �� ��
            printf("%d\n", dice[dice_index[0]]);            //���� �� ���
        }
        else
            return; 
    }
    else if(num == 2){          //����
        if(0 <= current_x && current_x < n && 0 <= current_y-1 && current_y-1 < m){
            current_y--;
            change_index(num);
            change_value();
            printf("%d\n", dice[dice_index[0]]);
        }
        else
            return; 
    }
    else if(num == 3){          //����
        if(0 <= current_x-1 && current_x-1 < n && 0 <= current_y && current_y < m){
            current_x--;
            change_index(num);
            change_value();
            printf("%d\n", dice[dice_index[0]]);
        }
        else
            return;
    }
    else if(num == 4){          //����
        if(0 <= current_x+1 && current_x+1 < n && 0 <= current_y && current_y < m){
            current_x++;
            change_index(num);
            change_value();
            printf("%d\n", dice[dice_index[0]]);
        }
        else
            return;    
    }
}

int main(){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    current_x = x;
    current_y = y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);
    for(int i = 0; i < k; i++){
        scanf("%d", &input);
        move(input);
    }
}
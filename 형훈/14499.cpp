#include <iostream>
using namespace std;

int n, m, x, y, k, input, current_x, current_y;
int map[21][21] = {0,};
int dice_index[6] = {0,4,5,1,2,3};  //초기 주사위상태 -> 위[0], 앞[1], 아래[2], 뒤[3], 오른쪽[4], 왼쪽[5]
int dice[6] = {0,};
void change_index(int dir){     //주사위 방향(상태) 변경
    if(dir == 1){               //동쪽
        int tmp1, tmp2;
        tmp1 = dice_index[0];
        tmp2 = dice_index[2];
        dice_index[0] = dice_index[5];
        dice_index[2] = dice_index[4];
        dice_index[4] = tmp1;
        dice_index[5] = tmp2;
    }
    else if(dir == 2){          //서쪽
        int tmp1, tmp2;
        tmp1 = dice_index[0];
        tmp2 = dice_index[2];
        dice_index[0] = dice_index[4];
        dice_index[2] = dice_index[5];
        dice_index[4] = tmp2;
        dice_index[5] = tmp1;
    }
    else if(dir == 3){          //북쪽
        int tmp;
        tmp = dice_index[0];
        dice_index[0] = dice_index[1];
        dice_index[1] = dice_index[2];
        dice_index[2] = dice_index[3];
        dice_index[3] = tmp;
    }
    else if(dir == 4){          //남쪽
        int tmp;
        tmp = dice_index[3];
        dice_index[3] = dice_index[2];
        dice_index[2] = dice_index[1];
        dice_index[1] = dice_index[0];
        dice_index[0] = tmp;
    }
}
void change_value(){            //지도 값과 바닥 값 비교
    if(map[current_x][current_y] == 0)                  //지도 값 0이면
        map[current_x][current_y] = dice[dice_index[2]]; 
    else{                                               //지도 값 0아니면
        dice[dice_index[2]] = map[current_x][current_y];
        map[current_x][current_y] = 0;
    }
}
void move(int num){
    if(num == 1){               //동쪽
        if(0 <= current_x && current_x < n && 0 <= current_y+1 && current_y+1 < m){     //범위안에있으면
            current_y++;                                    //좌표이동                        
            change_index(num);                              //주사위 상태변경                           
            change_value();                                 //지도 값과 바닥 값 비교
            printf("%d\n", dice[dice_index[0]]);            //윗면 값 출력
        }
        else
            return; 
    }
    else if(num == 2){          //서쪽
        if(0 <= current_x && current_x < n && 0 <= current_y-1 && current_y-1 < m){
            current_y--;
            change_index(num);
            change_value();
            printf("%d\n", dice[dice_index[0]]);
        }
        else
            return; 
    }
    else if(num == 3){          //북쪽
        if(0 <= current_x-1 && current_x-1 < n && 0 <= current_y && current_y < m){
            current_x--;
            change_index(num);
            change_value();
            printf("%d\n", dice[dice_index[0]]);
        }
        else
            return;
    }
    else if(num == 4){          //남쪽
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
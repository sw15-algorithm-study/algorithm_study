#include <iostream>

using namespace std;

int map[20][20] = {0,};

int checkwin(int y, int x, int color, int count, int dir){
    switch (dir){
    case 0:             //왼쪽에서 오른쪽
        if(count == 1)
            if(map[y][x-1] == color)    //첫번째 돌이 아니면 그만
                break;
        if(map[y][x+1] == color)            //다음 진행돌이 있다면 재귀
            count = checkwin(y,x+1,color,count+1,dir);
        break;
    case 1:             //왼쪽위에서 오른쪽 아래
        if(count == 1)
            if(map[y-1][x-1] == color)
                break;
        if(map[y+1][x+1] == color)
            count = checkwin(y+1,x+1,color,count+1,dir);
        break;
    case 2:             //왼쪽 밑에서 오른쪽 위
        if(count == 1)
            if(map[y+1][x-1] == color)
                break;
        if(map[y-1][x+1] == color)
            count = checkwin(y-1,x+1,color,count+1,dir);
        break;
    case 3:             //위쪽에서 아래쪽
        if(count == 1)
            if(map[y-1][x] == color)
                break;
        if(map[y+1][x] == color)
            count = checkwin(y+1,x,color,count+1,dir);
        break;
    }
    return count;
}

int main(){
    for(int i = 1; i < 20; i++)
        for(int j = 1; j < 20; j++)
            scanf("%d", &map[i][j]);
    for(int i = 1; i < 20; i++)
        for(int j = 1; j < 20; j++)
            for(int m = 1; m <= 2; m++)
                if(map[i][j] == m)
                    for(int k = 0; k < 4; k++)
                        if(checkwin(i,j,m,1,k) == 5){
                            printf("%d\n%d %d", m, i, j);
                            return 0;
                        }
    printf("0");
}
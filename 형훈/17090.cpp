#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char map[501][501];             //지도
int out[501][501] = {0};        //출발지점부터 끝나는 곳까지 흔적을 남김
bool result[250001] = {false};     //index값이 true이면 탈출 가능한 것임
int u[2] = {-1,0};
int r[2] = {0,1};
int d[2] = {1,0};
int l[2] = {0,-1};
int step = 1;                   //흔적
int num = 0;                 //탈출가능한 좌표 갯수

void dfs(int i, int j){
    if(!out[i][j])                  //아직 방문하지 않았다면
        out[i][j] = step;           //방문흔적 step값으로 남김
    int di, dj;
    switch (map[i][j])          //알파벳에 따라 변경값 설정
    {
    case 'U':
        di = i + u[0];      
        dj = j + u[1];
        if(0 <= di && di < n && 0 <= dj && dj < m){ //다음 좌표가 밖으로 나가지 않으면
            if(!out[di][dj])                        //다음 좌표가 아직 지나가지 않은 곳이면
                dfs(di,dj);
            else{                                   //이미 지나갔었다면
                if(result[out[di][dj]]){            //해당좌표에 남아있는 흔적이 탈출 가능한지 불가능한지 판단
                    num++;                          //탈출가능 흔적이 있다면 num값 증가
                    result[step] = true;            //시작했던 좌표도 true로 변경
                }
            }
        }
        else{                                       //좌표가 밖으로 나갔다면
            num++;
            result[step] = true;
        }
        break;
    case 'R':
        di = i + r[0];
        dj = j + r[1];
        if(0 <= di && di < n && 0 <= dj && dj < m){ //다음 좌표가 밖으로 나가지 않으면
            if(!out[di][dj])                        //다음 좌표가 아직 지나가지 않은 곳이면
                dfs(di,dj);
            else{                                   //이미 지나갔었다면
                if(result[out[di][dj]]){            //해당좌표에 남아있는 흔적이 탈출 가능한지 불가능한지 판단
                    num++;                          //탈출가능 흔적이 있다면 num값 증가
                    result[step] = true;            //시작했던 좌표도 true로 변경
                }
            }
        }
        else{                                       //좌표가 밖으로 나갔다면
            num++;
            result[step] = true;
        }
        break;
    case 'D':
        di = i + d[0];
        dj = j + d[1];
        if(0 <= di && di < n && 0 <= dj && dj < m){ //다음 좌표가 밖으로 나가지 않으면
            if(!out[di][dj])                        //다음 좌표가 아직 지나가지 않은 곳이면
                dfs(di,dj);
            else{                                   //이미 지나갔었다면
                if(result[out[di][dj]]){            //해당좌표에 남아있는 흔적이 탈출 가능한지 불가능한지 판단
                    num++;                          //탈출가능 흔적이 있다면 num값 증가
                    result[step] = true;            //시작했던 좌표도 true로 변경
                }
            }
        }
        else{                                       //좌표가 밖으로 나갔다면
            num++;
            result[step] = true;
        }
        break;
    case 'L':
        di = i + l[0];
        dj = j + l[1];
        if(0 <= di && di < n && 0 <= dj && dj < m){ //다음 좌표가 밖으로 나가지 않으면
            if(!out[di][dj])                        //다음 좌표가 아직 지나가지 않은 곳이면
                dfs(di,dj);
            else{                                   //이미 지나갔었다면
                if(result[out[di][dj]]){            //해당좌표에 남아있는 흔적이 탈출 가능한지 불가능한지 판단
                    num++;                          //탈출가능 흔적이 있다면 num값 증가
                    result[step] = true;            //시작했던 좌표도 true로 변경
                }
            }
        }
        else{                                       //좌표가 밖으로 나갔다면
            num++;
            result[step] = true;
        }
        break;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
                dfs(i,j);
                step++;                 //다음 dfs에서 다른 흔적을 남기기위해
        }
    }
    printf("%d", num);
}
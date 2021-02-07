#include <iostream>
#include <deque>

using namespace std;

int n, k, input, down, count = 0, stage = 0;
deque<pair<int,bool>> dq;

void rotate(){
    int tmp;                    
    tmp = dq[input].first;              //2n의 내구도
    dq.pop_back();
    dq.push_front({tmp, false});        //벨트 제일 앞으로 올라옴
    dq[down].second = false;            //N에 있는 로봇은 땅으로 내려감
    for(int i = down - 1; i > 0; i--)   //먼저올라간 로봇부터
        if(dq[i].second == true && dq[i+1].second == false && dq[i+1].first >= 1){  //i번째에 로봇이 있고 다음 벨트에 로봇이 없고 다음 벨트의 내구도가 1이상         
            dq[i].second = false;                           //현재 칸에서
            dq[i+1].second = true;                          //다음 칸으로 로봇이동
            dq[i+1].first--;                                //다음 칸 내구도 - 1
        }
    if(dq[0].first >= 1){               //땅으로 올라오는 벨트의 내구도가 1이상이면
        dq[0].second = true;            //로봇을 올림
        dq[0].first--;                  //내구도 - 1
    }
    for(int i = 0; i <= input; i++)
        if(dq[i].first == 0)
            count++;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n*2; i++){
        scanf("%d", &input);
        dq.push_back({input,false});
    }
    input = dq.size() - 1;              //벨트 마지막 인덱스
    down = input/2;                     //내려가는 곳 인덱스
    while(count < k){                   //0의 갯수가 k보다 작으면
        count = 0;                      //count 값 초기화
        stage++;                        //단계 1증가
        rotate();
    }
    printf("%d", stage);
}
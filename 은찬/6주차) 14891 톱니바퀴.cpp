#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void){
    int N, ans = 0;
    deque<deque<char>> d(5);

    for(int i = 1; i <= 4; i++){
        string s;
        cin >> s;

        for(int j = 0; j < 8; j++){
            d[i].push_back(s[j]);
        }
    }

    cin >> N;

    for(int i = 0; i < N; i++){
        int gear, direction;
        int check[5] = {false, };

        cin >> gear >> direction;

        //check에 0, 1, -1를 삽입.
        //1인 경우 시계 방향으로 회전
        //-1인 경우 반시계 방향으로 회전
        //0인 경우 회전하지 않는다.
        check[gear] = direction;

        //회전시키는 톱니바퀴의 왼쪽 방향으로 검사
        //만약 마주하는 톱니바퀴가 서로 다른 경우
        //오른쪽에 있는 톱니바퀴의 회전 방향을 확인하여 반대로 넣어준다.
        for(int i = gear - 1; i > 0; i--){
            if(d[i][2] != d[i + 1][6]){
                if(check[i + 1] == 1){
                    check[i] = -1;
                }
                else if(check[i + 1] == -1){
                    check[i] = 1;
                }
            }
            else{
                break;
            }
        }

        //회전시키는 톱니바퀴의 오른쪽 방향으로 검사
        //만약 마주하는 톱니바퀴가 서로 다른 경우
        //왼쪽에 있는 톱니바퀴의 회전 방향을 확인하여 반대로 넣어준다.
        for(int i = gear + 1; i <= 4; i++){
            if(d[i][6] != d[i - 1][2]){
                if(check[i - 1] == 1){
                    check[i] = -1;
                }
                else if(check[i - 1] == -1){
                    check[i] = 1;
                }
            }
            else{
                break;
            }
        }

        //check 배열에 있는 방향값을 토대로 회전시키기.
        for(int i = 1; i <= 4; i++){
            if(check[i] == 1){
                char last = d[i][7];

                d[i].push_front(last);
                d[i].pop_back();
            }
            else if(check[i] == -1){
                char first = d[i][0];

                d[i].push_back(first);
                d[i].pop_front();
            }
        }
    }

    ans = (d[1][0] == '1' ? 1 : 0) + (d[2][0] == '1' ? 2 : 0) + (d[3][0] == '1' ? 4 : 0) + (d[4][0] == '1' ? 8 : 0);
    cout << ans;

    return 0;
}
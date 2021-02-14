#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    //선수 번호는 0 ~ 8로 하여 배열 접근이 쉽게 한다.
    int N;
	vector<vector<int>> score(50, vector<int>(9));
	int ans = 0;

    vector<int> player = {1, 2, 3, 4, 5, 6, 7, 8};

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 9; j++){
            cin >> score[i][j];
        }
    }

    do{
        int sum = 0;
        int index = 0;
        vector<int> tmp_player = player;

        //player 벡터를 복사하여 4번 타자로 0번 선수가 나오게 배치.
        tmp_player.insert(tmp_player.begin() + 3, 0);

        for(int inning = 0; inning < N; inning++){
        	int out = 0;
        	queue<int> base;
            
            while(out != 3){
                //각 이닝 당 타순에 맞게 결과를 저장.
                int state = score[inning][tmp_player[index++]];
                
                if(state == 0){
                    //아웃
                    out++;
                }
                else if(state == 1){
                    //안타
                    //큐가 비어있으면 1루에 주자 1명을 두고, 2, 3루는 비어둔다.
                    //큐가 비어있지 않으면 큐의 사이즈가 3인지 검사.
                    //사이즈가 3인 경우 베이스를 1루씩 앞당기면서 베이스의 선수 여부에 따라 점수를 더해준다.
                    //사이즈가 3이 아닌 경우 1을 푸시하여 1루에 진루.
                    if(base.empty()){
                        base.push(0);
                        base.push(0);
                        base.push(1);
                    }
                    else{
                        if(base.size() == 3){    
                            sum += base.front();
                            base.pop();
                        }
                        base.push(1);
                    }
                }
                else if(state == 2){
                    //2루타
                    //큐가 비어있으면 2루에 주자 1명을 두고, 1, 3루는 비어둔다.
                    //큐가 비어있지 않으면 큐의 사이즈가 3인지 검사.
                    //사이즈가 3인 경우 베이스를 2루씩 앞당기면서 베이스의 선수 여부에 따라 점수를 더해준다.
                    //사이즈가 3이 아닌 경우 1과 0을 푸시. 2루에 선수 1명을 진루시키고, 1루에는 주자가 없다.
                    if(base.empty()){
                        base.push(0);
                        base.push(1);
                        base.push(0);
                    }
                    else{
                        if(base.size() == 3){
                            for(int i = 0; i < 2; i++){
                                sum += base.front();
                                base.pop();
                            }
                        }
                        base.push(1);
                        base.push(0);
                    }
                }
                else if(state == 3){
                    //3루타
                    //큐가 비어있으면 3루에 주자 1명을 두고, 1, 2루는 비어둔다.
                    //큐가 비어있지 않으면 사이즈가 3인지 검사.
                    //사이즈가 3인 경우 베이스를 3루씩 앞당기면서 베이스의 선수 여부에 따라 점수를 더해준다.
                    //사이즈가 3이 아닌 경우 1, 0, 0을 푸시. 3루에 선수 1명 진루, 1, 2루에는 주자가 없다.
                    if(base.empty()){
                        base.push(1);
                        base.push(0);
                        base.push(0);
                    }
                    else{
                        if(base.size() == 3){
                            for(int i = 0; i < 3; i++){
                                sum += base.front();
                                base.pop();
                            }
                        }
                        base.push(1);
                        base.push(0);
                        base.push(0);
                    }
                }
                else if(state == 4){
                    //홈런
                    //모든 주자가 들어와야 하기 때문에 큐가 빌 때까지 베이스의 선수 여부에 따라 점수를 더해준다.
                    //큐가 비게되면 홈런을 친 선수의 점수까지 더해주는 ++을 진행.
                    while(!base.empty()){
                        sum += base.front();
                        base.pop();
                    }
                    sum++;
                }

                if(index == 9){
                    index = 0;
                }
            }
        }

        //모든 타순을 다르게 하여 최대값을 얻는 점수를 저장.
        ans = ans < sum ? sum : ans;
    }while(next_permutation(player.begin(), player.end()));

    cout << ans;
    
    return 0;
}
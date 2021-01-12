#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    vector<int> board(101, 0);
    vector<int> count(101, -1);
    queue<int> q;
    int l, s;

    cin >> l >> s;

    for(int i = 0; i < l; i++){
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }

    for(int i = 0; i < s; i++){
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }

    q.push(1);
    count[1] = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int i = 1; i <= 6; i++){
            int next = current + i;

            if(next > 100){
                continue;
            }

            if(board[next] != 0){
                next = board[next];
            }

            if(count[next] == -1){
                count[next] = count[current] + 1;
                q.push(next);
            }
        }
    }
    cout << count[100];
    return 0;
}
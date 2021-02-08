#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;

deque<int> dq[5];
int k, num, dir, result = 0;;

int main(void){
    deque<int> dq[5];
    for(int i = 1; i < 5; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++)
            dq[i].push_back(s[j] - '0');
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d", &num, &dir);
        int idx = num;
        int tempDir = dir;
        queue<pair<int, int>> q;
        q.push({ idx, tempDir });
        while(1){                   //오른쪽 검사
            if(idx == 4)
                break;
            idx++;
            tempDir *= -1;
            if(dq[idx - 1][2] != dq[idx][6])
                q.push({ idx, tempDir });
            else
                break;
        }
        idx = num;
        tempDir = dir;
        while(1){                   //왼쪽 검사
            if(idx == 1)
                break;
            idx--;
            tempDir *= -1;
            if(dq[idx + 1][6] != dq[idx][2])
                q.push({ idx, tempDir });
            else
                break;
        }
        while(!q.empty()){
            int cur = q.front().first;
            int rotate = q.front().second;
            q.pop();
            if(rotate == 1){
                int temp = dq[cur].back();
                dq[cur].pop_back();
                dq[cur].push_front(temp);
            }
            else{
                int temp = dq[cur].front();
                dq[cur].pop_front();
                dq[cur].push_back(temp);
            }
        }
    }
    for(int i = 1; i < 5; i++)
        if(dq[i].front() == 1)
            result += (int)pow(2, i - 1);
    printf("%d", result);
}
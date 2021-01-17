#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    string s;
    vector<vector<int>> dp(2501, vector<int>(2501, 0));
    vector<int> count(2501, 0);
    int size = 0;

    cin >> s;
    s.insert(0, " ");
    
    size = s.size();

    //dp를 통한 회문 검사
    //1글자 회문
    for(int i = 1; i < size; i++){
        dp[i][i] = 1;
    }

    //2글자 회문
    for(int i = 1; i < size; i++){
        if(s[i] == s[i + 1]){
            dp[i][i + 1] = 1;
        }
    }

    //3글자 이상 회문
    for(int i = 2; i < size; i++){
        for(int j = 1; j <= size - i; j++){
            if(s[j] == s[i + j] && dp[j + 1][i + j - 1]){
                dp[j][i + j] = 1;
            }
        }
    }

    //최소 분할 개수 구하기
    for(int i = 1; i < size; i++){
        count[i] = 999999999;
        for(int j = 1; j <= i; j++){
            if(dp[j][i]){
                count[i] = count[i] < count[j - 1] + 1 ? count[i] : count[j - 1] + 1;
            }
        }
    }
 
	cout << count[size - 1];
    return 0;
}
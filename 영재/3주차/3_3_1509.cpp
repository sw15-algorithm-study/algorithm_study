#include <iostream>

using namespace std;

int main()
{
    string strings;

    cin >> strings;

    int* dp = new int[strings.size()+1]();
    // 팰린드롬 사실 유무 저장을 위한 2차원 배열
    bool** isTrue = new bool*[strings.size()]();

    // 1개짜리
    for(int i = 0; i < strings.size(); i++)
    {
        isTrue[i] = new bool[strings.size()]();
        isTrue[i][i] = 1;
    }

    // 2개짜리 펠린드롬 검사
    for(int i = 0; i < strings.size() - 1; i++)
    {
        if(strings[i] == strings[i+1])
        {
            isTrue[i][i+1] = 1;
        }
    }

    // 3개 이상 펠린드롬 검사
    for(int i = 2; i < strings.size(); i++)
    {
        for(int j = 0; i + j < strings.size(); j++)
        {
            if(strings[j] == strings[j+i]){
                if(isTrue[j+1][j+i-1] == 1)
                isTrue[j][j+i] = 1;
            }
        }
    }

    dp[0] = 0;

    // dp 시작
    for(int i = 0; i < strings.size(); i++)
    {
        int tmpMin = dp[i] + 1;
        for(int j = 0; j < i; j++)
        {
            if(isTrue[j][i] == 1)
            {
                tmpMin = min(dp[j] + 1, tmpMin);
            }
            
        }
        dp[i+1] = tmpMin;
    }

    cout << dp[strings.size()];

}
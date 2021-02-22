// *** 금액이 작은 동전부터 돌면서 dp 채우기 !

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int rest, int coinIndex);

int main()
{
    vector<int> coinList;
    int kinds, goal;
    int* dp;

    cin >> kinds >> goal;

    dp = new int[goal+1]();

    for(int i = 0; i < kinds; i++)
    {
        int inputNum;
        cin >> inputNum;
        coinList.push_back(inputNum);
    }

    // 오름차순 정렬
    sort(coinList.begin(), coinList.end());

    for(int c = 0; c < kinds; c++)
    {
        dp[coinList[c]] += 1;
        for(int i = 1; i <= goal; i++)
        {
            if(i - coinList[c] > 0)
            {
                dp[i] += dp[i - coinList[c]];
            }
        }
    }

    cout << dp[goal];
}
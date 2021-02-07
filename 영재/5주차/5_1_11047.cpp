#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int kindNum , goal;
    cin >> kindNum >> goal;
    vector<int> coinList;

    int answer = 0;
    int nowValue = 0;
    int coinPos = 0;

    for(int i = 0; i < kindNum; i++)
    {
        int tmpCoin;
        cin >> tmpCoin;
        coinList.push_back(tmpCoin);
    }

    sort(coinList.begin(), coinList.end(), greater<int>());

    while(nowValue != goal)
    {
        if(nowValue + coinList[coinPos] > goal)
        {
            if(coinPos + 1 < kindNum)
            {
                coinPos++;
            }
        }
        else
        {
            nowValue += coinList[coinPos];
            answer++;
        }
        
    }

    cout << answer;
}
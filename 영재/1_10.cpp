#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int k;
    vector< pair<int, int> > list;
    int num;

    cin >> num >> k;
    int** dp = new int*[num+1]();

    for(int i = 0; i < num; i++)
    {
        int w, v;
        cin >> w >> v;
        list.push_back(make_pair(w, v));
        dp[i] = new int[k+1]();
    }

    dp[num] = new int[k+1]();

    for(int i = 1; i < num+1; i++)
    {
        bool isChoose = false;
        int pos = i-1;
        for(int j = 1; j < k+1; j++)
        {
            if(list[pos].first > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-list[pos].first] + list[pos].second);
            }
        }
    }

    cout << dp[num][k];
}
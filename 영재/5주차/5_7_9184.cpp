#include <iostream>

using namespace std;

int main()
{
    int*** dp = new int**[21]();
    for(int i = 0; i < 21; i++)
    {
        dp[i] = new int*[21]();
        for(int j = 0; j < 21; j++)
        {
            dp[i][j] = new int[21]();
        }
    }

    for(int i = 0; i < 21; i++)
    {
        for(int j = 0; j < 21; j++)
        {
            for(int k = 0; k < 21; k++)
            {
                if(i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 1;
                }
                else if(i < j && j < k)
                {
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                }
                else
                {
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
                }             
            }
        }
    }

    string answer = "";
    while(true)
    {
        int i,j,k;
        cin >> i >> j >> k;
        if(i == -1 && j == -1 && k == -1)
        {
            break;
        }
        int ti,tj,tk;
        if(i <= 0 || j <= 0 || k <= 0)
        {
            ti = 0;
            tj = 0;
            tk = 0;
        }
        else if(i > 20 || j > 20 || k > 20)
        {
            ti = 20;
            tj = 20;
            tk = 20;
        }
        else
        {
            ti = i;
            tj = j;
            tk = k;
        }
        
        printf("w(%d, %d, %d) = %d\n", i, j, k, dp[ti][tj][tk]);
    }
}
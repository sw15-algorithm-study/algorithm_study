#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // 0번째는 사용하지 않고 1 ~ n 번째 인덱스만 사용
    int** dp = new int*[n+1]();
    vector<vector<int> > triangle;

    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[n+1];
        vector<int> tmpVector;
        triangle.push_back(tmpVector);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            int tmpNum;
            cin >> tmpNum;
            triangle[i].push_back(tmpNum);
        }
    }

    dp[1][1] = triangle[1].front();

    for(int i = 2; i <= n; i++)
    {
        dp[1][i] = dp[1][i-1] + triangle[i].front();
    }

    for(int x = 2; x <= n; x++)
    {
        for(int y = 2; y <= x; y++)
        {
            dp[y][x] = max(dp[y][x-1], dp[y-1][x-1]) + triangle[x][y-1];
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(dp[i][n] > answer)
        {
            answer = dp[i][n];
        }
    }

    cout << answer;
}
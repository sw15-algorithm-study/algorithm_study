#include <iostream>
#include <stack>

using namespace std;

int dfs(pair<int,int> nowStat);
bool canGo(int y, int x);

int row, col;
int** dp;
int** maps;
bool** visit;
int xVector[4] = {1, 0, -1, 0};
int yVector[4] = {0, 1, 0, -1};

int main()
{
    cin >> row >> col;

    maps = new int*[row]();
    dp = new int*[row]();
    visit = new bool*[row]();
    for(int i = 0; i < row; i++)
    {
        visit[i] = new bool[col]();
        dp[i] = new int[col]();
        maps[i] = new int[col]();
        for(int j = 0; j < col; j++)
        {
            cin >> maps[i][j];
        }
    }

    pair<int,int> start;
    start = make_pair(0,0);

    cout << dfs(start);
}

int dfs(pair<int,int> nowPos)
{
    if(visit[nowPos.first][nowPos.second])
    {
        return dp[nowPos.first][nowPos.second];
    }
    visit[nowPos.first][nowPos.second] = true;
    for(int i = 0; i < 4; i++)
    {
        pair<int,int> nextPos;
        nextPos.first = nowPos.first + yVector[i];
        nextPos.second = nowPos.second + xVector[i];
        if(canGo(nextPos.first, nextPos.second))
        {
            if(maps[nowPos.first][nowPos.second] <= maps[nextPos.first][nextPos.second])
            {
                continue;
            }
            if(nextPos.first == row - 1 && nextPos.second == col - 1)
            {
                dp[nowPos.first][nowPos.second] += 1;
                continue;
            }
            else
            {
                dp[nowPos.first][nowPos.second] += dfs(nextPos);
            }
        }
    }
    return dp[nowPos.first][nowPos.second];
}

bool canGo(int y, int x)
{
    if(0 <= y && y < row && 0 <= x && x < col)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
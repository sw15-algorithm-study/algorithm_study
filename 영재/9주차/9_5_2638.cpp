#include <iostream>
#include <queue>
#include <string.h>
#define n 100

using namespace std;

int row, col;
int maps[n][n] = {0, };
int outCount[n][n] = {0, };
bool outside[n][n] = {0, };
bool visit[n][n] = {0, };
int rest = 0;
int answer = 0;

int xVector[4] = {0, 1, 0, -1};
int yVector[4] = {-1, 0, 1, 0};

struct Pos
{
    int y;
    int x;
};

void findOutside();
bool inRange(int y, int x);
void findCheeze();

int main()
{
    cin >> row >> col;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> maps[i][j];
            if(maps[i][j] == 1)
            {
                rest++;
            }
        }
    }

    while(rest > 0)
    {
        findOutside();
        findCheeze();
        answer++;
    }

    cout << answer;
}

void findCheeze()
{
    memset(outCount, 0, n * n * sizeof(int));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(maps[i][j] == 0)
            {
                continue;
            }
            else
            {
                for(int k = 0; k < 4; k++)
                {
                    int nY = i + yVector[k];
                    int nX = j + xVector[k];
                    if(inRange(nY,nX))
                    {
                        if(outside[nY][nX])
                        {
                            outCount[i][j]++;
                        }
                    }
                }
            }   
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(outCount[i][j] >= 2 && maps[i][j] == 1)
            {
                maps[i][j] = 0;
                rest--;
            }
        }
    }

}

void findOutside()
{
    memset(visit, 0,  n * n* sizeof(bool));
    queue<Pos> q;
    Pos start = {0,0};
    outside[0][0] = true;
    q.push(start);

    while(!q.empty())
    {
        Pos now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nextY = now.y + yVector[i];
            int nextX = now.x + xVector[i];
            if(inRange(nextY, nextX))
            {
                if(visit[nextY][nextX])
                {
                    continue;
                }
                else
                {
                    visit[nextY][nextX] = 1;
                    if(maps[nextY][nextX] == 0)
                    {
                        outside[nextY][nextX] = true;
                        Pos nextPos = {nextY, nextX};
                        q.push(nextPos);
                    }
                }
            }
        }
    }
}

bool inRange(int y, int x)
{
    if(y < 0 || y >= row || x < 0 || x >= col)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}
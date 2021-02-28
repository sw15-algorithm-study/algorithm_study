#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

struct Pos
{
    int y;
    int x;
    int restDist;
};

int row, col, dist;
int maps[16][15];
int board[16][15];
bool visit[16][15];
int archers[3];
int answer = 0;
int xVector[3] = {-1, 0, 1};
int yVector[3] = {0, -1, 0};

bool inRange(int y, int x);
int simulate();
void findOrder(int k, int depth);

int main()
{
    cin >> row >> col >> dist;
    
    memset(visit, 0, 16 * 15 * sizeof(bool));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> maps[i][j];
        }
    }

    findOrder(0,0);

    cout << answer;
}

// 0 ~ row, 0 ~ col-1
int simulate()
{
    int kill = 0;
    queue<pair<int,int> > enemy;
    for(int turn = 0; turn < row; turn++)
    {
        for(int a = 0; a < 3; a++)
        {
            queue<Pos> findPos;
            Pos startPos = {row-1, archers[a], dist-1};
            findPos.push(startPos);

            while(!findPos.empty())
            {
                Pos nowPos = findPos.front();
                findPos.pop();

                if(board[nowPos.y][nowPos.x] == 1)
                {
                    enemy.push(make_pair(nowPos.y, nowPos.x));
                    break;
                }
                else
                {
                    if(nowPos.restDist > 0)
                    {
                        for(int i = 0; i < 3; i++)
                        {
                            int nextY = nowPos.y + yVector[i];
                            int nextX = nowPos.x + xVector[i];
                            if(inRange(nextY, nextX) && visit[nextY][nextX] == 0)
                            {
                                visit[nextY][nextX] = 1;
                                Pos tmpPos = {nextY, nextX, nowPos.restDist-1};
                                findPos.push(tmpPos);
                            }
                        }
                    }
                }
            }
            queue<Pos> emptyPos;
            std::swap(findPos, emptyPos);
            memset(visit, 0, 16 * 15 *sizeof(bool));
        }

        while(!enemy.empty())
        {
            pair<int,int> nowEnemy = enemy.front();
            enemy.pop();
            if(board[nowEnemy.first][nowEnemy.second] == 1)
            {
                kill++;
                board[nowEnemy.first][nowEnemy.second] = 0;
            }
        }

        for(int i = row - 2; i >= 0; i--)
        {
            memcpy(board[i+1], board[i], sizeof(int) * col);
            if(i == 0)
            {
                memset(board[0], 0, sizeof(int) * col);
            }
        }
    }
    return kill;
}

bool inRange(int y, int x)
{
    if(y < 0 || y >= row || x < 0 || x >= col)
    {
        return false;
    }

    return true;
}

void findOrder(int k, int depth)
{
    if(k > col || depth > 3)
    {
        return;
    }
    if(depth == 3)
    {
        memcpy(board, maps, sizeof(int) * 16 * 15);
        int result = simulate();
        if(answer < result)
        {
            answer = result;
        }
    }
    else
    {
        archers[depth] = k;
        findOrder(k+1, depth+1);
        
        findOrder(k+1, depth);
    }
    
}
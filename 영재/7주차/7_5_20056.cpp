#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct FireBall
{
    pair<int,int> position;
    int m;
    int s;
    int d;
};

int xVector[8] = {0, 1 ,1 ,1, 0, -1, -1, -1};
int yVector[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main()
{
    int row, col, fireNum, moveNum;
    queue<FireBall> ballsQ;

    cin >> row >> fireNum >> moveNum;
    col = row;
    
    vector<FireBall> board[row][col];

    for(int i = 0; i < fireNum; i++)
    {
        pair<int,int> tmpP;
        int tmpM, tmpS, tmpD;
        cin >> tmpP.first >> tmpP.second >> tmpM >> tmpS >> tmpD;
        tmpP.first -= 1;
        tmpP.second -= 1;
        FireBall tmpFireBall = {tmpP, tmpM, tmpS, tmpD};
        ballsQ.push(tmpFireBall);
    }

    for(int i = 0; i < moveNum; i++)
    {
        while (!ballsQ.empty())
        {
            FireBall nowBall = ballsQ.front();
            ballsQ.pop();

            pair<int,int> nextPos;
            nextPos.first = (nowBall.position.first + yVector[nowBall.d] * nowBall.s + (row * nowBall.s) ) % row;
            nextPos.second = (nowBall.position.second + xVector[nowBall.d] * nowBall.s + (col * nowBall.s) ) % col;
            nowBall.position = nextPos;

            board[nextPos.first][nextPos.second].push_back(nowBall);
        }

        for(int y = 0; y < row; y++)
        {
            for(int x = 0; x < col; x++)
            {
                if(board[y][x].empty())
                {
                    continue;
                }
                else if(board[y][x].size() == 1)
                {
                    ballsQ.push(board[y][x].front());
                }
                else // 2개 이상일 때
                {
                    int sumM = 0;
                    int sumS = 0;
                    int rest;
                    bool sameD = true;
                    for(int k = 0; k < board[y][x].size(); k++)
                    {
                        FireBall tmp = board[y][x][k];

                        if(k == 0)
                        {
                            rest = tmp.d % 2;
                        }
                        else
                        {
                            if(tmp.d % 2 != rest)
                            {
                                sameD = false;
                            }
                        }
                        sumM += tmp.m;
                        sumS += tmp.s;   
                    }
                    sumM = sumM / 5;
                    sumS = sumS / board[y][x].size();

                    if(sumM > 0)
                    {
                        if(sameD)
                        {
                            int startD = 0;
                            for(int j = 0; j < 4; j++)
                            {
                                pair<int,int> newP = make_pair(y, x);
                                FireBall newBall = {newP, sumM, sumS, startD};
                                ballsQ.push(newBall);
                                startD += 2;
                            }
                        }
                        else
                        {
                            int startD = 1;
                            for(int j = 0; j < 4; j++)
                            {
                                pair<int,int> newP = make_pair(y, x);
                                FireBall newBall = {newP, sumM, sumS, startD};
                                ballsQ.push(newBall);
                                startD += 2;
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
                board[i][j].clear();
            }
        }
    }

    int answer = 0;
    
    while(!ballsQ.empty())
    {
        answer += ballsQ.front().m;
        ballsQ.pop();
    }
    cout << answer;
}
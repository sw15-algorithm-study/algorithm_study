#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct BoardState
{
    int board[4][4];
    int fishesVector[17];
    bool isSurvive[17];
    vector<pair<int,int> > fishesPosition;
    pair<int,int> sharkPosition;
    int sharkVector;
    int score;
    pair<int,int> deadPosition;
};

int main()
{
    int xVector[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int yVector[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    BoardState startBoard = {};
    startBoard.score = 0;
    startBoard.deadPosition = make_pair(0, 0);

    queue<BoardState> boardQ;

    int answer = 0;

    for(int i = 0; i < 17; i++)
    {
        startBoard.fishesPosition.push_back(make_pair(0,0));
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int fishIndex, tmpVector;
            cin >> fishIndex >> tmpVector;
            startBoard.board[i][j] = fishIndex;
            startBoard.fishesVector[fishIndex] = tmpVector - 1;
            startBoard.isSurvive[fishIndex] = true;
            startBoard.fishesPosition[fishIndex].first = i;
            startBoard.fishesPosition[fishIndex].second = j;
        }
    }

    boardQ.push(startBoard);

    while (!boardQ.empty())
    {
        BoardState nowBoard = boardQ.front();
        boardQ.pop();

        int deadFish = nowBoard.board[nowBoard.deadPosition.first][nowBoard.deadPosition.second];
        nowBoard.score += deadFish;
        if(nowBoard.board[nowBoard.sharkPosition.first][nowBoard.sharkPosition.second] == 0)
        {
            nowBoard.board[nowBoard.sharkPosition.first][nowBoard.sharkPosition.second] = - 1;
        }
        nowBoard.board[nowBoard.deadPosition.first][nowBoard.deadPosition.second] = 0; // 0 = shark
        nowBoard.sharkPosition = nowBoard.deadPosition;
        nowBoard.sharkVector = nowBoard.fishesVector[deadFish];
        nowBoard.isSurvive[deadFish] = false;

        if(nowBoard.score > answer)
        {
            answer = nowBoard.score;
        }

        // 물고기들 대이동
        for(int i = 1; i <=16; i++)
        {
            if(nowBoard.isSurvive[i] == true)
            {
                bool canMove = true;
                int tmpVector = nowBoard.fishesVector[i];
                int nextY = nowBoard.fishesPosition[i].first + yVector[tmpVector];
                int nextX = nowBoard.fishesPosition[i].second + xVector[tmpVector];
                if(nextX < 0 || nextX > 3 || nextY < 0 || nextY > 3 || nowBoard.board[nextY][nextX] == 0)
                {
                    canMove = false;
                    for(int j = 0; j < 7; j++)
                    {
                        nextY = nowBoard.fishesPosition[i].first + yVector[tmpVector];
                        nextX = nowBoard.fishesPosition[i].second + xVector[tmpVector];
                        if(nextX < 0 || nextX > 3 || nextY < 0 || nextY > 3 || nowBoard.board[nextY][nextX] == 0)
                        {
                            tmpVector = (tmpVector + 1) % 8;
                            continue;
                        }
                        else
                        {
                            nowBoard.fishesVector[i] = tmpVector;
                            canMove = true;
                            break;
                        }
                        
                    }
                }
                if(canMove)
                {
                    int edFish = nowBoard.board[nextY][nextX];
                    pair<int,int> nextPair = make_pair(nextY, nextX);
                    pair<int,int> tmpPair = nowBoard.fishesPosition[i];
                    if(edFish != -1)
                    {
                        nowBoard.fishesPosition[i] = nextPair;
                        nowBoard.fishesPosition[edFish] = tmpPair;
                        nowBoard.board[tmpPair.first][tmpPair.second] = edFish;
                        nowBoard.board[nextY][nextX] = i;
                    }
                    else
                    {
                        nowBoard.board[nextY][nextX] = i;
                        nowBoard.fishesPosition[i] = nextPair;
                        nowBoard.board[tmpPair.first][tmpPair.second] = -1;
                    }
                }
            }
            else
            {
                // 이미 잡아 먹힌 물고기...
                continue;
            }
            
        }

        // 상어 이동
        int sharkVec = nowBoard.sharkVector;
        int sharkY = nowBoard.sharkPosition.first + yVector[sharkVec];
        int sharkX = nowBoard.sharkPosition.second + xVector[sharkVec];
        while (sharkX >= 0 && sharkX < 4 && sharkY >= 0 && sharkY < 4)
        {
            if(nowBoard.board[sharkY][sharkX] > 0)
            {
                nowBoard.deadPosition.first = sharkY;
                nowBoard.deadPosition.second = sharkX;
                boardQ.push(nowBoard);
            }

            sharkY = sharkY + yVector[sharkVec];
            sharkX = sharkX + xVector[sharkVec];
        }

        nowBoard.fishesPosition.clear();
    }

    cout << answer;
}
#include <iostream>
#include <queue>

using namespace std;

int answer = 0;
int sharkSize = 2;
int restNum = 2;

pair<int,int> sharkPosition;
int** board;
bool** visited;
int row, col;

int flag = -1;

int xVector[4] = {0, -1, 0, 1};
int yVector[4] = {-1, 0, 1, 0};

struct queueState
{
    pair<int,int> nextPosition;
    int times;
};


bool moveShark();

int main()
{
    cin >> row;
    col = row;

    board = new int*[row]();
    visited = new bool*[row]();

    for(int i = 0; i < row; i++)
    {
        board[i] = new int[col]();
        visited[i] = new bool[col]();
        for(int j = 0; j < col; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 9)
            {
                sharkPosition.first = i;
                sharkPosition.second = j;
                board[i][j] = 0;
            }
        }
    }

    while(true)
    {
       if(moveShark())
       {
           break;
       }
       else
       {
           if(restNum == 0)
            {
                sharkSize++;
                restNum = sharkSize;
            }
           for(int i = 0; i < row; i++)
           {
               for(int j = 0; j < col; j++)
               {
                   visited[i][j] = false;
               }
           }
       }
    }

    cout << answer;

}

bool moveShark()
{
    bool isEnd = true;
    queue<queueState> nextPositionQ;
    queueState tmpState = {sharkPosition, 1};
    nextPositionQ.push(tmpState);
    visited[sharkPosition.first][sharkPosition.second] = true;

    pair<int,int> nextPos;
    int preNum = 0;

    int minTimes = 0;

    while(!nextPositionQ.empty())
    {   
        pair<int,int> pos = nextPositionQ.front().nextPosition;
        int nowTimes = nextPositionQ.front().times;
        nextPositionQ.pop();

        if (minTimes !=0 && nowTimes > minTimes)
        {
            return false;
        }

        int nextY, nextX;

        for(int i = 0; i < 4; i++)
        {
            nextY = pos.first + yVector[i];
            nextX = pos.second + xVector[i];

            if(nextX < 0 || nextX >= col || nextY < 0 || nextY >= row || visited[nextY][nextX])
            {
                continue;
            }
            else
            {
                if(board[nextY][nextX] > 0 && board[nextY][nextX] < sharkSize)
                {
                    visited[nextY][nextX] = true;
                    if(minTimes == 0)
                    {
                        isEnd = false;
                        answer += nowTimes;
                        minTimes = nowTimes;
                        nextPos.first = nextY;
                        nextPos.second = nextX;
                        restNum--;
                        preNum = board[nextPos.first][nextPos.second];
                        board[nextPos.first][nextPos.second] = flag;
                        flag--;
                    }
                    else
                    {
                        if(nextPos.first > nextY || (nextPos.first == nextY && nextPos.second > nextX) )
                        {
                            board[nextPos.first][nextPos.second] = preNum;
                            nextPos.first = nextY;
                            nextPos.second = nextX;
                            preNum = board[nextPos.first][nextPos.second];
                            board[nextPos.first][nextPos.second] = flag;
                            flag--;
                        }
                    }
                    sharkPosition= nextPos;
                }
                else if(board[nextY][nextX] > sharkSize)
                {
                    visited[nextY][nextX] = true;
                    continue;
                }
                else
                {
                    visited[nextY][nextX] = true;
                    queueState nextState = {make_pair(nextY,nextX), nowTimes+1};
                    nextPositionQ.push(nextState);
                }
            }
        }   
    }

    return isEnd; // 엄마 상어 호출 !
}
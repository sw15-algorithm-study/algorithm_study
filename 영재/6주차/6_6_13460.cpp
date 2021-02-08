// 구현 난이도 매우매우 어려웠음
// 맨처음엔 보드판 자체를 큐에 넣으며 bfs 하려 했으나 너무너무 비효율적 !!
// 은찬이의 조언으로 -> 벽과 구멍은 고정 -> 구슬들을 큐에 넣고 빼면서 하나의 보드에서 시뮬레이션 함.

// 구현 컵셉
// 1. 빨간구슬과 파란구슬의 위치를 통해 반드시 먼저 움직여야 하는 구슬이 있는지 확인 ex). 0 0 R B 0 에서 오른쪽으로 기울일 때 -> 반드시 파란구슬먼저 움직이고 빨간구슬을 움직여야 한다.
// 2. 순서에 따라 구슬을 움직인다. moveBead()
// 3. 파란구슬이 구멍에 빠졌다면 현재의 움직임은 의미가 없으므로 큐에 넣지 않는다.
// 4. 둘다 구멍에 빠지지 않았다면 현재 구슬들의 위치를 각각의 큐에 넣는다.
// 5. 빨간구슬이 구멍에 빠졌다면 파란구슬도 빠지는지 검사. 파란구슬 안 빠진다면 수행 종료.
// ** 만약 moveVector=0 이라면 다음번 동작은 1과 3만 해주면 됨.              반대로 1이었다면 0, 2만 수행
#include <iostream>
#include <queue>

using namespace std;

int** board;
int row, col;
int xVector[4] = {1, 0, -1, 0};
int yVector[4] = {0, 1, 0, -1};
int answer = 0;

pair<int, int> redPosition;
pair<int, int> bluePosition;
queue<pair<int, int> > boardState; // first = times, second = moveVector
queue<pair<int, int> > redPositions;
queue<pair<int, int> > bluePositions;

bool redFirstMove(pair<int,int> rPoint, pair<int,int> bPoint, int times, int moveVector);
bool blueFirstMove(pair<int,int> rPoint, pair<int,int> bPoint, int times, int moveVector);
pair<int,int> moveBead(pair<int,int> startPosition, int moveIndex);

int main()
{
    cin >> row >> col;

    board = new int*[row]();

    for(int i = 0; i < row; i++)
    {
        board[i] = new int[col]();
        string input;
        cin >> input;
        for(int j = 0; j < col; j++)
        {
            if(input[j] == '#')
            {
                board[i][j] = -1;
            }
            else if(input[j] == '.')
            {
                board[i][j] = 0;
            }
            else if(input[j] == 'R')
            {
                board[i][j] = 0;
                redPosition.first = i;
                redPosition.second = j;
            }
            else if(input[j] == 'B')
            {
                board[i][j] = 0;
                bluePosition.first = i;
                bluePosition.second = j;
            }
            else
            {
                board[i][j] = 7;
            }
        }
    }

    for(int i = 0; i < 4; i++)
    {
        boardState.push(make_pair(1,i));
        redPositions.push(redPosition);
        bluePositions.push(bluePosition);
    }

    while(answer == 0)
    {
        // pair(times, moveVector)
        int times = boardState.front().first;
        int moveVector = boardState.front().second;
        // 10번동안 성공하지 못했다면 그만한다.
        if(times > 10)
        {
            answer = -1;
            break;
        }
        
        // 큐에서 현재 파란구슬 빨간구슬 위치 꺼내옴.
        pair<int, int> bPoint = bluePositions.front();
        pair<int, int> rPoint = redPositions.front();
        bluePositions.pop();
        redPositions.pop();
        boardState.pop();

        // moveVector 와 현재 파란구슬, 빨간구슬과의 관계를 통해 어떤 구슬을 먼저 움직일지 필터링하는 코드.
        if(moveVector == 0 || moveVector == 2)
        {
            if(moveVector == 0)
            {
                if(bPoint.first == rPoint.first && bPoint.second < rPoint.second)
                {
                    if(redFirstMove(rPoint, bPoint, times, moveVector))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
                else
                {
                    if(blueFirstMove(rPoint, bPoint, times, moveVector))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
            }
            else if(moveVector == 2)
            {
                if(bPoint.first == rPoint.first && bPoint.second > rPoint.second)
                {
                    if(redFirstMove(rPoint, bPoint, times, moveVector))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
                else
                {
                    if(blueFirstMove(rPoint, bPoint, times, moveVector))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
            }
        }
        else
        {
            if(moveVector == 1)
            {
                if(bPoint.second == rPoint.second && bPoint.first < rPoint.first)
                {
                    if(redFirstMove(rPoint, bPoint, times, moveVector))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
                else
                {
                    if(blueFirstMove(rPoint, bPoint, times, moveVector))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
            }
            else if(moveVector == 3)
            {
                if(bPoint.second == rPoint.second && bPoint.first > rPoint.first)
                {
                    if(redFirstMove(rPoint, bPoint, times, moveVector))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
                else
                {
                    if(blueFirstMove(rPoint, bPoint, times, moveVector))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }     
                }
            }
        }
    
    }

    cout << answer;

}

// 빨간구슬을 먼저 움직여야 할 때 // true 반환시 빨간구슬만 구멍에 빠지는 경우
bool redFirstMove(pair<int,int> rPoint, pair<int,int> bPoint, int times, int moveVector)
{
    pair<int,int> nextRPoint = moveBead(rPoint, moveVector);
    if(board[nextRPoint.first][nextRPoint.second] == 7)
    {
        pair<int,int> nextBPoint = moveBead(bPoint, moveVector);
        if(board[nextBPoint.first][nextBPoint.second] == 7)
        {
            return false;
        }
        answer = times;
        return true;
    }
    board[nextRPoint.first][nextRPoint.second] = 1;
    pair<int,int> nextBPoint = moveBead(bPoint, moveVector);
    if(board[nextBPoint.first][nextBPoint.second] == 7)
    {
        board[nextRPoint.first][nextRPoint.second] = 0;
        return false;
    }
    board[nextRPoint.first][nextRPoint.second] = 0;
    bluePositions.push(nextBPoint);
    bluePositions.push(nextBPoint);
    redPositions.push(nextRPoint);
    redPositions.push(nextRPoint);
    if(moveVector == 0 || moveVector == 2)
    {
        boardState.push(make_pair(times+1, 1));
        boardState.push(make_pair(times+1, 3));
    }
    else
    {
        boardState.push(make_pair(times+1, 0));
        boardState.push(make_pair(times+1, 2));
    }
    return false;
}

// 파란구슬을 먼저 움직여야 할 때 ..... 위의 코드와 거의 동일하며 움직이는 순서에 따라 조금씩 코드의 순서가 다름.
bool blueFirstMove(pair<int,int> rPoint, pair<int,int> bPoint, int times, int moveVector)
{
    pair<int,int> nextBPoint = moveBead(bPoint, moveVector);
    if(board[nextBPoint.first][nextBPoint.second] == 7)
    {
        return false;
    }
    board[nextBPoint.first][nextBPoint.second] = 1;
    pair<int,int> nextRPoint = moveBead(rPoint, moveVector);
    if(board[nextRPoint.first][nextRPoint.second] == 7)
    {
        answer = times;
        return true;
    }
    board[nextRPoint.first][nextRPoint.second] = 0;
    board[nextBPoint.first][nextBPoint.second] = 0;
    
    bluePositions.push(nextBPoint);
    bluePositions.push(nextBPoint);
    redPositions.push(nextRPoint);
    redPositions.push(nextRPoint);
    if(moveVector == 0 || moveVector == 2)
    {
        boardState.push(make_pair(times+1, 1));
        boardState.push(make_pair(times+1, 3));
    }
    else
    {
        boardState.push(make_pair(times+1, 0));
        boardState.push(make_pair(times+1, 2));
    }
    return false;
}

// 실제로 구슬을 움직이는 코드.
pair<int,int> moveBead(pair<int,int> startPosition, int moveIndex)
{
    board[startPosition.first][startPosition.second] = 0;
    int nextY = startPosition.first + yVector[moveIndex];
    int nextX = startPosition.second + xVector[moveIndex];

    while(true)
    {
        if(0 <= nextY && nextY < row && 0 <= nextX && nextX < col)
        {
            // 다음칸이 빈칸일 때
            if(board[nextY][nextX] == 0)
            {
                nextY += yVector[moveIndex];
                nextX += xVector[moveIndex];
            }
            // 다음칸이 구멍일 때
            else if(board[nextY][nextX] == 7)
            {
                break;
            }
            else
            {   // 다음칸이 벽이거나 다른 구슬이 있을 때 -> 바로 직전 위치로 복귀해줘야함!
                nextY += yVector[moveIndex] * -1;
                nextX += xVector[moveIndex] * -1;
                break;
            }   
        }
        else
        {   // 보드판의 영역을 벗어났을 경우. -> 바로 직전 위치로 복귀.
            nextY += yVector[moveIndex] * -1;
            nextX += xVector[moveIndex] * -1;
            break;
        }
    }
    pair<int,int> nextBeadPosition;
    nextBeadPosition.first = nextY;
    nextBeadPosition.second = nextX;
    return nextBeadPosition;
}
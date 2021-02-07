#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int row, col;
    int appleNum;
    int** board;
    vector<pair<int,char> > changeVector;
    queue<pair<int, int> > nextTailQ;       // 다음 꼬리가 될 칸을 큐에 집어넣음 -> head가 움직이는 칸을 큐에 순서대로 넣는다 !
    int changeNum;
    int sec = 0;

    int xVector[4] = {1, 0, -1, 0};
    int yVector[4] = {0, 1, 0, -1};

    cin >> row;
    col = row;

    board = new int*[row+1]();
    for(int i = 0; i <= row; i++)
    {
        board[i] = new int[col+1]();
    }

    cin >> appleNum;
    for(int i = 0; i < appleNum; i++)
    {
        int appleRow, appleCol;
        cin >> appleRow >> appleCol;
        // if apple -> 7
        board[appleRow][appleCol] = 7;
    }

    cin >> changeNum;
    for(int i = 0; i < changeNum; i++)
    {
        int times;
        char rotation;
        cin >> times >> rotation;
        changeVector.push_back(make_pair(times, rotation));
    }

    int changeIndex = 0;
    int moveIndex = 0;
    board[1][1] = 1;
    pair<int, int> headPos = make_pair(1,1);
    pair<int, int> tailPos = make_pair(1,1);

    while(true)
    {
        sec++;

        int nextY = headPos.first + yVector[moveIndex];
        int nextX = headPos.second + xVector[moveIndex];

        if(0 < nextY && nextY <= row && 0 < nextX && nextX <= col && board[nextY][nextX] != 1)
        {
            headPos.first = nextY;
            headPos.second = nextX;
            nextTailQ.push(make_pair(nextY, nextX));

            if(board[nextY][nextX] == 0)
            {
                board[tailPos.first][tailPos.second] = 0;
                tailPos.first = nextTailQ.front().first;
                tailPos.second = nextTailQ.front().second;
                nextTailQ.pop();
            }

            board[nextY][nextX] = 1;

            if(changeIndex < changeNum)
            {
                if(changeVector[changeIndex].first == sec)
                {
                    if(changeVector[changeIndex].second == 'D')
                    {
                        moveIndex = (moveIndex + 1) % 4;
                    }
                    else
                    {
                        moveIndex = (moveIndex + 3) % 4;    
                    }
                    changeIndex++;
                }
            }
        }
        else
        {
            break;
        }
    }

    cout << sec;
}
// 구현 난이도 높았음.
// 복잡한 구조로 코딩함.

#include <iostream>

using namespace std;

int** board;
int row, col;
int maxBlock = 0;

void moveBlock(int times, int moveVector);

int main()
{
    
    cin >> row;
    col = row;

    board = new int*[row]();

    for(int y = 0; y < row; y++)
    {
        board[y] = new int[col]();
        for(int x = 0; x < col; x++)
        {
            int tmpNum;
            cin >> tmpNum;
            board[y][x] = tmpNum;
        }
    }

    int tmpBoard[row][col];
    for(int y = 0; y < row ; y++)
    {
        for(int x = 0; x < col; x++)
        {
            tmpBoard[y][x] = board[y][x];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        for(int y = 0; y < row ; y++)
        {
            for(int x = 0; x < col; x++)
            {
                board[y][x] = tmpBoard[y][x];
            }
        }
        moveBlock(1, i);
    }

    cout << maxBlock;
}

void moveBlock(int times, int moveVector)
{
    // 코드의 중복을 줄이기위해 flag, compare 변수를 사용함. 나도 헷갈려서 1번 틀림.
    // fillPos  개념(ex. 오른쪽 방향으로 밀었을 때, 맨 오른쪽 블럭부터 숫자를 쌓아야함.)이 중요. 이것만 빼면 어려운것 없음.
    int startX, startY, flagX, flagY;
    int compareX = 0;
    int compareY = 0;
    if(moveVector == 1 || moveVector == 3)
    {
        startY = 0;
        flagY = 1;
        if(moveVector == 1)
        {
            startX = col - 1;
            flagX = -1; 
        }
        else
        {
            startX = 0;
            flagX = 1;
        }       
        
        for(int y = startY; compareY < row; compareY++)
        {
            int preBlock = 0;
            int fillPos = startX;
            compareX = 0;
            for(int x = startX; compareX < col; compareX++)
            {
                if(board[y][x] == 0)
                {
                    x += flagX;
                    continue;
                }

                if(preBlock == board[y][x])
                {
                    board[y][fillPos] = preBlock * 2;
                    if(maxBlock < preBlock * 2)
                    {
                        maxBlock = preBlock * 2;
                    }
                    if(x != fillPos)
                    {
                        board[y][x] = 0;
                    }
                    preBlock = 0;
                    fillPos += flagX;
                }
                else
                {
                    if(preBlock == 0)
                    {
                        preBlock = board[y][x];
                        board[y][fillPos] = board[y][x];
                        if(maxBlock < board[y][x])
                        {
                            maxBlock = board[y][x];
                        }    
                        if(x != fillPos)
                        {
                            board[y][x] = 0;
                        }
                    }
                    else
                    {
                        fillPos += flagX;
                        board[y][fillPos] = board[y][x];
                        preBlock = board[y][x];
                        if(maxBlock < board[y][x])
                        {
                            maxBlock = board[y][x];
                        }    
                        if(x != fillPos)
                        {
                            board[y][x] = 0;
                        }
                    }  
                }

                x += flagX;
            }
            y += flagY;
        }

    }
    else if(moveVector == 0 || moveVector == 2)
    {
        startX = 0;
        flagX = 1;
        if(moveVector == 0)
        {
            startY = 0;
            flagY = 1;
        }
        else
        {
            startY = row - 1;
            flagY = -1;
        }

        for(int x = startX; compareX < col; compareX++)
        {
            int preBlock = 0;
            int fillPos = startY;
            compareY = 0;
            for(int y = startY; compareY < row; compareY++)
            {
                if(board[y][x] == 0)
                {
                    y += flagY;
                    continue;
                }

                if(preBlock == board[y][x])
                {
                    board[fillPos][x] = preBlock * 2;
                    if(fillPos != y)
                    {
                        board[y][x] = 0;
                    }
                    if(maxBlock < preBlock * 2)
                    {
                        maxBlock = preBlock * 2;
                    }
                    preBlock = 0;
                    fillPos += flagY;
                }
                else
                {
                    if(preBlock == 0)
                    {
                        preBlock = board[y][x];
                        board[fillPos][x] = board[y][x];
                        if(maxBlock < board[y][x])
                        {
                            maxBlock = board[y][x];
                        }  
                        if(fillPos != y)
                        {
                            board[y][x] = 0;
                        }
                    }
                    else
                    {
                        fillPos += flagY;
                        board[fillPos][x] = board[y][x];
                        preBlock = board[y][x];
                        if(maxBlock < board[y][x])
                        {
                            maxBlock = board[y][x];
                        }  
                        if(fillPos != y)
                        {
                            board[y][x] = 0;
                        }
                    }    
                }

                y += flagY;
            }
            x += flagX;
        }
    }

    int tmpBoard[row][col];
    for(int y = 0; y < row ; y++)
    {
        for(int x = 0; x < col; x++)
        {
            tmpBoard[y][x] = board[y][x];
        }
    }

    if(times < 5)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int y = 0; y < row ; y++)
            {
                for(int x = 0; x < col; x++)
                {
                    board[y][x] = tmpBoard[y][x];
                }
            }
            moveBlock(times + 1, i);
        }
    }
}

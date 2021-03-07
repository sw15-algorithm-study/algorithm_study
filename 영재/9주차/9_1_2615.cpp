#include <iostream>

using namespace std;

int winner = 0;
int cur = 0;
int linearCount = 0;
pair<int,int> start = make_pair(0,0);
int ** board;

void check();
void rowSearch();
void colSearch();
void diaSearch();
void reverseDiaSearch();

int main()
{
    board = new int*[20]();
    for(int i = 0; i <= 19; i++)
    {
        board[i] = new int[20]();
        if(i != 0)
        {
            for(int j = 1; j <= 19; j++)
            {
                cin >> board[i][j];
            }
        }
    }

    // 가로 먼저 검사.
    rowSearch();

    // 세로 검사
    if(winner == 0)
    {
        colSearch();
    }

    // 대각선 검사
    if(winner == 0)
    {
        diaSearch();
    }
    // 대각선 검사2
    if(winner == 0)
    {
        reverseDiaSearch();
    }

    cout << winner << "\n";
    if(winner != 0)
    {
        cout << start.first << " " << start.second;
    }
}

void check(int i, int j)
{
    if(linearCount == 5 && cur != board[i][j])
    {
        winner = cur;
        return;
    }
    // 빈 칸일 때
    if(board[i][j] == 0)
    {
        cur = 0;
        linearCount = 0;
    }
    else
    {   // 현재 흰or검은돌 && 이전 칸이 빈 칸
        if(cur == 0)
        {
            start.first = i;
            start.second = j;
            linearCount = 1;
            cur = board[i][j];
        }
        else
        {   // 이전칸이 흰or검은돌 && 현재도 같은 색일 때
            if(cur == board[i][j])
            {
                linearCount++;
                cur = board[i][j];
            } // 이전칸 흰or검 && 현재랑 다른 색일 때
            else
            {
                cur = board[i][j];
                linearCount = 1;
                start.first = i;
                start.second = j;
            }          
        } 
    }
}

void rowSearch()
{
    for(int i = 1; i <= 19; i++)
    {
        cur = 0;
        linearCount = 0;
        for(int j = 1; j <= 19; j++)
        {
            check(i,j);
            if(winner != 0)
            {
                return;
            }
        }
        if(linearCount == 5)
        {
            winner = cur;
            return;
        }
    }
}

void colSearch()
{
    // i, j 반전 !!!
    for(int j = 1; j <= 19; j++)
    {
        cur = 0;
        linearCount = 0;
        for(int i = 1; i <= 19; i++)
        {
            check(i,j);
            if(winner != 0)
            {
                return;
            }
        }
        if(linearCount == 5)
        {
            winner = cur;
            return;
        }
    }
}

void diaSearch()
{
    for(int x = 15; x > 0; x--)
    {
        cur = 0;
        linearCount = 0;
        for(int stride = 0; x + stride <= 19; stride++)
        {
            int i = stride + 1;
            int j = x + stride;
            
            check(i,j);
            if(winner != 0)
            {
                return;
            }
        }
        if(linearCount == 5)
        {
            winner = cur;
            return;
        }
    }

    for(int y = 15; y > 0; y--)
    {
        cur = 0;
        linearCount = 0;
        for(int stride = 0; y + stride <= 19; stride++)
        {
            int i = y + stride;
            int j = stride + 1;
            
            check(i,j);
            if(winner != 0)
            {
                return;
            }
        }
        if(linearCount == 5)
        {
            winner = cur;
            return;
        }
    }
}


void reverseDiaSearch()
{
    for(int y = 5; y <= 19; y++)
    {
        cur = 0;
        linearCount = 0;
        for(int stride = 0; y - stride > 0; stride++)
        {
            int i = y - stride;
            int j = stride + 1;

            check(i,j);
            if(winner != 0)
            {
                return;
            }
        }
        if(linearCount == 5)
        {
            winner = cur;
            return;
        }
    }

    for(int x = 15; x > 0; x--)
    {
        cur = 0;
        linearCount = 0;
        for(int stride = 0; x + stride <= 0; stride++)
        {
            int i = 19 - stride;
            int j = x + stride;
            
            check(i,j);
            if(winner != 0)
            {
                return;
            }
        }
        if(linearCount == 5)
        {
            winner = cur;
            return;
        }
    }
}
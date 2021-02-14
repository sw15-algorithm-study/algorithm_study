#include <iostream>

using namespace std;

const int xVector[5] = {0, 1, -1, 0, 0};
const int yVector[5] = {0, 0, 0, -1, 1};

int main()
{
    int row, col, actCount;
    pair<int,int> dicePosition;
    int dice[6] = {0, 0, 0, 0, 0, 0};
    int** board;
    int* actList;

    cin >> row >> col;
    cin >> dicePosition.first >> dicePosition.second;
    cin >> actCount;

    board = new int*[row];
    actList = new int[actCount]();

    for(int i = 0; i < row; i++)
    {
        board[i] = new int[col]();
        for(int j = 0; j < col; j++)
        {
            cin >> board[i][j];
        }
    }  

    for(int i = 0; i < actCount; i++)
    {
        cin >> actList[i];
    }

    int up, down, left, right, front, back;
    up = 1;
    down = 4;
    left = 5;
    right = 2;
    front = 0;
    back = 3;

    for(int i = 0; i < actCount; i++)
    {
        int actVector = actList[i];
        int nextY = dicePosition.first + yVector[actVector];
        int nextX = dicePosition.second + xVector[actVector];

        if(nextY < 0 || nextY >= row || nextX < 0 || nextX >= col)
        {
            continue;
        }
        
        dicePosition.first = nextY;
        dicePosition.second = nextX;

        switch (actVector)
        {
            case 1:
                front = left;
                left = back;
                back = (front + 3) % 6;
                right = (left + 3) % 6;
                break;
            case 2:
                left = front;
                front = right;
                back = (front + 3) % 6;
                right = (left + 3) % 6;
                break;
            case 3:
                up = front;
                front = down;
                back = (front + 3) % 6;
                down = (up + 3) % 6;
                break;
            case 4:
                front = up;
                up = back;
                back = (front + 3) % 6;
                down = (up + 3) % 6;
                break;
            default:
                break;
        }

        if(board[nextY][nextX] != 0)
        {
            dice[back] = board[nextY][nextX];
            board[nextY][nextX] = 0;
        }
        else
        {
            board[nextY][nextX] = dice[back];
        }
        cout << dice[front] << "\n";
    }
}
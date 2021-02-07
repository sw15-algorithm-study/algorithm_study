// 배열을 통해 해결함.
#include <iostream>
#include <vector>

using namespace std;

int** gears;
int* pos;
int* visit;

void turnGear(int gearIndex, int turnVector);

int main()
{
    gears = new int*[4]();
    pos = new int[4](); // 기어별로 현재 12시 방향을 향하는 톱니의 index 저장을 위한 배열.
    visit = new int[4]();

    for(int i = 0; i < 4; i++)
    {
        gears[i] = new int[8]();
        string inputString;
        cin >> inputString;
        // 12시부터 시계방향으로 배열에 값 입력.
        for(int j = 0; j < 8; j++)
        {
            string tmpString = inputString.substr(j,1);
            int tmpNum = atoi(tmpString.c_str());
            gears[i][j] = tmpNum;
        }
    }

    int turnCount;
    cin >> turnCount;

    for(int i = 0; i < turnCount; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            visit[j] = 0;
        }
        int startGear, turnVector;
        cin >> startGear >> turnVector;

        turnGear(startGear-1, turnVector);
    }
    
    int answer = 0;
    int point = 1;
    for(int i = 0; i < 4; i++)
    {
        if(gears[i][pos[i]] == 1)
        {
            answer += point;
        }
        point *= 2;
    }
    cout << answer;
}

void turnGear(int gearIndex, int turnVector)
{
    visit[gearIndex] = 1;

    // 오른쪽 기어 탐색
    if(gearIndex < 3 && visit[gearIndex+1] == 0)
    {
        // 나의 오른쪽(3시) 톱니
        int myRightSide = (pos[gearIndex] + 2) % 8;
        // 내 오른쪽 기어의 왼쪽(9시) 톱니
        int rightLeftSide = (pos[gearIndex+1] + 6) % 8;

        if(gears[gearIndex][myRightSide] != gears[gearIndex+1][rightLeftSide])
        {
            // turnGear 함수가 호출 됐다 -> 회전해야하는 기어다.
            turnGear(gearIndex+1, turnVector*-1);
        }
    }

    // 왼쪽 기어 탐색
    if(0 < gearIndex && visit[gearIndex-1] == 0)
    {
        // 나의 왼쪽(9시) 톱니
        int myLeftSide = (pos[gearIndex] + 6) % 8;
        // 내 왼쪽 기어의 오른쪽(3시) 톱니
        int leftRightSide = (pos[gearIndex-1] + 2) % 8;

        if(gears[gearIndex][myLeftSide] != gears[gearIndex-1][leftRightSide])
        {
            turnGear(gearIndex-1, turnVector*-1);
        }
    }

    // 자기 자신 회전
    // 배열 전체가 움직이는 것이 아닌 pos배열의 값을 변경하여 기어가 회전하는 것처럼 구현.
    int nextPos;
    if(turnVector == 1)
    {
        nextPos = (pos[gearIndex] + 7) % 8;
    }
    else
    {
        nextPos = (pos[gearIndex] + 1) % 8;
    }
    pos[gearIndex] = nextPos;
}
// 이 문제 또한 컨베어 베열이 직접 움직이는 것이 아닌 up, down 인덱스를 바꾸므로써 컨베어회전 구현.
// % 연산 사용에 조심 !! 
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int conSize, th;
    cin >> conSize >> th;
    vector<int> robotPosList;

    conSize = 2 * conSize;
    
    int* conveyor = new int[conSize]();
    bool* isRobot = new bool[conSize]();

    for(int i = 0; i < conSize; i++)
    {
        int tmp;
        cin >> tmp;
        conveyor[i] = tmp;
    }

    int zeroCon = 0;
    int step = 0;
    int up = 0;
    int down = conSize / 2 - 1;

    while(zeroCon < th)
    {
        step++;

        // 1 step
        up = (up + conSize - 1) % conSize;
        down = (down + conSize - 1) % conSize;

        // 2 step
        for(int i = 0 ; i < robotPosList.size(); i++)
        {
            int nowPos = robotPosList[i];
            if(nowPos == down)
            {
                robotPosList.erase(robotPosList.begin() + i);
                isRobot[nowPos] = false;
                i--;
                continue;
            }
            int nextPos = (nowPos + 1) % conSize;
            if(isRobot[nextPos] == false && conveyor[nextPos] > 0)
            {
                robotPosList[i] = nextPos;
                conveyor[nextPos] -= 1;
                if(conveyor[nextPos] == 0)
                {
                    zeroCon++;
                }
                isRobot[nowPos] = false;
                isRobot[nextPos] = true;
                if(nextPos == down)
                {
                    robotPosList.erase(robotPosList.begin() + i);
                    isRobot[nextPos] = false;
                    i--;
                    continue;
                }
            }   
        }

        // 3 step
        if(isRobot[up] == false && conveyor[up] > 0)
        {
            isRobot[up] = true;
            conveyor[up] -= 1;
            if(conveyor[up] == 0)
            {
                zeroCon++;
            }
            robotPosList.push_back(up);
        }
    }

    cout << step;
}
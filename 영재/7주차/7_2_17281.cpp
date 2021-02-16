#include <iostream>
#include <queue>

using namespace std;

int maxScore = 0;
int round;
int** playerList;
int order[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int ground[4] = {0 , 0, 0, 0};
int visit[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void findPermutation(int depth);
void playBall();

int main()
{
    cin >> round;

    playerList = new int*[round]();

    for(int i = 0; i < round; i++)
    {
        playerList[i] = new int[9]();
        for(int j = 0; j < 9; j++)
        {
            int tmpNum;
            cin >> tmpNum;
            playerList[i][j] = tmpNum;
        }
    }

    findPermutation(0);
    
    cout << maxScore;

}

void findPermutation(int depth)
{
    if(depth == 3)
    {
        findPermutation(depth+1);
    }
    else
    {
        for(int i = 1; i < 9; i++)
        {
            if(visit[i] == 1)
            {
                continue;
            }
            else
            {
                order[depth] = i;
                visit[i] = 1;
                if(depth < 8)
                {
                    findPermutation(depth+1);
                }
                else
                {
                    playBall();
                }
            }
            visit[i] = 0;
        }
    }
}

void playBall()
{
    int score = 0;
    int pos = 0;

    for(int i = 0; i < round; i++)
    {
        for(int k = 0; k < 4; k++)
        {
            ground[k] = 0;
        }
        int outCount = 0;
        while (outCount < 3)
        {
            int playerIndex = order[pos];

            if(playerList[i][playerIndex] == 0)
            {
                outCount++;
            }
            else
            {
                ground[0] = 1;
                for(int j = 3; j >= 0; j--)
                {
                    if(ground[j] == 1)
                    {
                        ground[j] = 0;
                        if(j + playerList[i][playerIndex] > 3)
                        {
                            score++;
                        }
                        else
                        {
                            ground[j+playerList[i][playerIndex]] = 1;
                        }
                        
                    }
                }
            }
            pos = (pos+1) % 9;
        }
    }
    if(score > maxScore)
    {
        maxScore = score;
    }
}
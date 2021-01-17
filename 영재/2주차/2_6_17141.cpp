#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void findPosition(int startIndex, int setableSize, int nowDepth, int depth);
void bfs();

int MinTime;
int MapSize;
int** Maps;
int** Simuls;
vector<pair<int,int> > SetablePosition;
vector<pair<int,int> > PositionList;
int Dx[4] = {0, 1, 0, -1};
int Dy[4] = {1, 0, -1, 0};

int main()
{
    int numVirus;

    cin >> MapSize >> numVirus;

    Maps = new int*[MapSize]();
    Simuls = new int*[MapSize]();
    MinTime = MapSize * MapSize;

    for(int i = 0; i < numVirus; i++)
    {
        PositionList.push_back(make_pair(0,0));
    }

    for(int i = 0; i < MapSize; i++)
    {
        Maps[i] = new int[MapSize]();
        Simuls[i] = new int[MapSize]();

        for(int j = 0; j < MapSize; j++)
        {
            cin >> Maps[i][j];
            if(Maps[i][j] == 1)
            {
                Maps[i][j] = -1;
            }
            else if(Maps[i][j] == 2)
            {
                Maps[i][j] = 0;
                SetablePosition.push_back(make_pair(i,j));
            }
            
        }
    }

    findPosition(0, SetablePosition.size(), 1, numVirus);

    if(MinTime == (MapSize*MapSize))
    {
        cout << "-1";
    }
    else
    {
        cout << MinTime-1;
    }
    
}

void bfs()
{
    queue<pair<int,int> > nodeQueue;

    for(int i = 0; i < PositionList.size(); i++)
    {
        nodeQueue.push(make_pair(PositionList[i].first,PositionList[i].second));
        Simuls[PositionList[i].first][PositionList[i].second] = 1;
    }

    int nx, ny, times;

    while(!nodeQueue.empty())
    {
        ny = nodeQueue.front().first;
        nx = nodeQueue.front().second;
        times = Simuls[ny][nx];

        if(times >= MinTime){
            return;
        }

        times += 1;

        nodeQueue.pop();

        int tx, ty;

        for(int i = 0; i < 4; i++)
        {
            tx = nx + Dx[i];
            ty = ny + Dy[i];

            if(tx < 0 || tx >= MapSize || ty < 0 || ty >= MapSize || Simuls[ty][tx] != 0)
            {
                continue;
            }
            else if(Simuls[ty][tx] == 0)
            {
                Simuls[ty][tx] = times;
                nodeQueue.push(make_pair(ty,tx));
            }
                          
        }
    }
    int max = 0;

    for(int i = 0; i < MapSize; i++)
    {
        for(int j = 0; j < MapSize; j++)
        {
            if(Simuls[i][j] == 0)
            {
                return;
            }
            if(max < Simuls[i][j])
            {
                max = Simuls[i][j];
            }
        }
    }

    if(max < MinTime)
    {
        MinTime = max;
    }
}

void findPosition(int startIndex, int setableSize, int nowDepth, int depth)
{
    for(int i = startIndex; i < setableSize; i++)
    {
        PositionList[nowDepth - 1].first = SetablePosition[i].first;
        PositionList[nowDepth - 1].second = SetablePosition[i].second;

        if(nowDepth == depth)
        {
            for(int j = 0; j < MapSize; j++)
            {
                for(int k = 0; k < MapSize; k++)
                {
                    Simuls[j][k] = Maps[j][k];
                }
            }
            bfs();
        }
        else
        {
            findPosition(i+1, setableSize, nowDepth+1, depth);
        }
    }
}
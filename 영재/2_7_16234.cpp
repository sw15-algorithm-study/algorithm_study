#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int y, int x);

bool IsDone;
int MapSize;
int Low;
int High;
int** Maps;
int** Visited;

int Dx[4] = {0, 1, 0, -1};
int Dy[4] = {1, 0, -1, 0};

int main()
{
    int answer = 0;

    cin >> MapSize >> Low >> High;

    IsDone = false;
    Maps = new int*[MapSize]();
    Visited = new int*[MapSize]();

    for(int i = 0; i < MapSize; i++)
    {
        Maps[i] = new int[MapSize]();
        Visited[i] = new int[MapSize]();
        for(int j = 0; j < MapSize; j++)
        {
            cin >> Maps[i][j];
        }
    }

    while(!IsDone)
    {
        IsDone = true;
        for(int i = 0; i < MapSize; i++)
        {
            for(int j = 0; j < MapSize; j++)
            {
                if(Visited[i][j] == 0)
                {
                    bfs(i,j);
                }
            }
        }
        if(IsDone == false)
        {
            answer++;
            for(int i = 0; i < MapSize; i++)
            {
                for(int j = 0; j < MapSize; j++)
                {
                    Visited[i][j] = 0;
                }
            }
        }
    }

    cout << answer;
}

void bfs(int y, int x)
{
    queue<pair<int,int> > nodeQueue;
    vector<pair<int,int> > contryList;

    nodeQueue.push(make_pair(y,x));
    contryList.push_back(make_pair(y,x));

    Visited[y][x] = 1;
    
    int sum = 0;
    int ny, nx, ty, tx;

    while (!nodeQueue.empty())
    {
        ny = nodeQueue.front().first;
        nx = nodeQueue.front().second;

        sum += Maps[ny][nx];

        nodeQueue.pop();

        for(int i = 0; i < 4; i++)
        {
            ty = ny + Dy[i];
            tx = nx + Dx[i];

            if(ty < 0 || ty >= MapSize || tx < 0 || tx >= MapSize || Visited[ty][tx] == 1)
            {
                continue;
            }
            else if( Low <= abs(Maps[ny][nx] - Maps[ty][tx]) && abs(Maps[ny][nx] - Maps[ty][tx]) <= High )
            {
                Visited[ty][tx] = 1;
                contryList.push_back(make_pair(ty,tx));
                nodeQueue.push(make_pair(ty,tx));
            }
        }
    }
    
    if(contryList.size() > 1)
    {
        IsDone = false;
        int average = sum / contryList.size();
        for(int i = 0; i < contryList.size(); i++)
        {
            Maps[contryList[i].first][contryList[i].second] = average;
        }
        contryList.clear();
    }
    
}
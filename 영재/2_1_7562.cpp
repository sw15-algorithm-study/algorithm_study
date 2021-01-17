#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int caseNum = 0;

    cin >> caseNum;

    vector<int> sizeList;
    vector< pair<int,int> > startPositions;
    vector< pair<int,int> > destPositions;
    queue< pair< pair<int,int>, int> > positionQueue;

    int mx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int my[8] = {2, 1, -1, -2, -2, -1, 1, 2};

    for(int i = 0; i < caseNum; i++)
    {
        int num = 0;
        int x = 0, y = 0;

        cin >> num;
        sizeList.push_back(num);

        cin >> x >> y;
        startPositions.push_back(make_pair(x,y));

        cin >> x >> y;
        destPositions.push_back(make_pair(x,y));
    }

    for(int i = 0; i < caseNum; i++)
    {
        positionQueue = queue< pair< pair<int,int>, int> >();
        bool isFound = false;

        int num = sizeList[i];
        int nx = startPositions[i].first;
        int ny = startPositions[i].second;
        int dx = destPositions[i].first;
        int dy = destPositions[i].second;
        int cx = 0;
        int cy = 0;

        int** chess = new int*[num]();
        for(int j = 0; j < num; j++)
        {
            chess[j] = new int[num]();
        }

        if(nx == dx && ny == dy)
        {
                // found!
                cout << "0\n";
        }
        else
        {
            positionQueue.push(make_pair(make_pair(nx, ny), 1));
            chess[nx][ny] = 1;

            int depth;

            while(!isFound && !positionQueue.empty())
            {
                nx = positionQueue.front().first.first;
                ny = positionQueue.front().first.second;
                depth = positionQueue.front().second;

                if(nx == dx && ny == dy)
                {
                    // found!
                    cout << depth << "\n";
                    break;
                }

                positionQueue.pop();

                for(int i = 0; i < 8; i++)
                {
                    cx = nx + mx[i];
                    cy = ny + my[i];

                    if(cx < 0 || num <= cx || cy < 0 || num <= cy)
                    {
                        continue;
                    }

                    if(chess[cx][cy] == 1)
                    {
                        continue;
                    }
                    else
                    {
                        chess[cx][cy] = 1;
                    }

                    if(cx == dx && cy == dy)
                    {
                        // found!
                        cout << depth << "\n";
                        isFound = true;
                        break;
                    }
                    else
                    {
                        positionQueue.push(make_pair(make_pair(cx,cy), depth + 1));
                    }          
                }              
            }
        }
    }

}
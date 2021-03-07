#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int cities, routeNum;
vector<int> route;
int** link;
bool* visit;

bool check(int start, int end);

int main()
{
    cin >> cities;
    cin >> routeNum;

    visit = new bool[cities+1]();
    link = new int*[cities+1]();

    for(int i = 0; i <= cities; i++)
    {
        link[i] = new int[cities+1]();
        if(i != 0)
        {
            for(int j = 1; j <= cities; j++)
            {
                cin >> link[i][j];
            }
        }
    }

    for(int i = 0; i < routeNum; i++)
    {
        int tmp;
        cin >> tmp;
        route.push_back(tmp);
    }

    // ** 자기 자신으로 가는 길도 입력으로 들어오나봄. 이것때문에 틀림...
    for(int i = 1; i <= cities; i++)
    {
        link[i][i] = 1;
    }
    
    string answer = "YES";

    for(int i = 0; i < routeNum - 1; i++)
    {
        int start = route[i];
        int end = route[i+1];

        if(link[start][end] == 1)
        {
            continue;
        }
        else
        {
            if(!check(start,end))
            {
                answer = "NO";
                break;
            }
        }
    }

    cout << answer;


}

bool check(int start, int end)
{
    memset(visit, 0, (cities+1) * sizeof(bool));
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(int i = 1; i <= cities; i++)
        {
            if(visit[i])
            {
                continue;
            }
            if(link[now][i] == 1)
            {
                link[start][i] = 1;
                link[i][start] = 1;
                visit[i] = true;
                if(i == end)
                {
                    while(!q.empty())
                    {
                        q.pop();
                    }
                    return true;
                }
                else
                {
                    q.push(i);
                }
            }
        }
    }

    return false;
}
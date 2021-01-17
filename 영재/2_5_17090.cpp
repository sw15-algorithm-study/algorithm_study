#include <iostream>
#include <vector>

using namespace std;

void check(int y, int x, int col, int row);

char** Maze;
char** IsPossibles;
char** Visited;
int Dx[4] = {0, 1, 0, -1};
int Dy[4] = {-1, 0, 1, 0};

int main()
{
    int row, col;
    int answer = 0;
    cin >> row >> col;

    Maze = new char*[row]();
    IsPossibles = new char*[row]();
    Visited = new char*[row]();

    for(int i = 0; i < row; i++)
    {
        Maze[i] = new char[col]();
        IsPossibles[i] = new char[col]();
        Visited[i] = new char[col]();
        string input;
        cin >> input;
        for(int j = 0; j < col; j++)
        {
            switch (input[j])
            {
                case 'U':
                    Maze[i][j] = 0;
                    break;
                case 'R':
                    Maze[i][j] = 1;
                    break;
                case 'D':
                    Maze[i][j] = 2;
                    break;
                case 'L':
                    Maze[i][j] = 3;
                    break;        
                default:
                    break;
            }
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(IsPossibles[i][j] == 0)
            {
                check(i, j, col, row);
            }
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(IsPossibles[i][j] == 1)
            {
                answer++;
            }
        }
    }

    cout << answer;
}

void check(int y, int x, int col, int row)
{
    int my, mx;
    vector<pair<int,int> > path;
    
    while(true)
    {
        path.push_back(make_pair(y,x));
        Visited[y][x] = 1;

        my = y + Dy[Maze[y][x]];
        mx = x + Dx[Maze[y][x]];

        if(my < 0 || my >= row || mx < 0 || mx >= col || IsPossibles[my][mx] == 1)
        {
            for(int i = 0; i < path.size(); i++)
            {
                IsPossibles[path[i].first][path[i].second] = 1;
            }
            break;
        }
        else if(IsPossibles[my][mx] == -1 || Visited[my][mx] == 1)
        {
            for(int i = 0; i < path.size(); i++)
            {
                IsPossibles[path[i].first][path[i].second] = -1;
            }
            break;
        }
        else
        {
            y = my;
            x = mx;
        }
    }
}

#include <iostream>
#include <vector>

using namespace std;

void dfs(int c, int x, int y);

vector<int> Widths;
vector<int> Heights;
vector<int**> SquareList;
vector<int**> VisitedList;
int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int Dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main()
{

    while(true)
    {
        int w, h;
        cin >> w >> h;

        if(w == 0 && h ==0)
        {
            break;
        }

        Widths.push_back(w);
        Heights.push_back(h);

        int** square = new int*[h]();
        int** visited = new int*[h]();

        for(int i = 0; i < h; i++)
        {
            square[i] = new int[w]();
            visited[i] = new int[w]();

            for(int j = 0; j < w; j++)
            {
                cin >> square[i][j];
            }
        }

        SquareList.push_back(square);
        VisitedList.push_back(visited);
    }

    for(int c = 0; c < SquareList.size(); c++)
    {
        int count = 0;

        for(int i = 0; i < Heights[c]; i++)
        {
            for(int j = 0; j < Widths[c]; j++)
            {
                if(SquareList[c][i][j] == 1 && VisitedList[c][i][j] == 0)
                {
                    dfs(c, i, j);
                    count++;
                }
            }
        }
        cout << count << "\n";
    }


}

void dfs(int c, int y, int x)
{
    int tx, ty;
    for(int i = 0; i < 8; i++)
    {
        tx = x + Dx[i];
        ty = y + Dy[i];

        if(tx < 0 || tx >= Widths[c] || ty < 0 || ty >= Heights[c]){
            continue;
        }
        else if(SquareList[c][ty][tx] == 1 && VisitedList[c][ty][tx] == 0)
        {
            VisitedList[c][ty][tx] = 1;
            dfs(c, ty, tx);
        }
    }
}
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int** sudoku = new int* [9];
    vector<pair<int,int> > holeList;

    int* rows = new int[9]();
    int* cols = new int[9]();
    int* squares = new int[9]();

    for(int i = 0; i < 9; i++)
    {
        sudoku[i] = new int[9];
        for(int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0)
            {
                rows[i]++;
                cols[j]++;
                squares[(i/3)+ (j/3) * 3]++;
                holeList.push_back(make_pair(i,j));
            }
        }
    }

    while(!holeList.empty())
    {
        int row = holeList.back().first;
        int col = holeList.back().second;
        int sum = 0;

        holeList.pop_back();
        
        if(rows[row] == 1)
        {
            for(int j = 0; j < 9; j++)
            {
                sum += sudoku[row][j];
            }
        }
        else if(cols[col] == 1)
        {
            for(int i = 0; i < 9; i++)
            {
                sum += sudoku[i][col];
            }
        }
        else if(squares[(row/3) + (col/3) * 3] == 1)
        {
            int s_row = (row / 3) * 3;
            int s_col = (col/3) * 3;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    sum += sudoku[s_row + i][s_col + j];
                }
            }
        }
        else
        {
            holeList.insert(holeList.begin(), make_pair(row,col));
            continue;
        }

        sum = 45 - sum;
        
        sudoku[row][col] = sum;

        rows[row]--;
        cols[col]--;
        squares[(row/3) + (col/3) * 3]--;
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }


}
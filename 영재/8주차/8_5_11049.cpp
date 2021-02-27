#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int> > matrix;
    vector<vector<pair<int,int> > > mergeMatrix;
    int** dp = new int*[n]();

    for(int i = 0; i < n; i++)
    {
        vector<pair<int,int> > tmpMatrix;
        for(int j = 0; j < n; j++)
        {
            tmpMatrix.push_back(make_pair(0,0));
        }
        mergeMatrix.push_back(tmpMatrix);
    }

    for(int i = 0; i < n; i++)
    {
        dp[i] = new int[n]();
        int front, back;
        cin >> front >> back;
        matrix.push_back(make_pair(front, back));
        mergeMatrix[i][i] = make_pair(front, back);
    }

    // dp[i][i+1]
    for(int i = 0; i < n - 1; i++)
    {
        dp[i][i+1] = mergeMatrix[i][i].first * mergeMatrix[i][i].second * mergeMatrix[i+1][i+1].second;
        mergeMatrix[i][i+1] = make_pair(mergeMatrix[i][i].first, mergeMatrix[i+1][i+1].second);
    }

    for(int s = 2; s < n; s++)
    {
        for(int i = 0; i < n - s; i++)
        {
            int min;
            int indexK;
            for(int k = i; k < i + s; k++)
            {
                int nowCost = mergeMatrix[i][k].first * mergeMatrix[i][k].second * mergeMatrix[k+1][i+s].second + dp[i][k] + dp[k+1][i+s];
                if(k == i)
                {
                    indexK = k;
                    min = nowCost;
                }
                else if(min > nowCost)
                {
                    indexK = k;
                    min = nowCost;
                }
            }
            dp[i][i+s] = min;
            mergeMatrix[i][i+s] = make_pair(mergeMatrix[i][indexK].first, mergeMatrix[indexK+1][i+s].second);
        }
    }

    cout << dp[0][n-1];
}
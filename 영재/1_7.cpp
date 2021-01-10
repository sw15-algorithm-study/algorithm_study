#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    int max = 0;
    int answer = 0;
    int front = 0, back = 0;

    cin >> n;

    int* dp = new int[n]();

    vector<pair<int,int> > lineList;

    for(int i = 0; i < n; i++)
    {
        cin >> front >> back;
        lineList.push_back(make_pair(front, back));
    }

    sort(lineList.begin(), lineList.end());

    for(int i = 0; i < n; i++)
    {
        max = 0;
        if(i == 0)
        {
            dp[i] = 1;
        }
        for(int j = 0; j < i; j++)
        {
            if(lineList[i].second > lineList[j].second && max < dp[j])
            {
                max = dp[j];
            }
        }
        dp[i] = max + 1;
    }

    max = 0;

    for(int i = 0; i < n; i++)
    {
        if(max < dp[i])
        {
            max = dp[i];
        }
    }
    answer = n - max;
    cout << answer;
}
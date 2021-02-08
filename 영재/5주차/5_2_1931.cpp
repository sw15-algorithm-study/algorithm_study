#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<pair<int,int> > times;
    int* dp = new int[num]();
    int answer = 1;

    for(int i = 0; i < num; i++)
    {
        int start, end;
        cin >> start >> end;
        times.push_back(make_pair(start, end));
    }
    sort(times.begin(), times.end());
    
    int endTime = times[0].second;
    for(int i = 1; i < num; i++)
    {
        if(times[i].second < endTime)
        {
            endTime = times[i].second;
        }
        else if(times[i].first >= endTime)
        {
            endTime = times[i].second;
            answer++;
        }
    }

    cout << answer;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> timeList;
    int answer = 0;

    for(int i = 0; i < num; i++)
    {
        int tmpTime;
        cin >> tmpTime;
        timeList.push_back(tmpTime);
    }

    sort(timeList.begin(), timeList.end());

    for(int i = 0; i < num; i++)
    {
        answer += timeList[i] * (num - i);
    }

    cout << answer;
}
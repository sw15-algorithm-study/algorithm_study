#include <iostream>
#include <vector>

using namespace std;

vector<long long> distances;
vector<long long> prices;
long long answer = 0;
int contryNum;

void oilStation(int pos, long long nowPrice);

int main()
{
    cin >> contryNum;

    for(int i = 0; i < contryNum - 1; i++)
    {
        long long tmpDistance;
        cin >> tmpDistance;
        distances.push_back(tmpDistance);
    }
    for(int i = 0; i < contryNum; i++)
    {
        long long tmpPrice;
        cin >> tmpPrice;
        prices.push_back(tmpPrice);
    }

    oilStation(0, prices[0]);

    cout << answer;
}

void oilStation(int pos, long long nowPrice)
{
    answer += distances[pos] * nowPrice;
    if(pos + 1 != contryNum - 1)
        {
        if(prices[pos+1] > nowPrice)
        {
            oilStation(pos+1, nowPrice);
        }
        else
        {
            oilStation(pos+1, prices[pos+1]);
        }
    }
}

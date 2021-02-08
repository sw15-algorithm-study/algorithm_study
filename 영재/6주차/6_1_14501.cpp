#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > counList;
int maxPay = 0;
int n = 0;

void greedy(int pos, int nowPay);

int main()
{
    cin >> n;

    for(int i  = 0; i < n; i++)
    {
        int times, pay;
        cin >> times >> pay;
        counList.push_back(make_pair(times, pay));
    }
    maxPay = 0;

    greedy(0,0);

    cout << maxPay;
}

void greedy(int pos, int nowPay)
{
    // 현재 상담을 선택할 경우
    if(pos + counList[pos].first <= n)
    {
        int nextPay = nowPay + counList[pos].second;
        if(maxPay < nextPay)
        {
            maxPay = nextPay;
        }
        if(pos + counList[pos].first < n)
        {  
            greedy(pos+counList[pos].first, nextPay);
        }
    }
    // 상담을 받지 않는 경우
    if(pos + 1 < n)
    {
        greedy(pos+1, nowPay);
    }
}
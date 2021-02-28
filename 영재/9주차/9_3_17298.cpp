// 오!큰수
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* list = new int[n]();
    int* dp = new int[n]();
    vector<int> indexList;
    
    // 입력
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }


    for(int i = 0; i < n - 1; i++)
    {
        // 자신의 바로 오른쪽이 더 큰경우
        if(list[i] < list[i+1])
        {
            dp[i] = list[i+1];
            // 자신의 왼쪽에 아직 dp칸을 채우지 못한 친구들도 검사
            while(!indexList.empty())
            {
                int pos = indexList.back();
                if(list[pos] < list[i+1])
                {
                    dp[pos] = list[i+1];
                    indexList.pop_back();
                }
                else
                {
                    break;
                }
                
            }
        }
        else
        {
            indexList.push_back(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(dp[i] == 0)
        {
            cout << "-1 ";
        }
        else
        {
            cout << dp[i] << " ";
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testCount;
    cin >> testCount;

    vector<int> testList;

    for(int i = 0; i < testCount; i++)
    {
        int tmpCount;
        cin >> tmpCount;
        testList.push_back(tmpCount);
    }

    int mainSuper, subSuper;
    cin >> mainSuper >> subSuper;

    // **** long long 주의 
    long long answer = 0;

    for(int i = 0; i < testCount; i++)
    {
        answer++;
        // 주감독관 먼저 배정
        testList[i] -= mainSuper;

        if(testList[i] <= 0)
        {
            continue;
        }
        else // 주감독관 혼자 감시할 수 없는 경우
        {
            int subCount = testList[i] / subSuper;
            if(testList[i] % subSuper != 0)
            {
                subCount++;
            }            
            answer += subCount;
        }
    }

    cout << answer;
}
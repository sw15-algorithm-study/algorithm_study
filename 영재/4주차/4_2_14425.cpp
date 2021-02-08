// 집합 S안에 보기로 주어지는 문자열들(M)이 얼마나 속해 있는지 찾는 문제.
// 이진탐색으로 해결함.
// * 중요한 점 *
// 모든 M을 돌며 S를 이진탐색
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int answer = 0;

    vector<string> searched;
    vector<string> searching;

    for(int i = 0; i < n; i++)
    {
        string tmpString;
        cin >> tmpString;
        searched.push_back(tmpString);
    }
    for(int i = 0; i < m; i++)
    {
        string tmpString;
        cin >> tmpString;
        searching.push_back(tmpString);
    }

    sort(searched.begin(), searched.end());

    for(int i = 0; i < m; i++)
    {
        int left = 0;
        int right = n - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if(searched[mid].compare(searching[i]) == 0)
            {
                answer++;
                break;
            }
            else if(searched[mid] < searching[i])
            {
                left = mid + 1;
            }
            else
            {                
                right = mid - 1;
            }           
        }
    }

    cout << answer;
}
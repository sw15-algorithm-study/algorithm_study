#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int caseNum;
    cin >> caseNum;
    vector<string> callNumList;
    vector<string> answerList;

    for(int i = 0; i < caseNum; i++)
    {
        int listNum;
        cin >> listNum;

        for(int j = 0; j < listNum; j++)
        {
            string tmpString;
            cin >> tmpString;
            callNumList.push_back(tmpString);
        }

        // 전화목록부를 오름차순으로 정렬.
        sort(callNumList.begin(), callNumList.end());

        for(int j = 0; j < listNum - 1; j++)
        {
            // 현재 위치에서의 전화번호가 다음 위치의 전화번호보다 길이가 짧아야 겹칠 가능성이 있다.
            if(callNumList[j].size() < callNumList[j+1].size())
            {   // 현재 위치의 전화번호 길이 만큼 다음 위치의 전화번호와 비교.
                if(callNumList[j].compare(callNumList[j+1].substr(0, callNumList[j].size())) == 0)
                {
                    answerList.push_back("NO");
                    break;
                }
            }
            if(j == listNum - 2)
            {
                answerList.push_back("YES");
            }
        }
        callNumList.clear();
    }

    for(int i = 0; i < caseNum; i++)
    {
        cout << answerList[i] << "\n";
    }
}
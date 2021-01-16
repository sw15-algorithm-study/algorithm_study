#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string mainString;
    string bomb;
    vector<char> answer;
    bool isCorrect = false;

    cin >> mainString;
    cin >> bomb;

    int bombSize = bomb.size();
    
    // bomb의 끝 문자를 추출하여 mainString 이랑 비교.
    char lastSpell = bomb[bombSize-1];

    for(int i = 0; i < mainString.size(); i++)
    {
        isCorrect = true;
        // mainString 한 문자씩 추출
        answer.push_back(mainString[i]);
        // 방금 추출한 mainString의 문자가 bomb의 마지막 문자와 같다면 폭발문자열인지 검사
        if(answer.size() >= bombSize && lastSpell == answer.back())
        {
            for(int j = 0; j < bombSize; j++)
            {
                if(answer[answer.size()- bombSize + j] == bomb[j])
                {
                    continue;
                }
                else
                {
                    isCorrect = false;
                    break;
                }
            }
            if(isCorrect)
            {
                // 폭발
                for(int j = 0; j < bombSize; j++)
                {
                    answer.pop_back();
                }
            }
        }
        else
        {
            continue;
        }
        
    }
    if(answer.empty())
    {
        cout << "FRULA";
    }
    else
    {
        for(int i = 0; i < answer.size(); i++)
        {
            cout << answer[i];
        }
    }

}
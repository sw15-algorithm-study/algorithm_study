#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string expression;
    string subNum = "";
    bool isMinus = false;
    cin >> expression;
    int answer = 0;

    vector<int> numList;

    for(int i = 0; i < expression.size(); i++)
    {
        if(expression[i] == '+')
        {
            int tmpNum = atoi(subNum.c_str());
            if(isMinus)
            {
                tmpNum *= -1;
            }
            numList.push_back(tmpNum);
            subNum = "";
        }
        else if(expression[i] == '-')
        {
            int tmpNum = atoi(subNum.c_str());
            if(isMinus)
            {
                tmpNum *= -1;
            }
            numList.push_back(tmpNum);
            subNum = "";
            isMinus = true;
        }
        else
        {
            subNum += expression[i];
            if(i == expression.size() - 1)
            {
                int tmpNum = atoi(subNum.c_str());
                if(isMinus)
                {
                    tmpNum *= -1;
                }
                numList.push_back(tmpNum);
                subNum = "";
            }
        }    
    }
    
    for(int i = 0; i < numList.size(); i++)
    {
        answer += numList[i];
    }
    cout << answer;
}
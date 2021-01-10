#include <iostream>

using namespace std;

int main()
{
    string firstStirng;
    string secondString;
    cin >> firstStirng;
    cin >> secondString;

    int firstNum = firstStirng.size();
    int secondNum = secondString.size();

    int *dp = new int[firstNum]();
    int *posList = new int[firstNum]();

    for(int i = 0; i < firstNum; i++)
    {
        if(i == 0)
        {
            for(int j = 0; j < secondNum; j++)
            {
                if(firstStirng[i] == secondString[j])
                {
                    dp[i]++;
                    posList[i] = j;
                }
            }
        }
        else
        {
            for(int j = posList[i - 1]+1; j < secondNum; j++)
            {
                
            }
        }
        
    }

}
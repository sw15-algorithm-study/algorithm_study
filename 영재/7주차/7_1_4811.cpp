// 카탈란 수.... 경로 문제처럼 생각하자
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> testCaseList;
    long long* catalan = new long long[31]();
    catalan[0] = 1;
    catalan[1] = 1;
    catalan[2] = 2;

    int inputNum;

    while(true)
    {
        cin >> inputNum;
        if(inputNum <= 0)
        {
            break;
        }
        testCaseList.push_back(inputNum);
    }

    for(int i = 3; i <= 30; i++)
    {
        for(int j = 0; j < i; j++)
        {        
            catalan[i] += catalan[i-j-1] * catalan[j];
        }
    }

    for(int i = 0; i < testCaseList.size(); i++)
    {
        int medicineNum = testCaseList[i];
        cout << catalan[medicineNum] << "\n";
    }
}
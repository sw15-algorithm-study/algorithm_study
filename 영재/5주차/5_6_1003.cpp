#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int caseNum;
    cin >> caseNum;
    vector<int> fibonacci;
    int* zeroDp;
    int* oneDp;

    int maxNum = 0;

    for(int i = 0; i < caseNum; i++)
    {
        int tmpFibonacci;
        cin >> tmpFibonacci;
        fibonacci.push_back(tmpFibonacci);
        if(tmpFibonacci > maxNum)
        {
            maxNum = tmpFibonacci;
        }
    }

    zeroDp = new int[maxNum+1]();
    oneDp = new int[maxNum+1]();
    
    zeroDp[0] = 1;
    oneDp[1] = 1;

    for(int i = 2; i <= maxNum; i++)
    {
        zeroDp[i] = zeroDp[i-1] + zeroDp[i-2];
        oneDp[i] = oneDp[i-1] + oneDp[i-2];
    }

    for(int i = 0; i < caseNum; i++)
    {
        cout << zeroDp[fibonacci[i]] << " " << oneDp[fibonacci[i]] << "\n";
    }

}
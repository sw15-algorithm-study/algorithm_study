#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n = 0;
    int maxSum = 0;

    cin >> n;

    int* array = new int[n];
    int* dp = new int[n]();

    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            maxSum = array[i];
            dp[i] = array[i];
        }
        else
        {
            dp[i] = max(array[i], dp[i-1] + array[i]);
            if(maxSum < dp[i])
            {
                maxSum = dp[i];
            }
        }
        
    }

    cout << maxSum;

}

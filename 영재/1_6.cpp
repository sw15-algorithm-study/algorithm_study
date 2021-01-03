#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    
    cin >> n;

    int* array = new int[n];
    int* left = new int[n]();
    int* right = new int[n]();
    int leftMax = 0;
    int rightMax = 0;
    int answer = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for(int i = 0; i < n; i++)
    {
        leftMax = 0;
        rightMax = 0;
        for(int j = 0; j < i; j++)
        {
            if(i != 0)
            {
                if(array[j] < array[i] && leftMax < (left[j] + 1))
                {
                    leftMax = left[j] + 1;
                }
                if(array[n - 1 - j] < array[n - 1 - i] && rightMax < (right[n - 1 - j] + 1))
                {
                    rightMax = right[n - 1 - j] + 1;
                }
            }
        }
        left[i] = leftMax;
        right[n - 1 - i] = rightMax;
    }

    for(int i = 0; i < n; i++)
    {
        left[i] += right[i];
        if(answer < left[i])
        {
            answer = left[i];
        }
    }

    cout << answer + 1;
}
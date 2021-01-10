#include <iostream>

using namespace std;

void findMinStat(int** array, int* left, int* right, int nowDepth, int n, int depth, int startNum);
int g_min;

int main()
{
    int n = 0;
    g_min = -1;

    cin >> n;

    int ** array = new int*[n];
    int *left = new int[n/2];
    int *right = new int[n/2];

    for(int i = 0; i < n; i++)
    {
        array[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            cin >> array[i][j];
        }
    }

    left[0] = 0;

    findMinStat(array, left, right, 2, n, n/2, 1);

    cout << g_min;
    
}

void findMinStat(int** array, int* left, int* right, int nowDepth, int n, int depth, int startNum)
{
    for(int i = startNum; i < n; i++)
    {
        left[nowDepth - 1] = i;
        
        if(nowDepth == depth){
            int leftSum = 0, rightSum = 0;
            int leftPos = 1;
            int rightPos = 0;
            for(int j = 1; j < n; j++)
            {
                if(leftPos > depth || j != left[leftPos]){
                    right[rightPos] = j;
                    rightPos++;
                }
                else{
                    leftPos++;
                }
            }
            for(int k = 0; k < depth; k++)
            {
                for(int p = k + 1; p < depth; p++)
                {
                    leftSum += array[left[k]][left[p]] + array[left[p]][left[k]];
                    rightSum += array[right[k]][right[p]] + array[right[p]][right[k]];
                }
            }
            int sub = abs(leftSum - rightSum);
            if(g_min < 0)
            {
                g_min = sub;
            }
            else if(sub < g_min)
            {
                g_min = sub;
            }
            
        }
        else{
            findMinStat(array, left, right, nowDepth + 1, n, depth, i+1);
        }
    }
}



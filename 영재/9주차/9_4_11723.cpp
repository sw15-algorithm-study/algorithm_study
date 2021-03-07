#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;


int main()
{
    int* S = new int[21]();
    int allS[21];
    for(int i = 0; i < 21; i++)
    {
        allS[i] = 1;;
    }

    int M;
    cin >> M;

    char order[10];
    int inputNum;

    for(int i = 0; i < M; i++)
    {
        scanf("%s", order);

        if(order[1] != 'l' && order[1] != 'm')
        {
            scanf("%d", &inputNum);
        }

        if(order[1] == 'd')
        {
            S[inputNum] = 1;
        }
        else if(order[1] == 'e')
        {
            S[inputNum] = 0;
        }
        else if(order[1] == 'h')
        {
            printf("%d\n", S[inputNum]);
        }
        else if(order[1] == 'o')
        {
            if(S[inputNum] == 1)
            {
                S[inputNum] = 0;
            }
            else
            {
                S[inputNum] = 1;
            }
        }
        else if(order[1] == 'l')
        {
            memcpy(S, allS, 21 * sizeof(int));
        }
        else if(order[1] == 'm')
        {
            memset(S, 0, 21 * sizeof(int));
        }
    }

}
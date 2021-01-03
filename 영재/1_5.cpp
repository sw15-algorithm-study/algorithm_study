#include <iostream>

using namespace std;

int main()
{
    int n = 0;

    cin >> n;

    int* list = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    int * result = new int[n]();

    for(int i = 0; i < n; i++)
    {
        if(i == 0){
            continue;
        }
        else
        {
            int max = -1;
            for(int j = 0; j < i; j++)
            {
                if(list[j] < list[i])
                {
                    if(max < result[j])
                    {
                        max = result[j];
                    }
                }
            }
            if(max > -1){
                result[i] = max + 1;
            }
        }
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        if(answer < result[i])
        {
            answer = result[i];
        }
    }

    cout << answer+1;

    return 0;
}
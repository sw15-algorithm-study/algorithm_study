#include <iostream>

using namespace std;

void findNumList(int * list, int nowDepth, int n, int depth);

int main()
{
    int n , depth = 0;

    cin >> n >> depth;
    
    int * list = new int[depth]();

    findNumList(list, 1, n, depth);

    return 0;

}

void findNumList(int * list, int nowDepth, int n, int depth)
{
    for(int i = 1; i <= n; i++)
    {
        list[nowDepth - 1] = i;
        
        if(nowDepth == depth){
            for(int j = 0; j < depth; j++)
            {
                cout << list[j] << " ";
            }
            cout << "\n";
        }
        else{
            findNumList(list, nowDepth + 1, n, depth);
        }
    }

    return ;
}
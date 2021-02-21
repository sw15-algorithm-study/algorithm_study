#include <iostream>
using namespace std;

int tri[501][501] = {0};

int main(){
    int n, result = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            scanf("%d", &tri[i][j]); 
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
           tri[i][j] = max(tri[i-1][j-1] + tri[i][j], tri[i-1][j] + tri[i][j]);
    for(int i = 1; i <= n; i++)
        result = max(tri[n][i], result);
    printf("%d", result);
    return 0;
}
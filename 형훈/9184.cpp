#include <iostream>
#include <cstring>

using namespace std;

int a, b, c;
int cache[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a >= 21 || b >= 21 || c >= 21)
        return w(20, 20, 20);
    int &result = cache[a][b][c];
    if(result != 0)
        return result;
    if (a < b && b < c)
        result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return result;
}

 

int main(){
    while(1){
        scanf("%d %d %d",&a, &b, &c);
        if(a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;

}
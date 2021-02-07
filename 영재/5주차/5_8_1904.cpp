#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long* tiles = new long long[n+1]();

    tiles[1] = 1;
    tiles[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        tiles[i] = (tiles[i-1] + tiles[i-2]) % 15746;
    }

    cout << tiles[n];
}
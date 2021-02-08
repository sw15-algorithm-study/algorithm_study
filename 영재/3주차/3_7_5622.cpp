// 쉬우니 주석 생략.
#include <iostream>

using namespace std;

int main()
{
    int times[26]= {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

    string input;

    cin >> input;

    int index = 0;
    int sum = 0;

    for(int i = 0; i < input.size(); i++)
    {
        index = int((char)input[i] - 'A');
        sum += times[index];
    }

    cout << sum;
}
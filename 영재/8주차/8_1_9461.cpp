#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long triangle[100] = {0,};

    triangle[0] = 1;
    triangle[1] = 1;
    triangle[2] = 1;
    triangle[3] = 2;
    triangle[4] = 2;

    for(int i = 5; i < 100; i++)
    {
        triangle[i] = triangle[i - 1] + triangle[i - 5];
    }

    int input;
    vector<int> inputList;

    int testNum;
    cin >> testNum;
    for(int i = 0; i < testNum; i++)
    {
        cin >> input;
        inputList.push_back(input);
    }

    for(int i = 0; i < inputList.size(); i++)
    {
        cout << triangle[inputList[i] - 1] << "\n";
    }
}
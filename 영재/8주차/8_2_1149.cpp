#include <iostream>
#include <vector>

using namespace std;

struct House
{
    int r;
    int g;
    int b;
};

int main()
{
    int houseNum;
    int answer = 0;
    vector<House> houseList;
    cin >> houseNum;

    int ** dp = new int*[3]();

    for(int i = 0; i < houseNum; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        House tmpHouse = {r, g, b};
        houseList.push_back(tmpHouse);
    }

    for(int i = 0; i < 3; i++)
    {
        dp[i] = new int[houseNum]();
    }

    dp[0][0] = houseList[0].r;
    dp[1][0] = houseList[0].g;
    dp[2][0] = houseList[0].b;

    for(int x = 1; x < houseNum; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            int nowCost;
            switch(y)
            {
                case 0 :
                    nowCost = houseList[x].r;
                    break;
                case 1 :
                nowCost = houseList[x].g;
                break;
                case 2 :
                nowCost = houseList[x].b;
                break;
            }
            dp[y][x] = min(dp[(y+1)%3][x-1], dp[(y+2)%3][x-1]) + nowCost;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(i == 0)
        {
            answer = dp[i][houseNum-1];
        }
        else if(answer > dp[i][houseNum-1])
        {
            answer = dp[i][houseNum-1];
        }
    }

    cout << answer;
}
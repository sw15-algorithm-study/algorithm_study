#include <iostream>
#include <vector>

using namespace std;

struct Book
{
    int danNum;
    vector<int> fileSize;
};

int main()
{
    int testNum;
    cin >> testNum;
    long long** dp;
    int** sumDp;
    vector<Book> bookList;

    for(int i = 0; i < testNum; i++)
    {
        Book tmpBook;
        cin >> tmpBook.danNum;
        for(int j = 0; j < tmpBook.danNum; j++)
        {
            int tmpSize;
            cin >> tmpSize;
            tmpBook.fileSize.push_back(tmpSize);
        }
        bookList.push_back(tmpBook);
    }

    for(int c = 0; c < testNum; c++)
    {
        int n = bookList[c].danNum;

        dp = new long long*[n]();
        sumDp = new int*[n]();

        for(int k = 0; k < n; k++)
        {
            dp[k] = new long long[n]();
            sumDp[k] = new int[n]();
        }
        // [i][i] 채우기
        for(int i = 0; i < n; i++)
        {
            //dp[i][i] = bookList[c].fileSize[i];
            sumDp[i][i] = bookList[c].fileSize[i];
        }

        // [i][i+1] 채우기
        for(int i = 0; i < n - 1; i++)
        {
            dp[i][i+1] = bookList[c].fileSize[i] + bookList[c].fileSize[i+1];
            sumDp[i][i+1] = sumDp[i][i] + sumDp[i+1][i+1];
        }

        for(int x = 2; x < n; x++)
        {
            for(int y = 0; y < n - x; y++)
            {
                long long minCost;
                for(int k = y; k < y + x; k++)
                {
                    if(k == y)
                    {
                        minCost = sumDp[y][k] + sumDp[k+1][y+x] + dp[y][k] + dp[k+1][y+x];
                    }
                    else
                    {
                        long long tmpCost = sumDp[y][k] + sumDp[k+1][y+x] + dp[y][k] + dp[k+1][y+x];
                        if(tmpCost < minCost)
                        {
                            minCost = tmpCost;
                        }
                    }  
                }
                dp[y][y+x] = minCost;
                sumDp[y][y+x] = sumDp[y][y] + sumDp[y+1][y+x];
            }
        }

        cout << dp[0][n-1] << "\n";
        delete[] dp;
        delete[] sumDp;
    }
}
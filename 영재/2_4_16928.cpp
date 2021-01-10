#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<pair<int, int> > nextNodeAndCount;
    int* gameBoard = new int[101]();
    int* visited = new int[101]();
    int numLadder = 0;
    int numSnake = 0;

    cin >> numLadder >> numSnake;

    for(int i = 0; i < numLadder + numSnake; i++)
    {
        int x, y;
        cin >> x >> y;
        gameBoard[x] = y;
    }
    
    nextNodeAndCount.push(make_pair(1,1));
    visited[1] = 1;

    while(!nextNodeAndCount.empty())
    {
        int nowNode = nextNodeAndCount.front().first;
        int count = nextNodeAndCount.front().second;

        nextNodeAndCount.pop();

        int nextNode = 0;

        for(int i = 1; i < 7; i++){
            nextNode = nowNode + i;

            if(nextNode > 100 || visited[nextNode] == 1)
            {
                continue;
            }
            else if(nextNode == 100)
            {
                cout << count;
                return 0;
            }
            else
            {
                visited[nextNode] = 1;
                if(gameBoard[nextNode] == 0)
                {
                    nextNodeAndCount.push(make_pair(nextNode, count + 1));
                }
                else if(gameBoard[nextNode] > nextNode)
                {
                    nextNode = gameBoard[nextNode];
                    visited[nextNode] = 1;
                    while(gameBoard[nextNode] > nextNode){
                        nextNode = gameBoard[nextNode];
                        visited[nextNode] = 1;
                    }
                    nextNodeAndCount.push(make_pair(nextNode,count +1));
                }
                else
                {
                    nextNode = gameBoard[nextNode];
                    visited[nextNode] = 1;
                    while(gameBoard[nextNode] != 0 && gameBoard[nextNode] < nextNode){
                        nextNode = gameBoard[nextNode];
                        visited[nextNode] = 1;
                    }
                    nextNodeAndCount.push(make_pair(nextNode,count +1));
                }
                
            }
        }
    }
}
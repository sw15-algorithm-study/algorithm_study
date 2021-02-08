#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int nodeNum, root;
    int answer = 0;
    cin >> nodeNum;

    // 해당 노드의 부모 노드 인덱스 저장.
    int* parentNum = new int[nodeNum]();
    // 자식 노드의 갯수 저장.
    int* childNum = new int[nodeNum]();
    // 자식 노드 리스트.
    vector<vector<int> > childList;

    for(int i = 0; i < nodeNum; i++)
    {
        vector<int> tmpNode;
        childList.push_back(tmpNode);
    }

    // 입력 받으며 자신의 부모 노드 저장 및 자식노드리스트 추가.
    for(int i = 0; i < nodeNum; i++)
    {
        int inputNum;
        cin >> inputNum;
        if(inputNum == -1)
        {
            root = i;
            parentNum[i] = -1;
        }
        else
        {
            childNum[inputNum]++;
            childList[inputNum].push_back(i);
            parentNum[i] = inputNum;
        }
    }

    int deletedNode;

    cin >> deletedNode;

    queue<int> q;

    q.push(deletedNode);

    int nowNode;
    // 큐를 돌며 삭제해야하는 노드들의 자식 노드들을 큐에 추가
    while(!q.empty())
    {
        nowNode = q.front();
        q.pop();
        if(parentNum[nowNode] != -1)
        {
            // 자기 자신이 사라지기 떄문에 자신의 부모노드의 자식갯수 -1
            childNum[parentNum[nowNode]]--;
        }
        // 만약에 0 이라면 리프노드이기 때문에 -1로 갱신
        childNum[nowNode] = -1;

        for(int i = 0; i < childList[nowNode].size(); i++)
        {
            q.push(childList[nowNode][i]);
        }
    }

    // 리프노드의 갯수 측정.
    for(int i = 0; i < nodeNum; i++)
    {
        if(childNum[i] == 0)
        {
            answer++;
        }
    }

    cout << answer;
}
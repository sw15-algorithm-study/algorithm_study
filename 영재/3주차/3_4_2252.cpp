// 위상정렬 사용. 위상정렬이 무엇인지 몰라 공부한 후 품.
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int studentNum, conditionNum;
    cin >> studentNum >> conditionNum;

    // 현재 남은 간선의 수
    int* restConditionList = new int[studentNum+1]();

    // 3 -> 4 일때 backList[3] 에 4 추가
    vector<vector<int> > backList;

    queue<int> q;
    vector<int> answer;

    for(int i = 0; i < studentNum+1; i++)
    {
        vector<int> tmpVector;
        backList.push_back(tmpVector);
    }

    for(int i = 0; i < conditionNum; i++)
    {
        int front, back;
        cin >> front >> back;
        restConditionList[back]++;
        backList[front].push_back(back);
    }

    // 조건이 필요없는 녀석들, 즉 간선이 남아 있지 않은 노드 큐에 삽입
    for(int i = 1; i <= studentNum; i++)
    {
        if(restConditionList[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int candi = q.front();
        // 큐 -> 답 으로 이동
        q.pop();
        answer.push_back(candi);

        // 방금 큐에서 꺼낸 노드가 조건인 노드들의 간선 수 -1
        while(!backList[candi].empty())
        {
            int back = backList[candi].back();
            backList[candi].pop_back();
            restConditionList[back]--;
            // 더이상 관련된 간선이 없다면 큐에 삽입
            if(restConditionList[back] == 0)
            {
                q.push(back);
            }
        }
    }

    // 입력은 위상정렬에서 사이클이 생기지 않는 다는 보장이 있었기 때문에 추가 검사 안함.

    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}
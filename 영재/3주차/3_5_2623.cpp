// 3_4 문제와 동일하나 내가 간선 관계를 만들어야 하며 마지막에 위상정렬 가능 여부를 확인 해야함.

#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int main()
{
    int singerNum, pdNum;
    cin >> singerNum >> pdNum;

    int* restConditionList = new int[singerNum+1]();
    vector<vector<int> > conditionVector;
    queue<int> q;
    vector<int> answer;

    for(int i = 0; i < singerNum+1; i++)
    {
        vector<int> tmpVector;
        conditionVector.push_back(tmpVector);
    }

    for(int i = 0; i < pdNum; i++)
    {
        int count;
        cin >> count;
        int preNum = -1;
        int nowNum = 0;
        for(int j = 0; j < count; j++)
        {
            cin >> nowNum;
            if(preNum == -1)
            {
                preNum = nowNum;
            }
            else
            {
                restConditionList[nowNum]++;
                conditionVector[preNum].push_back(nowNum);
                preNum = nowNum;
            }
            
        }
    }

    for(int i = 1; i <= singerNum; i++)
    {
        if(restConditionList[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int candi = q.front();
        q.pop();
        answer.push_back(candi);

        while (!conditionVector[candi].empty())
        {
            int back = conditionVector[candi].back();
            conditionVector[candi].pop_back();
            restConditionList[back]--;
            if(restConditionList[back] == 0)
            {
                q.push(back);
            }
        }
        
    }

    if(answer.size() != singerNum)
    {
        cout << "0";
    }
    else
    {
        for(int i = 0; i < singerNum; i++)
        {
            cout << answer[i] << "\n";
        }
    }
    
    

}
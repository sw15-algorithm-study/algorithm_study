// ** 정렬의 순서를 잘 생각하자 ** //
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct State
{
    int start;
    int dest;
    int count;
};

bool compare(State a, State b);

int main()
{
    int villNum, maxBox, stateNum;
    int* putCount;
    int answer = 0;
    cin >> villNum >> maxBox;
    cin >> stateNum;

    putCount = new int[villNum];
    for(int i = 0; i < villNum; i++)
    {
        putCount[i] = maxBox;
    }

    vector<State> course;

    for(int i = 0; i < stateNum; i++)
    {
        State tmpState;
        cin >> tmpState.start >> tmpState.dest >> tmpState.count;
        course.push_back(tmpState);
    }

    sort(course.begin(), course.end(), compare);
    
    for(int i = 0; i < course.size(); i++)
    {
        bool canMove = true;
        int moveBox = course[i].count;
        int pos = course[i].start;
        while(pos < course[i].dest)
        {
            if(putCount[pos] == 0)
            {
                canMove = false;
                break;
            }
            moveBox = putCount[pos] < moveBox ? putCount[pos] : moveBox;
            pos++;
        }
        if(canMove)
        {
            for(int p = course[i].start; p < course[i].dest; p++)
            {
                putCount[p] -= moveBox;
            }
            answer += moveBox;
        }
    }

    cout << answer;
}



bool compare(State a, State b)
{
    if(a.dest == b.dest)
    {
        return a.start > b.start;
    }
    else
    {
        return a.dest < b.dest;
    }
    
    
}
#include <iostream>

using namespace std;

int main()
{
    // 심사대 , 일행수
    long long desks, friends;
    long long right = 0;
    long long left = 0;
    long long avg = 0;
    long long count = 0;
    long long answer = 0;
    
    cin >> desks >> friends;

    // 심사대 별 심사소요시간
    long long* times = new long long[desks];

    for(int i = 0; i < desks; i++)
    {
        cin >> times[i];
        if(times[i] > right)
        {
            right = times[i];
        }
    }

    right = right * friends;
    answer = right;

    while(left <= right)
    {
        // avg = 소요되는 시간, 중간값 구하기
        avg = (left + right) / 2;
        count = 0;
        // avg / times 를 통해 해당 시간에 처리할 수 있는 인원 구하기
        for(int i = 0; i < desks; i++)
        {
            count += avg / times[i];
        }

        if(count < friends)
        {
            left = avg + 1;
        }
        else
        {
            if(avg < answer)
            {
                answer = avg;
            }
            right = avg - 1;
        }
    }

    cout << answer;


}
// 간단한 문제이나 "dz" 구문에서 실수가 있었음.
#include <iostream>

using namespace std;

int main()
{
    string table[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    string input;

    cin >> input;

    int answer = 0;

    for(int i = 0; i < input.size(); i++)
    {
        if(i == input.size() -1)
        {
            answer++;
            break;
        }
        if(input[i] == 'd' && input[i+1] == 'z' && i+2 < input.size() && input[i+2] == '=')
        {
            answer++;
            i = i + 2;
        }
        else
        {
            string substr = input.substr(i,2);
            for(int j = 0; j < 8; j++)
            {
                if(substr.compare(table[j]) == 0)
                {
                    i++;
                    break;
                }
            }
            answer++;
        }
        
    }

    cout << answer;
}
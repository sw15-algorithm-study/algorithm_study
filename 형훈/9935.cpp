#include <iostream>

using namespace std;

string str;
string bomb;
char result[1000000];

int main(){
    cin >> str >> bomb;
    int j = 0;
    for(int i = 0; i < str.length(); i++){                //str을 하나씩 result에 넣음
        result[j++] = str[i];
        if(result[j - 1] == bomb[bomb.length() - 1]){     //대입 문자열이 폭탄문자열의 마지막과 같다면
            bool find = true;
            if (j - bomb.length() < 0)                  //폭탄길이보다 작으면 아무것도 아님
                continue;
            for(int k = 0; k < bomb.length(); k++){                   //뒤에서부터 비교
                if(result[j - 1 - k] != bomb[bomb.length() - 1 - k]){ //폭탄문자열이아니면 그만
                    find = false;
                    break;
                }
            }
            if(find)                //폭탄문자열을 포함하고 있으면
                j -= bomb.length();
        }
    }
    if(j != 0)
        for(int i = 0; i < j; i++)  //j까지 출력
            printf("%c", result[i]);
    else
        printf("FRULA");
}
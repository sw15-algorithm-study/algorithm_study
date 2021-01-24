#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main(void){
    int N, M;
    map<string, int> m;
    int answer = 0;

    cin >> N >> M;

    //집합 S에 포함되는 문자열 s
    //s를 key 값으로 하는 value는 1로 저장.
    for(int i = 0; i < N; i++){
        string s;

        cin >> s;
        m[s] = 1;
    }

    //M개의 문자열을 입력받는 s.
    //s를 key 값으로 하는 요소 중에서 value가 1이면 집합 S에 포함되는 문자열이다.
    for(int i = 0; i < M; i++){
        string s;

        cin >> s;

        if(m[s] == 1){
            answer++;
        }
    }

    cout << answer;

    return 0;
}
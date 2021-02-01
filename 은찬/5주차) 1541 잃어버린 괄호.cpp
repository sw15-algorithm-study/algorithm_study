#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void){
    string s, tmp = "";
    int ans = 0, sum = 0;
    vector<int> v;
    bool plus = false;

    cin >> s;

    //문자열 파싱
    //-가 나오면 앞에서 + 기호가 있는지 확인.
    //만약 +가 앞에 있었다면 지금까지 더한 값을 v에 삽입
    //만약 +가 앖에 없었다면 현재 값을 v에 삽입
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-'){
            if(plus){
                sum += stoi(tmp);
                v.push_back(sum);
                sum = 0;
            }
            else{
                v.push_back(stoi(tmp));
            }
            tmp = "";
            plus = false;
        }
        else if(s[i] == '+'){
            sum += stoi(tmp);
            plus = true;
            tmp = "";
        }
        else{
            tmp += s[i];
        }
    }

    if(plus){
        sum += stoi(tmp);
        v.push_back(sum);
    }
    else{
        v.push_back(stoi(tmp));
    }

    //ans에 처음 값 저장
    ans = v[0];

    //v에 저장되어 있는 값 모두 뺄셈 진행
    for(int i = 1; i < v.size(); i++){
        ans -= v[i];
    }

    cout << ans;

    return 0;
}
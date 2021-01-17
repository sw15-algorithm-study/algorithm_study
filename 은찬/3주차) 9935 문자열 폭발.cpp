#include <iostream>
#include <string>

using namespace std;

int main(void){
    string s, bomb, answer = "";
    int size = 0;

    cin >> s;
    cin >> bomb;

    size = bomb.length() - 1;

    for(int i = 0; i < s.size(); i++){
        answer += s[i];

        if(answer[answer.length() - 1] == bomb[size]){
            if(answer.length() >= size){
                int count = 1;
                for(int j = size - 1; j >= 0; j--){
                    if(answer[answer.length() - (size - j) - 1] == bomb[j]){
                        count++;
                    }
                }    

                if(count == size + 1){
                    for(int j = 0; j < size + 1; j++){
                        answer.pop_back();
                    }
                }
            }
        }
    }

    if(answer.empty()){
        cout << "FRULA";
    }
    else{
        cout << answer;
    }
    return 0;
}
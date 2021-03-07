#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    set<int> S;
    set<int> allS = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        int num;

        cin >> s;

        if(s != "all" && s != "empty"){
            cin >> num;
        }

        if(s == "add"){
            if(S.find(num) == S.end()){
                S.insert(num);
            }
        }
        else if(s == "remove"){
            if(S.find(num) != S.end()){
                S.erase(num);
            }
        }
        else if(s == "check"){
            if(S.find(num) != S.end()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(s == "toggle"){
            if(S.find(num) != S.end()){
                S.erase(num);
            }
            else{
                S.insert(num);
            }
        }
        else if(s == "all"){
            S = allS;
        }
        else if(s == "empty"){
            S.clear();
        }
    }

    return 0;
}
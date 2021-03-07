#include <iostream>
#include <set>
#include <string>

using namespace std;

int m, x;
string str;
set<int> s;
set<int> s_all = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> str;
        if(str == "add"){
            cin >> x;
            s.insert(x);
        }
        else if(str == "remove"){
            cin >> x;
            s.erase(x);
        }
        else if(str == "check"){
            cin >> x;
            if(s.find(x) != s.end())
                printf("1\n");
            else
                printf("0\n");
        }
        else if(str == "toggle"){
            cin >> x;
            if(s.find(x) != s.end())
                s.erase(x);
            else
                s.insert(x);
        }
        else if(str == "all")
            s = s_all;
        else if(str == "empty")
            s.clear();
    }
}
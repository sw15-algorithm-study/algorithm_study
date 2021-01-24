#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int t;

    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        bool check = false;
        vector<string> phone;

        cin >> n;

        for(int j = 0; j < n; j++){
            string s;
            cin >> s;
            phone.push_back(s);
        }

        sort(phone.begin(), phone.end());

        for(int j = 0; j < phone.size() - 1; j++){
            int current = phone[j].size();
            int compare = phone[j + 1].size();

            if(current == compare){
                continue;
            }
            else{
                if(phone[j + 1].substr(0, current) == phone[j]){
                    check = true;
                    break;
                }
            }
        }

        if(check){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
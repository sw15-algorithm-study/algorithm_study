#include <iostream>
#include <string>
using namespace std;
 
string s[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
string t;

int main(void) {
    cin >> t;
    size_t start_pos;
    for (int i = 0; i < 8; ++i) {
        start_pos = 0;
        while ((start_pos = t.find(s[i], start_pos)) != string::npos) {
            t.replace(start_pos, s[i].length(), "O");
            start_pos += 1;
        }
    }
    printf("%d",t.size());
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t, n;
string s;
vector<string> v;
int main(){
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        v.resize(0);                        //벡터초기화
        bool result = true;                 //변수초기화
        for(int j = 0; j < n; j++){
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());           //정렬
        for(int k = 0; k < v.size()-1; k++){
            int tmp = 0;
            for(int m = 0; m < v[k].length(); m++){
                if(v[k][m] == v[k+1][m])    //문자가 같으면 1씩증가
                    tmp++;
            }
            if(tmp == v[k].length()){       //같다는 것은 접두어라는 말
                printf("NO\n");
                result = false;
                break;
            }
        }
        if(result == true)
            printf("YES\n");
    }
}
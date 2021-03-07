#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent(500001);

int getParent(int x){
    //부모 노드 찾기
    if(parent[x] == x){
        return x;
    }
    return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b){
    //각 노드의 부모 노드 찾기
    a = getParent(a);
    b = getParent(b);
    
    //만약 부모가 같으면 사이클이 형성됐기 때문에 1 리턴
    //부모가 같지 않으면 둘 중 부모의 값이 더 작은 값으로 부모를 만든 후 0 리턴
    if(a == b){
        return true;
    }
    else if(a < b){
        parent[b] = a;
        return false;
    }
    else{
        parent[a] = b;
        return false;
    }
}

int main(void){
    //union-find로 찾기
    int n, m;

    cin >> n >> m;

    //처음에 각 노드는 자신의 번호를 가리킨다.
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    //union-find
    for(int i = 1;i <= m; i++){
        int a, b;

        cin >> a >> b;

        //리턴값이 1이면 사이클 형성
        if(unionParent(a, b)){
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}
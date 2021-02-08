#include <iostream>
#include <vector>

using namespace std;

int n, deleteNode;
pair<int, bool> parent[51];     //부모노드, true - leaf아님 false - leaf임
vector<int> ancestor[51];

int countLeaf(void){
        for(int i = 0; i < n; i++)                  //조상 중에 deleteNode가 있으면 삭제된 노드이므로
            for(int j = 0; j < ancestor[i].size(); j++)
                if(ancestor[i][j] == deleteNode)
                    parent[i].second = true;        //leaf가 아니다
        for(int i = 0; i < n; i++)                  //삭제된 노드 제외하고 다시 자식 여부 파악
            if(i!=deleteNode)
                parent[parent[i].first].second = true; //leaf가 아니다
        //leaf 노드 개수 센다
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(parent[i].second == false)
                cnt++;
        return cnt;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &parent[i].first);
        parent[parent[i].first].second = true;
    }
    for(int i = 0; i < n; i++){         //조상
        int curParent = parent[i].first;
        while(curParent != -1){
            ancestor[i].push_back(curParent);
            curParent = parent[curParent].first;
        }
    }
    scanf("%d", &deleteNode);
    parent[deleteNode].second = true;  //삭제된 노드는 leaf가 아니다
    parent[parent[deleteNode].first].second = false; //삭제된 노드의 부모는 leaf이다
    cout << countLeaf() << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
vector<vector<int>> tree(50);

void deleteNode(int start, int M){
    //자식 노드가 비어있으면 리턴.
    if(tree[start].empty()){
        return;
    }

    //자식 노드들을 반복자를 통해 확인
    //자식 노드 중 M번 노드가 있다면 erase를 해주고 종료.
    for(auto itr = tree[start].begin(); itr != tree[start].end(); itr++){
        if(*itr != M){
            deleteNode(*itr, M);
        }
        else{
            tree[start].erase(itr);
            return;
        }
    }
}

//dfs를 통해 자식 노드가 없다면 리프 노드.
void dfs(int start){
    if(tree[start].empty()){
        answer++;
        return;
    }

    for(int i = 0; i < tree[start].size(); i++){
        dfs(tree[start][i]);
    }
}

int main(void){
    int N, M;
    int root;

    cin >> N;


    //parent가 -1이면 루트,
    //아니면 tree[parent]에 i 노드를 이어준다.
    for(int i = 0; i < N; i++){
        int parent;
        cin >> parent;

        if(parent == -1){
            root = i;
        }
        else{
            tree[parent].push_back(i);
        }
    }

    cin >> M;

    //지우려고 하는 노드가 루트이면 0 리턴
    //아니면 deleteNode를 통해 M번 노드를 지우고, dfs로 리프 노드 카운팅
    if(root == M){
        answer = 0;
    }
    else{
        deleteNode(root, M);
        dfs(root);
    }
    
    cout << answer;
    return 0;
}
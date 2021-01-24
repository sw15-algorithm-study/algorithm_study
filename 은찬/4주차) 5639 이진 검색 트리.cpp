#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int num;
    Node * left = NULL;
    Node * right = NULL;
};

vector<Node> tree(1000001);

//부모 노드의 번호와 자식 노드의 번호 비교하면서 왼쪽, 오른쪽에 노드 입력
void makeTree(Node * node, int index){
    if(node->num > tree[index].num){
        if(node->left == NULL){
            node->left = &tree[index];
        }
        else{
            makeTree(node->left, index);
        }
    }
    else{
        if(node->right == NULL){
            node->right = &tree[index];
        }
        else{
            makeTree(node->right, index);
        }
    }
}

//후위 순회
void postorder(Node * node){
    if(node->left != NULL){
        postorder(node->left);
    }

    if(node->right != NULL){
        postorder(node->right);
    }
    
    cout << node->num << endl;
}

int main(void){
    int tmp, cnt = 0;
    Node * root;

    //Node형 벡터 tree에 노드 번호 입력
    while(cin >> tmp){
        tree[cnt++].num = tmp;
    }
    
    //입력받은 값 중 첫번째 번호가 무조건 루트
    root = &tree[0];

    //이진 트리 만들기
    for(int i = 1; i < cnt; i++){
        makeTree(root, i);
    }

    //후위 순회 출력
    postorder(root);

    return 0;
}
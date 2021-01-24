#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    char c;
    Node * left = NULL;
    Node * right = NULL;
};

//전위 순회
void preorder(Node * node){
    cout << node->c;

    if(node->left != NULL){
        preorder(node->left);
    }

    if(node->right != NULL){
        preorder(node->right);
    }
}

//중위 순회
void inorder(Node * node){
    if(node->left != NULL){
        inorder(node->left);
    }

    cout << node->c;

    if(node->right != NULL){
        inorder(node->right);
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

    cout << node->c;
}

int main(void){
    int N;
    vector<Node> node(26);
    Node * root;

    cin >> N;

    //알파벳에 따라 노드 이어주기
    for(int i = 0; i < N; i++){
        char parent, left, right;

        cin >> parent >> left >> right;
        node[parent - 'A'].c = parent;

        if(left != '.'){
            node[parent - 'A'].left = &node[left - 'A'];
        }
        if(right != '.'){
            node[parent - 'A'].right = &node[right - 'A'];
        }
    }

    root = &node[0];

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}
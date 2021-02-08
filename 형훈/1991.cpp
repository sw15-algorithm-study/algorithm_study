#include <iostream>

using namespace std;
struct node{
    char left;
    char right;
};
node arr[27];
int n;
char a, b, c;

void preorder(char root){
    if(root == '.')
        return;
    printf("%c", root);
    preorder(arr[root].left);
    preorder(arr[root].right);
}
void inorder(char root){
    if(root == '.')
        return;
    inorder(arr[root].left);
    printf("%c", root);
    inorder(arr[root].right);
}
void postorder(char root){
    if(root == '.')
        return;
    postorder(arr[root].left);
    postorder(arr[root].right);
    printf("%c", root);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }
    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
}
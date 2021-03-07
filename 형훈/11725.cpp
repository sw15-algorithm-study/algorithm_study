#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, a, b;
struct node{
    int parents = 0;
};
struct node arr[100001];
vector<int> v[100001];
queue<int> q;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    arr[1].parents = 1;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++)
            if(arr[v[x][i]].parents == 0){      //�θ� ��������� ������
                q.push(v[x][i]);                //queue�� �ְ�
                arr[v[x][i]].parents = x;       //���� ��带 �θ�� ����
            }
    }
    for(int i = 2; i <= n; i++)
        printf("%d\n", arr[i].parents);
}
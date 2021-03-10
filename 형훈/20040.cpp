#include <iostream>

using namespace std;

int n, m;
int parents[500001];

int find(int x){            //부모노드 찾기
    if(x == parents[x])
        return x;
    else
        return parents[x] = find(parents[x]);
}

bool union_node(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)          //루트노드가 같으면 순환
        return true;
    else{
        parents[a] = b;
        return false;
    }
}

int main(){
    int input1, input2;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        parents[i] = i;                 //자기자신이 부모
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &input1, &input2);
        if(union_node(input1,input2)){  //true가 return 되면 순환
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
}
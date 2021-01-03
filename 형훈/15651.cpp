#include <iostream>

using namespace std;

int n, m;
int arr[7] = {1,2,3,4,5,6,7};
int result[7] = {0};

void backtracking(int a){
    if(a == m){
        for(int j = 0; j < m; j++){
            printf("%d ", result[j]);
        }
        printf("\n");
    }
    else{
        for(int i = 0; i < n; i++){
            result[a++] = arr[i];
            backtracking(a--);
        }
    }
}

int main(){
    scanf("%d %d",&n, &m);
    backtracking(0);
    return 0;
}
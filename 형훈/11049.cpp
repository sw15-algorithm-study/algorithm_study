#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int matrix[501][2];
int minmatrix[501][501];

int mincal(int left, int right){
    if(left == right)
        return 0;
    int &result = minmatrix[left][right];
    if(result != -1)                        //�̹� �ּ� ���� ������ �ִٸ�
        return result;
    result = 2123456789;                    //�ƴ϶�� ū �� ����(max�ٻ簪��)
    for(int i = left; i < right; i++)
        result = min(result, mincal(left, i) + mincal(i+1, right) + matrix[left][0] * matrix[i][1] * matrix[right][1]);
    return result;    
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &matrix[i][0], &matrix[i][1]);
    memset(minmatrix, -1, sizeof(minmatrix));
    printf("%d", mincal(0,n-1));
}
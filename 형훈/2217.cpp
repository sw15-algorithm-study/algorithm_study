#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum = 0, max_value;
vector<int> v;

int main(){
    scanf("%d", &n);
    int input;
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        sum += input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());                       //�������� ����
    for(int i = 0; i < v.size(); i++)
        max_value = max(max_value, v[i] * n--);     //������ n�� ������� �� ��� �ִ� �ִ��߷� ���
    printf("%d", max_value);
}
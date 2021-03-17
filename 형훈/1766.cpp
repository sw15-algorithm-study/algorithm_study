#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n, m;
int arr[32001];
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int>> pq;      //minheap

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int input1, input2;
        scanf("%d %d", &input1, &input2);
        arr[input2]++;                  
        v[input1].push_back(input2);
    }
    for(int i = 1; i <= n; i++)
        if(arr[i] == 0)                                 //선행문제가 없다면
            pq.push(i);
    while(!pq.empty()){
        int output = pq.top();
        pq.pop();
        printf("%d ",output);
        for(int i = 0; i < v[output].size(); i++)       
            if(--arr[v[output][i]] == 0)                //선행문제가 없는
                pq.push(v[output][i]);                  //후행문제들을 pq에 push
    }
}
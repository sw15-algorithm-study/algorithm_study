#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

vector<int>works[1001];
int worker_to_work[1001];
int work_to_worker[1001];
bool visit[1001];

bool func(int worker){
    for(int i = 0; i < works[worker].size(); i++){
        int worknum = works[worker][i];
        if(visit[worknum])
            continue;
        visit[worknum] = true;
        if(work_to_worker[worknum] == -1 || func(work_to_worker[worknum])){
            worker_to_work[worker] = worknum;
            work_to_worker[worknum] = worker;
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        int cnt;
        scanf("%d", &cnt);
        for(int j = 0; j < cnt; j++){
            int work;
            scanf("%d", &work);
            works[i].push_back(work-1);
        }
    }
    memset(worker_to_work, -1, sizeof(worker_to_work));
    memset(work_to_worker, -1, sizeof(work_to_worker));
    int result = 0;
    for(int worker = 0; worker < n; worker++){
        if(worker_to_work[worker] == -1){
            memset(visit, false, sizeof(visit));
            if(func(worker))
                result++;
        }
    }
    printf("%d", result);
}
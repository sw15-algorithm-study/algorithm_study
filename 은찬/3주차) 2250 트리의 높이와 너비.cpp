#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int current_y = 1;
int max_level = 0;
bool tree[10001][10001];

struct Node{
    int num;
    Node * left;
    Node * right;
};

//중위 탐색(left->current->right 순으로 탐색)
void dfs(Node * node, int level){
    if(node->left->num != 0){
        dfs(node->left, level + 1);
    }

    //bool형 2차원 배열을 통해 y열에 겹치지 않게 그래프를 표시
    tree[level][current_y++] = true;

    if(node->right->num != 0){
        dfs(node->right, level + 1);
    }
}

//그래프의 최대 높이(level)를 구하기 위한 bfs
void bfs(Node * root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i < size; i++){
            Node * node = q.front();
            q.pop();

            if(node->left->num != 0){
                q.push(node->left);
            }
            if(node->right->num != 0){
                q.push(node->right);
            }
        }
        max_level++;
    }
}

int main(void){
    int N;
    Node * root;
    int answer[2] = {1, 1};

    cin >> N;

    //node를 연결하기 위해 사용
    vector<Node> node(N + 1);
    //루트를 찾기위해 숫자를 카운트.
    //num을 입력받으면서 카운팅을 시작.
    //카운팅 결과 1이 나온 num이 루트 노드의 시작 숫자.
    vector<int> count(N + 1, 0);
    //node[0] -> 자식 노드가 없을 때 0으로 처리
    node[0].num = 0;
    
    for(int i = 1; i <= N; i++){
        int num, left, right;
        cin >> num >> left >> right;
        
        node[num].num = num;
        count[num]++;
        
        //left 또는 right가 -1인 경우 node[0]으로 연결.
        //그 외의 경우 node[num]을 연결시켜 준다.
        if(left != -1){
            node[num].left = &node[left];
            count[left]++;
        }
        else{
            node[num].left = &node[0];
        }
        
        if(right != -1){
            node[num].right = &node[right];
            count[right]++;
        }
        else{
            node[num].right = &node[0];
        }
    }

    //count 배열을 통해 루트 노드 찾기
	for(int i = 1; i <= N; i++){
		if(count[i] == 1){
			root = &node[i];
			break;
		}
	}

    //넓이를 구하기 위해 dfs 활용
    dfs(root, 1);
    //높이를 구하기 위해 bfs 활용
    bfs(root);

    //각 레벨마다 왼쪽과 오른쪽을 탐색.
    //왼쪽, 오른쪽 탐색 시 가장 처음에 만난 노드의 위치를 저장하고 답을 구한다.
    for(int i = 1; i <= max_level; i++){
        int tmp = 0;
        int left = 0, right = N;

        for(int j = 1; j <= N; j++){
            if(tree[i][j]){
                left = j;
                break;
            }
        }

        for(int j = N; right >= 1; j--){
            if(tree[i][j]){
                right = j;
                break;
            }
        }
        tmp = right - left + 1;
        if(answer[1] < tmp){
            answer[0] = i;
            answer[1] = tmp;
        }
    }
    
    cout << answer[0] << " " << answer[1];
    return 0;
}
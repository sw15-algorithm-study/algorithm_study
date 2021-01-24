// 너무 복잡하게 생각 하다 많이 틀린 문제.
// 입력을 받고 루트부터 비교해 가며 이진트리를 완성한다. (-> 시간적으로는 효율성x 일듯)
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int key;
    int root;
    int left;
    int right;
};

vector<node> nodeList;

void backSearch(int index);

int main()
{
    int tmp;
    int root;
    vector<int> inputList;

    while(cin >> tmp)
    {
        inputList.push_back(tmp);
    }

    for(int i = 0; i < inputList.size(); i++)
    {
        node tmpNode = {-1, -1, -1, -1};
        nodeList.push_back(tmpNode);
    }

    root = 0;
    nodeList[0].key = inputList[0];

    int nowKey;
    int nodePos = 0;
    for(int i = 1; i < inputList.size(); i++)
    {
        nodePos = 0;
        nowKey = inputList[i];
        nodeList[i].key = nowKey;

        while(true)
        {
            if(nodeList[nodePos].key > nowKey)
            {
                if(nodeList[nodePos].left == -1)
                {
                    nodeList[nodePos].left = i;
                    nodeList[i].root = nodePos;
                    break;
                }
                else
                {
                    nodePos = nodeList[nodePos].left;
                }
            }
            else
            {
                if(nodeList[nodePos].right == -1)
                {
                    nodeList[nodePos].right = i;
                    nodeList[i].root = nodePos;
                    break;
                }
                else
                {
                    nodePos = nodeList[nodePos].right;
                }
            }    
        }
        
    }

    backSearch(0);

}

void backSearch(int index)
{
    int left = nodeList[index].left;
    int right = nodeList[index].right;

    if(left != -1)
    {
        backSearch(left);
    }
    if(right != -1)
    {
        backSearch(right);
    }
    cout << nodeList[index].key << "\n";
}
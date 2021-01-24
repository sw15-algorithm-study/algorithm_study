// 간단한 문제이니 주석 생략.
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    char name;
    int root;
    int left;
    int right;
};

vector<node> nodeList;

void frontSearch(int index);
void middleSearch(int index);
void backSearch(int index);

int main()
{
    int nodeNum;
    cin >> nodeNum;


    for(int i = 0; i < nodeNum; i++)
    {
        node tmpNode = {' ', -1, -1, -1};
        nodeList.push_back(tmpNode);
    }

    nodeList[0].name = 'A';

    for(int i = 0; i < nodeNum; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;

        if(left != '.')
        {
            nodeList[left-'A'].name = left;
            nodeList[left-'A'].root = parent - 'A';
            nodeList[parent-'A'].left = left - 'A';
        }
        if(right != '.')
        {
            nodeList[right-'A'].name = right;
            nodeList[right-'A'].root = parent - 'A';
            nodeList[parent-'A'].right = right - 'A';
        }
    }

    frontSearch(0);
    cout << "\n";
    middleSearch(0);
    cout << "\n";
    backSearch(0);
}

void frontSearch(int index)
{
    int left, right;
    cout << nodeList[index].name;
    left = nodeList[index].left;
    right = nodeList[index].right;

    if(left != -1)
    {
        frontSearch(left);
    }
    if(right != -1)
    {
        frontSearch(right);
    }
}

void middleSearch(int index)
{
    int left, right;
    left = nodeList[index].left;
    right = nodeList[index].right;

    if(left != -1)
    {
        middleSearch(left);
    }
    cout << nodeList[index].name;
    if(right != -1)
    {
        middleSearch(right);
    }
}

void backSearch(int index)
{
    int left, right;
    left = nodeList[index].left;
    right = nodeList[index].right;

   if(left != -1)
    {
        backSearch(left);
    }
    if(right != -1)
    {
        backSearch(right);
    }
    cout << nodeList[index].name;
}
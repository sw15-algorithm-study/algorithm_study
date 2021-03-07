#include <iostream>
#include <algorithm>
using namespace std;

struct info {
	int sender;
	int reciever;
	int cnt;

	
};

info arr[10000];
int capacity[10001] = { 0 };
int n = 0, c = 0, m = 0;
int result = 0;

bool cmp(info a, info b) {
	if (a.reciever < b.reciever)return true;
	else if (a.reciever == b.reciever)
		if (a.sender < b.sender)
			return true;
		
	return false;
}

int main() {
	scanf("%d %d", &n, &c);
    scanf("%d", &m);

	for (int i = 0; i < m; i++)
		cin >> arr[i].sender >> arr[i].reciever >> arr[i].cnt;

	sort(arr, arr + m,cmp); //�������� ���� 1.������ 2.����� 
	for (int i = 0; i < m; i++) { 
		int maxcnt = 0;
		for (int j = arr[i].sender; j < arr[i].reciever; j++)  //�����°����� �޴°�����
			maxcnt = max(capacity[j], maxcnt); //capacity�� �ִ밪�� �����մϴ�. �ڽ��� �󸶳� ���� �� �ִ� Ȯ���ϱ� ����
		int val = min(arr[i].cnt, c - maxcnt);
		result += val;
		for (int j = arr[i].sender; j < arr[i].reciever; j++)
			capacity[j] += val; // �̵��Ǹ鼭 �ش� ������ŭ �Ҵ����־�� �ڽ��� �� �Ǹ�����
	}
    printf("%d", result);
}
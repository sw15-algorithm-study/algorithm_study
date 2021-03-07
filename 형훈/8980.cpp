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

	sort(arr, arr + m,cmp); //오름차순 정렬 1.도착지 2.출발지 
	for (int i = 0; i < m; i++) { 
		int maxcnt = 0;
		for (int j = arr[i].sender; j < arr[i].reciever; j++)  //보내는곳부터 받는곳까지
			maxcnt = max(capacity[j], maxcnt); //capacity의 최대값을 저장합니다. 박스를 얼마나 넣을 수 있는 확인하기 위해
		int val = min(arr[i].cnt, c - maxcnt);
		result += val;
		for (int j = arr[i].sender; j < arr[i].reciever; j++)
			capacity[j] += val; // 이동되면서 해당 공간만큼 할당해주어야 박스가 못 실리겠죠
	}
    printf("%d", result);
}
#include <iostream>
#include <algorithm>
#include <vector>;
using namespace std;
struct time
{
	int start;
	int end;
};
bool compare(time t1, time t2);
int main() {
	int n, cnt = 0, tmp = 0;	//cnt는 회의 횟수저장 tmp는 임시변수
	bool check = false;
	scanf("%d", &n);
	vector<time> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].start, &v[i].end);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].start >= tmp) {
			tmp = v[i].end;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}

bool compare(time t1, time t2) {	//compare정의 끝나는시간기준 정렬, 같다면 시작시간 작은순
	if (t1.end == t2.end)
		return t1.start < t2.start;
	else
		return t1.end < t2.end;
}
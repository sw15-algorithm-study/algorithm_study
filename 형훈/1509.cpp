#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

string Palindrom = " ";
bool DP[2501][2501];
int Result[2501];

int main() {
	string temp;
	cin >> temp;
	Palindrom += temp;

	for (int i = 1; i < Palindrom.size(); i++)                              //길이가 1일떄                       
		DP[i][i] = true;

	for (int i = 1; i < Palindrom.size(); i++)                              //길이가 2일때
		if (Palindrom[i] == Palindrom[i + 1])
			DP[i][i + 1] = true;
	
	for (int i = 2; i < Palindrom.size(); i++)                              //길이가 3이상일 때
		for (int j = 1; j < Palindrom.size() - i; j++)
			if (Palindrom[j] == Palindrom[j + i] && DP[j + 1][i + j - 1])
				DP[j][j + i] = true;
	

	Result[0] = 0;
	for (int i = 1; i < Palindrom.size(); i++) {
		Result[i] = 10000000;
		for (int j = 1; j <= i; j++)
			if (DP[j][i])
				Result[i] = min(Result[i], Result[j - 1] + 1);
	}
	cout << Result[Palindrom.size() - 1];
	return 0;
}
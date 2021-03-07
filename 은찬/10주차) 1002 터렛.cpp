#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	double x1, y1, x2, y2, r1, r2, i;
	int T;
	cin >> T;
	for (int j = 0; j < T; j++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		i = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			if ((r1 + r2) > i && abs(r1 - r2) < i)
				cout << 2 << endl;
			else if (i == r1 + r2 || i == abs(r1-r2))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}
#include <stdio.h>

int main(void)
{
	char num[16];
	int i = 0;
	int sum = 0;
	scanf("%s", &num);

	while (num[i] != '\0')
	{
		if (num[i] == 'A' || num[i] == 'B' || num[i] == 'C')
			sum += 3;
		else if (num[i] == 'D' || num[i] == 'E' || num[i] == 'F')
			sum += 4;
		else if (num[i] == 'G' || num[i] == 'H' || num[i] == 'I')
			sum += 5;
		else if (num[i] == 'J' || num[i] == 'K' || num[i] == 'L')
			sum += 6;
		else if (num[i] == 'M' || num[i] == 'N' || num[i] == 'O')
			sum += 7;
		else if (num[i] == 'P' || num[i] == 'Q' || num[i] == 'R' || num[i] == 'S')
			sum += 8;
		else if (num[i] == 'T' || num[i] == 'U' || num[i] == 'V')
			sum += 9;
		else if (num[i] == 'W' || num[i] == 'X' || num[i] == 'Y' || num[i] == 'Z')
			sum += 10;
		i++;
	}
	printf("%d", sum);
	return 0;
}
#include <stdio.h>

int main(void)
{
	char c[101];
	int i = 0;
	int sum = 0;
	scanf("%s", &c);

	while (c[i] != '\0')
	{
		if (c[i] == 'c')
		{
			if (c[i + 1] == '=' || c[i + 1] == '-')
				i += 1;
		}
		else if (c[i] == 'd')
		{
			if (c[i + 1] == 'z' && c[i + 2] == '=')
				i += 2;
			else if (c[i + 1] == '-')
				i += 1;
		}
		else if (c[i] == 'l' && c[i + 1] == 'j')
			i += 1;
		else if (c[i] == 'n' && c[i + 1] == 'j')
			i += 1;
		else if (c[i] == 's' && c[i + 1] == '=')
			i += 1;
		else if (c[i] == 'z' && c[i + 1] == '=')
			i += 1;
		sum++;
		i++;
	}
	printf("%d", sum);
	return 0;
}
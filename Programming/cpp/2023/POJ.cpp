#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[31];
int hash()
{
	int sum = 0;
	for (int j = 0, k = 0; k < 7 && j < strlen(str); j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			sum = sum * 10 + str[j] - '0';
			k++;
		}
		else
		{
			switch (str[j])
			{
			case 'A':
			case 'B':
			case 'C':
				sum = sum * 10 + 2;
				k++;
				break;
			case 'D':
			case 'E':
			case 'F':
				sum = sum * 10 + 3;
				k++;
				break;
			case 'G':
			case 'H':
			case 'I':
				sum = sum * 10 + 4;
				k++;
				break;
			case 'J':
			case 'K':
			case 'L':
				sum = sum * 10 + 5;
				k++;
				break;
			case 'M':
			case 'N':
			case 'O':
				sum = sum * 10 + 6;
				k++;
				break;
			case 'P':
			case 'R':
			case 'S':
				sum = sum * 10 + 7;
				k++;
				break;
			case 'T':
			case 'U':
			case 'V':
				sum = sum * 10 + 8;
				k++;
				break;
			case 'W':
			case 'X':
			case 'Y':
				sum = sum * 10 + 9;
				k++;
				break;
			default:
				break;
			}
		}
	}
	return sum;
}
void POJ1002()
{
	int n;
	scanf("%d", &n);
	int ans[n];
	getchar(); // ����n֮����һ���س�
	for (int i = 0; i < n; i++)
	{
		gets(str);
		ans[i] = hash();
	}
	sort(ans, ans + n);
	// for (int i=0;i<n;i++)printf("%d,",ans[i]);
	printf("\n");
	int i = 0;
	int num = 1;
	bool p = false;
	while (i < n)
	{
		num = 1;
		while (i < n - 1 && ans[i] == ans[i + 1])
		{
			i++;
			num++;
		} // 123-4565
		if (num > 1)
		{
			p = true;
			printf("%03d-%04d %d\n", ans[i] / 10000, ans[i] % 10000, num);
		}
		i++;
	}
	if (p == false)
		printf("No duplicates.\n");
}
int main()
{
	POJ1002();
	return 0;
}

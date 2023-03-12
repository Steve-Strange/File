#include <stdio.h>

int main()
{
	long long a[51][2];
	int i;
	a[0][0] = 1, a[1][0] = 1, a[2][0] = 2;
	a[0][1] = 0, a[1][1] = 0, a[2][1] = 0;
	for (i = 3; i <= 50; i ++)
	{
		a[i][0] = a[i-1][0] + a[i-2][0] + a[i-3][0] - a[i-3][1];
		a[i][1] = a[i-3][0] - a[i-3][1];
	}
	int n;
	while (~scanf("%d", &n))
		printf("%lld\n", a[n][0]);
	return 0;
}

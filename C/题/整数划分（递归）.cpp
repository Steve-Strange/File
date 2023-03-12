#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

long long x(int n,int m)
{
	if(n==1||m==1) return 1;
	if(m==n) return 1+x(n,n-1);
	if(m>n) return x(n,n);
	if(m<n) return x(n-m,m)+x(n,m-1);
}

int main()
{
	int t;
	scanf("%d",&t);	
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);	
		printf("%lld\n",x(n,n));
	}
	return 0;
}

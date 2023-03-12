#include<stdio.h>
int main()
{
	long long n,x0,y0,p,q,r,x,y,i;
	scanf("%lld\n",&n);
	scanf("(%lld,%lld)\n",&x0,&y0);
	if(n!=0)	scanf("%lld%lld%lld\n",&p,&q,&r);
	if(n==0) {
		scanf("%lld%lld%lld",&p,&q,&r);
		goto here;
	}
	for (i=0;i<n-1;i++)
	{
	scanf("(%lld,%lld)\n",&x,&y);
		x0-=x;
		y0-=y;
	}
		scanf("(%lld,%lld)",&x,&y);
		x0-=x;
		y0-=y;
	here:
	if(((x0-p)*(x0-p)+(y0-q)*(y0-q))>r*r)
	{
		printf("(%lld,%lld)",x0,y0);
	}
	else printf("No way!");
	return 0;
 } 

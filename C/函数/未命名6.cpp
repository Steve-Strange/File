#include<stdio.h>
#include<string.h>
int num[3][500],a[1500],b[500],np,len1,len2,st1=0;
int ans[401];
int fei()
{
	int cur=2,cnt=3,i,j,a=0,b=1;
	while(cnt<=1260)
	{
		num[cur][0]=0;
		for(i=1,j=0;i<=num[a][0]||i<=num[b][0]||j;i++)
		{
			num[cur][++num[cur][0]]=(num[a][i]+num[b][i]+j)%10;
			j=(num[a][i]+num[b][i]+j)/10;
		}
		cur=(cur+1)%3;
		a=(a+1)%3;
		b=(b+1)%3;
		cnt++;
	}
	return cur;
}
void add(int f)
{
	for(int i=0;i<len2;i++)	a[len1-len2+i]+=f*b[i];
	for(int i=len1-1;i>st1;i--)
	{
		if(a[i]>9)
		{
			a[i-1]++;
			a[i]=a[i]-10;
		}
		else if(a[i]<0)
		{
			a[i-1]--;
			a[i]=10+a[i];
		}
	}
}
void f()
{
	np=(np+1)%3;
	len1=num[np][0]+1;
	for(int i=num[np][0];i>=1;i--)	a[num[np][0]-i]=num[np][i];
	np=(np+1)%3;
	len2=num[np][0];
	for(int i=num[np][0];i>=1;i--)	b[num[np][0]-i]=num[np][i];
	for(int i=1,k,f;i<=400;i++)
	{
		for(k=1,f=1;k<10&&f;k++)
		{
			//printf("trying: %d\n",k);
			if(len1-st1<len2)	break;
			add(-1);
			for(int j=st1;j<len1;j++)
			{
				if(a[j]<0)
				{
					f=0;
					break;
				}
				else if(a[j]>0)	break;
			}
		}
		if(len1-st1>=len2&&(!f))	add(1);
		ans[i]=k-2+f;
		len1++;
		for(;!a[st1];st1++);
	}
}

int main()
{
	int k;
	memset(ans,0,sizeof(ans));
	memset(num,0,sizeof(num));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	num[0][0]=num[1][0]=num[0][1]=num[1][1]=1;
	np=fei();
	f();
	while(scanf("%d",&k)!=EOF)	printf("%d\n",ans[k]);
}

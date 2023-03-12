#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char x[1005]={0};
	int op[1005]={0};
	int cnt_num=0;
	int cnt_op=0;
	int dig=0;
	int num[1005]={0};
	int cnt_ans=0;
	int ans[1005]={0};
	gets(x);
	int n=strlen(x);
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(x[i]!=' ')
			x[j++]=x[i];
	}
	x[j]='\0';
	n=strlen(x);
		
	
	for(int i=n-1;i>=0;i--)
	{
		if(x[i]>='0'&&x[i]<='9')
		{
			if(dig==0) cnt_num++;
			num[cnt_num]+=(x[i]-'0')*pow(10,(dig++));
		}
		else
		{
			cnt_op++;
			if(x[i]=='+') op[cnt_op]=1;
			if(x[i]=='-') op[cnt_op]=-1;
			if(x[i]=='*') op[cnt_op]=2;
			if(x[i]=='/') op[cnt_op]=3;
			dig=0;
		}
		
	}
	
	if(cnt_op==cnt_num)	op[++cnt_op]=1;
	
//	for(int i=cnt_op;i>0;i--)
//	{
//		printf("%d ",op[i]);
//	}
//	putchar(10);
//	for(int i=cnt_num;i>0;i--)
//	{
//		printf("%d ",num[i]);
//	}	
//	
	for(int i=cnt_op;i>0;i--)
	{
		if(op[i]==2)
		{
			num[i-1]*=num[i]; 
			num[i]=0;
		}
		
		if(op[i]==3)
		{
			num[i]/=num[i-1];
			num[i-1]=num[i];
			num[i]=0;
		}
		
		if(op[i]==1) ans[cnt_ans]=1,cnt_ans++;
		if(op[i]==-1) ans[cnt_ans]=-1,cnt_ans++;
	}
	int output=0;
	
//	for(int i=cnt_num;i>0;i--)
//	{
//		printf("%d ",num[i]);
//	}	
//	putchar(10);
//	
//	for(int i=0;i<cnt_ans;i++) printf("%d ",ans[i]);
//		
	for(int i=1;i<=cnt_num;i++)
	{
		if(num[i]!=0) output+=num[i]*ans[--cnt_ans];
	}
	
	printf("%d",output);
	return 0;
}



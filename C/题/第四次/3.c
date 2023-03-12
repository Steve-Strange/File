#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char stack[300]={0};
	char ans[300][20]={0};
	char formula[300]={0};
	double pile[300]={0};
	gets(formula);
	int len=strlen(formula);
	int t=0;
	int p=0;
	for(int i=0;i<len;i++)
	{
		if(formula[i]==' ') continue;
		else if(formula[i]=='=')
		{
			for(int j=p-1;j>=0;j--)
			{
				ans[t++][0]=stack[j];
			}
			break;
		}
		else if(formula[i]>='0'&&formula[i]<='9')
		{
			int num=0;
			while(formula[i+num]>='0'&&formula[i+num]<='9')
			{
				ans[t][num]=formula[i+num];
				num++;
			}
			t++;
			i+=num-1;
		}
		else
		{
			if(formula[i]!='('&&formula[i]!=')')
			{
				if(p==0) stack[p++]=formula[i];
				else
				{
					while(p>0&&(((formula[i]=='*'||formula[i]=='/'||formula[i]=='%')&&(stack[p-1]=='*'||stack[p-1]=='/'||stack[p-1]=='%'))||((formula[i]=='-'||formula[i]=='+')&&(stack[p-1]=='-'||stack[p-1]=='+'))||((formula[i]=='-'||formula[i]=='+')&&(stack[p-1]=='*'||stack[p-1]=='/'||stack[p-1]=='%'))))
					{
						ans[t++][0]=stack[p-1];
						p--;
					}
					stack[p++]=formula[i];
				}
			}
			else
			{
				if(formula[i]=='(')
				{
					stack[p++]=formula[i];
				}
				else
				{
					while(stack[--p]!='(')
					{
						ans[t++][0]=stack[p];
					}
				}
			}
		}
	}

	// for(int i=0;i<t;i++)
	// {
	// 	printf("%s ",ans[i]);
	// }
	
	
	int k=0;
	for(int i=0;i<t;i++)
	{
		double temp;
		if(isdigit(ans[i][0]))
		{
			pile[k++]=atoi(ans[i]);
		}
		else
		{
			if(ans[i][0]=='+') temp=pile[k-2]+pile[k-1];
			if(ans[i][0]=='-') temp=pile[k-2]-pile[k-1];
			if(ans[i][0]=='*') temp=pile[k-2]*pile[k-1];
			if(ans[i][0]=='/') temp=pile[k-2]/pile[k-1];
			k-=2;
			pile[k++]=temp;
		}
	}
	
	printf("%.2lf",pile[0]);
}

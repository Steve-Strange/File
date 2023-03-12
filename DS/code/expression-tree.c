	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<ctype.h>

	typedef struct node{
		char data[10];
		struct node *ltree, *rtree;
	}node;

	int level[1000];
	int cnt_level;

	double answer[300]={0};
	int answertop=0;
	void postorder(node* t)
	{
		if(t!=NULL)
		{
			cnt_level++;
			postorder(t->ltree);
			postorder(t->rtree);
			cnt_level--;
			if(t->data[0]=='+'||t->data[0]=='-'||t->data[0]=='*'||t->data[0]=='/')
			{
				level[cnt_level]++;
				double b=answer[--answertop];
				double a=answer[--answertop];
				if(t->data[0]=='+') answer[answertop++]=a+b;
				if(t->data[0]=='-') answer[answertop++]=a-b;
				if(t->data[0]=='*') answer[answertop++]=a*b;
				if(t->data[0]=='/') answer[answertop++]=a/b;
			}
			else
			{
				int num=atoi(t->data);
				answer[answertop++]=(double)num;
			}  
		}
	}

	int main()
	{
		char stack[300]={0};
		char ans[300][20]={0};
		char formula[300]={0};
		double pile[300]={0};
		node *tree[300];
		int top=0;
		gets(formula);
		int len=strlen(formula);
		int t=0;  //运算符和操作数 的个数
		int p=0;
		for(int i=0;i<len;i++)
		{
			if(formula[i]==' ') continue;

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
		for(int j=p-1;j>=0;j--)
		{
			ans[t++][0]=stack[j];
		}
		//ans[][] 为后缀表达式
		// for(int i=0;i<t;i++)
		// {
		// 	printf("%s ",ans[i]);
		// }

		for(int i=0;i<t;i++)
		{
			node *k=(node*)malloc(sizeof(node));
			memset(k->data,0,sizeof(k->data));
			k->ltree=k->rtree=NULL;
			if(ans[i][0]>='0'&&ans[i][0]<='9')
			{
				strcpy(k->data,ans[i]);
				tree[top++]=k;
			}
			else
			{
				strcpy(k->data,ans[i]);
				k->rtree=tree[--top];
				k->ltree=tree[--top];
				tree[top++]=k;
			}
		}
		// if(tree[0]->data) printf("%s",tree[0]->data);
		// if(tree[0]->ltree->data) printf(" %s",tree[0]->ltree->data);
		// if(tree[0]->rtree->data) printf(" %s",tree[0]->rtree->data);
		// printf("\n");

		postorder(tree[0]);
		if(answer[0]>0) printf("%.2lf",answer[0]);
	}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char num;
	struct node* left;
	struct node* right;
}node;

int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}


int main()
{
	
	FILE *in,*out;
	in=fopen("in.txt","r");
	out=fopen("in_crpyt.txt","w");
	
	node *chain,*ptr,*head;
	chain=(node*)malloc(sizeof(node));
	head=chain;
	chain->num=1;
	for(int i=1;i<95;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->left=chain;
		ptr->num=i+1;
		chain->right=ptr;
		chain=ptr;
	}
	head->left=ptr;
	ptr->right=head;
	ptr=head;
	
	char x[35]={0};
	fgets(x,35,stdin);
	int book[130]={0};
	int len=strlen(x);
	for(int i=0;i<len;i++)
	{
		if(x[i]>=32&&x[i]<=126)
		if(book[x[i]]==0)
		{
			ptr->num=x[i];
			ptr=ptr->right;
			book[x[i]]=1;
		}
	}
	
	for(int i=32;i<=126;i++)
	{
		if(book[i]==0)
		{
			ptr->num=i;
			ptr=ptr->right;
			book[i]=1;
		}
	}
	//
	//	for(int i=32;i<=126;i++)
	//	{
	//			ptr=ptr->left;
	//		printf("%c",ptr->num);
	//
	//	}
	char code[96]={0};
	for(int i=0;i<95;i++)
	{
		code[i]=ptr->num;
		ptr->left->right=ptr->right;
		ptr->right->left=ptr->left;
		for(int j=ptr->num;j>0;j--)
		{
			ptr=ptr->right;
		}
	}
	//	for(int i=0;i<95;i++)
	//	{
	//		printf("%c ",code[i]);
	//	}
	
	code[95]=code[0];
	
	int convert[95][2];
	for(int i=0;i<95;i++)
	{
		convert[i][0]=code[i];
		convert[i][1]=code[i+1];
	}
	
	qsort(convert,95,8,cmp);
	
	char c;
	while(c=getc(in),c!=EOF)
	{
		if(c>=32&&c<=126)
		{
			c=convert[c-32][1];
		}
		fputc(c,out);
	}
	fclose(in);
	fclose(out);
	return 0;
}





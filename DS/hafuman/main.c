//文件压缩-Huffman实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {			//Huffman树结构
	char c;		
	int weight;		//树节点权重，叶节点为字符和它的出现次数
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};		//存放每个字符的出现次数，如Ccount[i]表示ASCII值为i的字符出现次数 
struct tnode *Root=NULL; 	//Huffman树的根节点
char HCode[128][MAXSIZE]={{0}}; //字符的Huffman编码，如HCode['a']为字符a的Huffman编码（字符串形式） 
int Step=0;			//实验步骤 
FILE *Src, *Obj;
	
void statCount();		//步骤1：统计文件中字符频率
void createHTree();		//步骤2：创建一个Huffman树，根节点为Root 
void makeHCode();		//步骤3：根据Huffman树生成Huffman编码
void atoHZIP(); 		//步骤4：根据Huffman编码将指定ASCII码文本文件转换成Huffman码文件

void print1();			//输出步骤1的结果
void print2(struct tnode *p);	//输出步骤2的结果 
void print3();			//输出步骤3的结果
void print4();			//输出步骤4的结果

int main()
{
        if((Src=fopen("input.txt","r"))==NULL) {
	        fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1; 
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);		//输入当前实验步骤 
	
	statCount();			//实验步骤1：统计文件中字符出现次数（频率）
	(Step==1)?print1():1;   	//输出实验步骤1结果	
	createHTree();			//实验步骤2：依据字符频率生成相应的Huffman树
	(Step==2)?print2(Root):2; 	//输出实验步骤2结果	
	makeHCode();		//实验步骤3：依据Root为树的根的Huffman树生成相应Huffman编码
	(Step==3)?print3():3;   	//输出实验步骤3结果
	(Step>=4)?atoHZIP(),print4():4;//实验步骤4：据Huffman编码生成压缩文件，并输出实验步骤4结果	

	fclose(Src);
	fclose(Obj);
        return 0;
} 

//【实验步骤1】开始 
void statCount()
{
char s;
    int b;
    while((s=fgetc(Src))!=EOF)
    {
        if(Ccount[s]!=0)
        {
            b=Ccount[s];
            b++;
            Ccount[s]=b;
        }
        else 
       {
       	 Ccount[s]=1;
	   }
    }
    Ccount[0]=1;

	
}




//【实验步骤1】结束

//【实验步骤2】开始
void createHTree()
{
char i;
    int j,k;
    int num=0,top=-1;
    int start=0;
    struct tnode *p; 
    struct tnode *a[128];
    for(i=0;i<127;i++)
    {
        if(Ccount[i]!=0)
        {
            p=(struct tnode*)malloc(sizeof(struct tnode));
            p->c=i; p->weight=Ccount[i];//字符及其出现次数
            p->left=p->right=NULL;
            a[num++]=p;
        }
    }
    for(j=1;j<num;j++)
        for(k=0;k<j;k++)
        {
            if(a[k]->weight>a[k+1]->weight)
            {
                  p=a[k];
                  a[k]=a[k+1];
                  a[k+1]=p;
            }
        }
        top=num-1;
	while(start<top-1)
	{
		p=(struct tnode *)malloc(sizeof(struct tnode));
		p->weight=a[start]->weight+a[start+1]->weight;
		p->left=a[start];
		p->right=a[start+1];
		start+=2; 
		a[++top]=p;
		num--;
		for(j=0;j<top;j++)
			for(k=j-1;k>=start;k--)
			{
				if(a[k+1]->weight<a[k]->weight)
				{
				  p=a[k];
                  a[k]=a[k+1];
                  a[k+1]=p;
				}
			}
	}
    p=(struct tnode *)malloc(sizeof(struct tnode));
	p->weight=a[start]->weight+a[start+1]->weight;
	p->left=a[start];p->right=a[start+1];Root=p;

	
}


//【实验步骤2】结束

//【实验步骤3】开始
char Str[19];
void ProHcode(struct tnode *p,char a,int b)
{
	int i;
	if(p!=Root)
	b++;
	if(b!=0)
	{
		Str[b-1]=a;
	}
	if(p->left==NULL&&p->right==NULL)
	{
		Str[b]='\0';
		for(i=0;i<=b;i++)
		HCode[p->c][i]=Str[i];
	}
	else 
	{
		ProHcode(p->left,'0',b);
		ProHcode(p->right,'1',b);
	}
} 
void makeHCode()
{
	ProHcode(Root,0,0);
} 




//【实验步骤3】结束

//【实验步骤4】开始
void ab(int x,unsigned char hc,int c)
{
	char a[2];
	if(c==0&&x!=0)
	{
		x=(x+1)%8-1;
		for(;x<8;x++)
		hc=(hc<<1);
		printf("%x",hc);
		fputc(hc,Obj);
	}
}
void atoHZIP()
{
	unsigned char hc,c,*p;
	int i=1;
	fseek(Src,0,SEEK_SET);
	while(c=fgetc(Src))
	{
		if(c>=129)
		{
			for(p=HCode[0];*p!='\0';i++,p++)
		{
			hc=(hc<<1)|(*p-'0');
			if(i%8==0)
			{
				fputc(hc,Obj);
				printf("%x",hc);
				i=0;
			}
		}
		break;
		}
		for(p=HCode[c];*p!='\0';i++,p++)
		{
			hc=(hc<<1)|(*p-'0');
			if(i%8==0)
			{
				fputc(hc,Obj);
				printf("%x",hc);
				i=0;
			}
		}
			
	}
	ab(i,hc,c);
}



//【实验步骤4】结束

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\n原文件大小：%ldB\n",in_size);
	printf("压缩后文件大小：%ldB\n",out_size);
	printf("压缩率：%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}


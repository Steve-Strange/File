#include<stdio.h>
#include<string.h>
struct kuohao
{
	char type;
	int line;
}stk[300];
int p=0,l=1,t=0;
char output[300]={0},c;
int main()
{
	memset(stk,0,sizeof(stk));
	FILE *in=fopen("example.c","r+");////
	while(c=fgetc(in),c!=EOF)
	{
		//printf("%d \'%c\'\n",l,c);
		//system("pause");
		switch(c)
		{
			case '\"':
				for(c=fgetc(in);c!='\"'&&c!=10&&c!=EOF;c=fgetc(in));
				if(c==10)	l++;
				break;
			case '\'':
				for(c=fgetc(in);c!='\''&&c!=10&&c!=EOF;c=fgetc(in));
				if(c==10)	l++;
				break;
			case '/':
				c=fgetc(in);
				if(c=='/')
				{
					for(c=fgetc(in);c!=10&&c!=EOF;c=fgetc(in));
					l++;
				}
				else if(c=='*')	
					for(c=fgetc(in);c!=EOF;c=fgetc(in))
					{
						if(c==10)	l++;
						else if(c=='/')
						{
							fseek(in,-2,SEEK_CUR);
							if(fgetc(in)=='*')
							{
								fseek(in,1,SEEK_CUR);
								break;
							}
							else	fseek(in,1,SEEK_CUR);
						}
					}	
				else	fseek(in,-1,SEEK_CUR);
				break;
			case '{':
				if(p>0&&stk[p-1].type=='(')
				{
					printf("without maching \'(\' at line %d",stk[p-1].line);
					return 0;
				}
				else
				{
					stk[p].type='{';
					stk[p++].line=l;
					output[t++]='{';
				}
				break;
			case '}':
				if(p==0||stk[p-1].type!='{')
				{
					printf("without maching \'}\' at line %d",l);
					return 0;
				}
				else
				{
					output[t++]='}';
					p--;
				}
				break;
			case '(':
				stk[p].type='(';
				stk[p++].line=l;
				output[t++]='(';
				break;
			case ')':
				if(p==0||stk[p-1].type!='(')
				{
					printf("without maching \')\' at line %d",l);
					return 0;
				}
				else
				{
					output[t++]=')';
					p--;
				}
				break;
			case 10:
				l++;
				break;
			default:break;
		}
	}
	if(p!=0)
	{
		printf("without maching \'%c\' at line %d",stk[p-1].type,stk[p-1].line);
		return 0;
	}
	fclose(in);
	printf("%s",output);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define tolower(c) (c>='A'&&c<='Z'?'a'-'A'+c:c)

int main()
{
	FILE *in,*out;
	in=fopen("filein.txt","r");
	out=fopen("fileout.txt","w");

	char find[105]={0};
	char replace[105]={0};
	scanf("%s",find);
	scanf("%s",replace);
	
	char str[1005]={0};
	while(fgets(str,1005,in)!=NULL)
	{
		for(int i=0;str[i]!='\0';i++)
		{
			int k=0;
			for(int j=i;find[k]!='\0'&&tolower(str[j])==tolower(find[k]);j++,k++);
			if(find[k]=='\0')
			{
				i+=strlen(find)-1;
				fputs(replace,out);
			}
			else
			{
				fputc(str[i],out);
			}
		}	
	}
	
	fclose(in);
	fclose(out);
	return 0;
}


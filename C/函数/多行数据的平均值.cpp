#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *get_value(char *s, double *d)
{
	while(*s!='\0'&&isspace(*s)) s++;
	if(sscanf(s,"%lf",d)!=1)  //sscanf 从地址（数组）获取东西  用s 而不是*s 
	return NULL;
	while(*s!='\0'&&!isspace(*s)) s++;
	return s;
}

int main()
{
	int i,n;
	double d,subsum;
	char buf[BUFSIZ],*p;
	for(i=1;fgets(buf,BUFSIZ,stdin)!=NULL;i++)
	{
		subsum=0;
		for(n=0,p=buf;(p=get_value(p,&d))!=NULL;n++)
		subsum+=d;
		if(n>0) printf("%d:%d %f\n", i, n, subsum/n);
	}
	return 0;
} 

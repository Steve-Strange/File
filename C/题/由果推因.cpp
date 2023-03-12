#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	double max=0.0,sum=0.0;
	char maxbus[5];
	int j=0;
	int i=0;
	here:
	for(;i<n;i++)
	{
		char bus[5];
		double p,q;
		scanf("%s%lf%lf",bus,&p,&q);
		if(p*q<1e-5)
		{
			j++;
			if(j==4)
			{
				printf("ERROR!");
				return 0;
			}
			i++;
			goto here;
		}
		sum+=p*q;
				if(p*q>max) 
				{
					max=p*q;
					maxbus[0]=bus[0];
					maxbus[1]=bus[1];
					maxbus[2]=bus[2];
					maxbus[3]=bus[3];
				}
	}
	printf("%c%c%c%c ",maxbus[0],maxbus[1],maxbus[2],maxbus[3]);
	printf("%.4lf",max/sum);
	
	return 0;
}

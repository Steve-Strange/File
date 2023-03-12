#include<stdio.h>
int main()
{	
    int m=0,r=0,n,i,b;
    scanf("%d",&n);n*=12;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b);
        m+=300-b;
        if(m<0)
        {
            printf("-%d",i);
            return 0;
        }
        r+=m/100;
        m-=m/100*100;
        if(i%12==0)
        {
            m=m+r*120;
            r=0;
        }
    }
    printf("%d",m);
	return 0;
}

#include<stdio.h>
int main()
{
    int n,h,m;
    double a,j;
    scanf("%d",&n);
    j=h=n%12;
    if(h==11)
    {
        a=0;
        printf("%d:%d:%.7lf",0,0,a);
        return 0;
    }
    a=j/11;
    m=a*60;
    a=(a*60-m)*60;
    printf("%d:%d:%.7lf",h,m,a);
    return 0;
}
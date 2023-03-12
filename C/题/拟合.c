#include<stdio.h>
#include<math.h>
int main()
{
    int n,xa=0,ya=0,xya=0,x2a=0,si,max=0,del;
    int x[100],y[100];
    float a,b,s;	
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        xya+=x[i]*y[i];
        x2a+=x[i]*x[i];
        xa+=x[i];
        ya+=y[i];
    }
    xa/=n;
    ya/=n;
    x2a/=n;
    xya/=n;
    b=(xa*ya-xya)/(xa*xa-x2a);
    a=ya-b*xa;
    for(int i=0;i<n;i++)
    {
        si=(y[i]-(a+b*x[i]))*(y[i]-(a+b*x[i]));
        if(max<y[i])
        {
            max=y[i];
            del=i;
        }
    }
    x[del]=x[n-1];
    y[del]=y[n-1];
    for(int i=0;i<n-1;i++)
    {
        xya+=x[i]*y[i];
        x2a+=x[i]*x[i];
        xa+=x[i];
        ya+=y[i];
    }
    xa/=n-1;
    ya/=n-1;
    x2a/=n-1;
    xya/=n-1;
    b=(xa*ya-xya)/(xa*xa-x2a);
    a=ya-b*xa;
    for(int i=0;i<n-1;i++)
    {
        s+=(y[i]-(a+b*x[i]))*(y[i]-(a+b*x[i]));
    }
    printf("%.2f",s);
    return 0;
}

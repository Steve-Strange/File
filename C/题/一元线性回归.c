#include<stdio.h>
#include<math.h>
int main()
{
    double xa=0.0,ya=0.0,xya=0.0,x2a=0.0,s,min=1e15;
    int n;
    double x[110],y[110];
    double a,b,temp1,temp2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&x[i]);
    }
        for(int i=0;i<n;i++)
    {
        scanf("%lf",&y[i]);
    }
    for(int j=0;j<n;j++)
    {
        temp1=x[j];
        temp2=y[j];
        x[j]=x[n-1];
        y[j]=y[n-1];
        xya=x2a=xa=ya=s=0.0;
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
    for(int i=0;i<n-1;i++){
    s+=(y[i]-(a+b*x[i]))*(y[i]-(a+b*x[i]));
    }
    x[j]=temp1;
    y[j]=temp2;
    if(min>s) min=s;
    }
    printf("%.2lf",min);
    return 0;
}
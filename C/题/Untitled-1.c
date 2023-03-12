#include<stdio.h>
# include<math.h>
int main()
{
    int n,f;
    long long a,b,c;
    int w0,w1,w2,w3;
    int x[999],y[999];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int sum=0;
        int p;
        scanf("%lld%lld",&a,&b);
        scanf("%d%d%d%d",&w0,&w1,&w2,&w3);
        c=((a>b)?a:b);
            f=log2(c);
            for(int j=f;j>=0;j--)
            {
                x[j]=a/pow(2,j);
                if(x[j]==1) a=a-pow(2,j);
                y[j]=b/pow;(2,j);
                if(y[j]==1) b=b-pow(2,j);
            }
        for(int j=f;j>=0;j--)
        {   
            if(x[j]==0&&y[j]==0) p=w0;
            if(x[j]==0&&y[j]==1) p=w1;
            if(x[j]==1&&y[j]==0) p=w2;
            if(x[j]==1&&y[j]==1) p=w3;
            sum=sum+p*pow(2,j);
        }
        printf("%d\n",sum);
    }
    return 0;
}
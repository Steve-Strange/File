#include<stdio.h>
#include<math.h>
int main()
{
    long long n,ans=0;
    int len,sum=0;
    float ave;
    scanf("%lld",&n);
    len=log10(n)+1;
    long long num[12];
    for (int i=0;i<len;i++)
    {
        num[i]=(long long)(n/pow(10,len-i-1))%10;
        sum+=num[i];
    }
    ave=sum/10;
    for (int i=0;i<len;i++)
    {
        if(num[i]>ave)
        {
            num[i]=0;
        }
    }
    for (int i=0;i<len;i++)
    {
        ans+=num[i]*(pow(10,len-i-1));
    }
    printf("%lld",ans);
    return 0;
}
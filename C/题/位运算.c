#include<stdio.h>
int main(){

int q;
long long a,b,ans=0;
int t[2][2];
scanf("%d",&q);
while(q--)
{
    scanf("%ld%ld",&a,&b);
    for(int i=0;i<2;i++) for(int k=0;k<2;k++) scanf("%d",&t[i][k]);
    int len=0;
    for(;(a>>len)||(b>>len);len++);
    while(len--)
    {
        ans=ans<<1;
        ans+=t[a>>len][b>>len];
        a-=(a>>len)<<len; b-=(b>>len)<<len;
    }
    printf("%ld\n",ans);
    ans=0;
}
return 0;
}
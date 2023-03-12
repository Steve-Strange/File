#include<stdio.h>
#include<math.h>
int main(){
    long long N;
    scanf("%lld",&N);
    int i,j,l=0,k,m;
    int arr[99];
    i=log10(N)+1;
    for(j=1;j<=i;j++)
    {
        k=pow(10,j);
        m=pow(10,j-1);
        arr[i-1]=N%k/m;
    }
    if (i>=4)
    {
        for(j=0;j<4;j++)
        {
            printf("%d",arr[3-j]);
        }
        for(j=4;j<i;j++)
        {
            printf("%d",arr[j]);
        }
    }
    return 0;
}
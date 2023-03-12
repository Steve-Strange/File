#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    int new[500]={0};
    int people[500][2]={0};
    for (int i = 0; i < 500; i++)
    {
        people[i][0]=i+1;
    }

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&new[i]);
    }

    int num=0;
    int top=0;
    int pile[500]={0};

    int op=3;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        top+=new[i];
        if(top>=21&&top<28) op=4;
        else if(top>=28) op=5;
        else op=3;

        for (int j = 0; j < op&&top>0; j++)
        {
            printf("%d : %d\n",people[sum][0],people[sum][1]);
            sum++;
            top--;
        }

        for (int i = 0; i < top; i++)
        {
            people[sum+i][1]++;
        }

        if(top<0) top=0;
        if(top>=28&&top<35) op=4;
        else if(top>=35) op=5;
        else op=3;

    }

    while(top!=0)
    {
        for (int j = 0; j < op&&top>0; j++)
        {
            printf("%d : %d\n",people[sum][0],people[sum][1]);
            sum++;
            top--;
        }

        for (int i = 0; i < top; i++)
        {
            people[sum+i][1]++;
        }

        if(top<0) top=0;
        if(top>=28&&top<35) op=4;
        else if(top>=35) op=5;
        else op=3;


    }
}
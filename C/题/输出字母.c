#include<stdio.h>
int main()
{
    char letter;
    int n;
    scanf("%c",&letter);
        if(letter>'z')
    {
        printf("Not a Letter");
        return 0;
    }
    if(letter<'A')
    {
        printf("Not a Letter");
        return 0;
    }
    if(letter>'Z'&&letter<'a')
    {
        printf("Not a Letter");
        return 0;
    }
    scanf("%d",&n);
        if(letter+n-1>'z')
    {
        printf("OverfIow!");
        return 0;
    }   
        if(letter<='Z'&&letter+n-1>'Z')
    {
        printf("OverfIow!");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        printf("%c ",letter+i);
    }
    return 0;
}
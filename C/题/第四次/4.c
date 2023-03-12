#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char terminal[2000] = {0};

typedef struct operate
{
    int op;
    int pos;
    int len;
    char str[2000];
} operate;

void delete(int pos,int t)
{
    char temp[2000]={0};
    for (int i = 0; i < pos; i++)
    {
        temp[i]=terminal[i];
    }
    int len2=strlen(terminal);
    for (int i = pos; i+t < len2; i++)
    {
        temp[i]=terminal[i+t];
    }
    strcpy(terminal,temp);
}


void insert(int pos,char *str)
{
    char temp[2000]={0};
    for (int i = 0; i < pos; i++)
    {
        temp[i]=terminal[i];
    }
    strcat(temp,str);
    strcat(temp,terminal+pos);
    strcpy(terminal,temp);
}


int main()
{
    fgets(terminal, 2000, stdin);

    operate after[200];
    operate before[200];
    operate final[200];
    operate before_final[200];
    int op = 0;
    int cnt = -1;

    int n;
    scanf("%d", &n);
    for (int i = 0; i <n; i++)
    {
        cnt++;
        scanf("%d", &before[cnt].op);
        scanf("%d", &before[cnt].pos);
        scanf("%s", before[cnt].str);
    }
    cnt = -1;
    getchar();
    while (scanf("%d", &op),op!=-1)
    {
        cnt++;
        after[cnt].op = op;
        if(op==3) continue;
        if(op==1)
        {
            scanf("%d", &after[cnt].pos);
            scanf("%s", after[cnt].str);           
        }
        if(op==2)
        {
            scanf("%d", &after[cnt].pos);
            scanf("%d", &after[cnt].len);                    
        }
    }

    int cnt_before_final=0;
    int top=-1; 

    for(int i = 0; i <= cnt; i++)
    {
        if(after[i].op==3&&top!=-1)
        {
            top--;
        }
        else if(after[i].op==3&&top==-1&&n!=0)
        {
            before_final[cnt_before_final++]=before[--n];
        }
        else if(after[i].op==1||after[i].op==2)
        {
            top++;
            final[top]=after[i];
        }
    }

    for (int i = 0; i < cnt_before_final; i++)
    {
        // printf("%d %d %s\n",before_final[i].op,before_final[i].pos, before_final[i].str);

        if(before_final[i].op==1)
        {
            delete(before_final[i].pos,strlen(before_final[i].str));
        }
        else
        {
            insert(before_final[i].pos,before_final[i].str);
        }
    }
    
    for (int i = 0; i <= top; i++)
    {
        // printf("%d %d %s\n",final[i].op,final[i].pos, final[i].str);
        if(final[i].op==1)
        {
            insert(final[i].pos,final[i].str);
        }
        else
        {
            delete(final[i].pos,final[i].len);
        }
    }
    printf("%s",terminal);
}
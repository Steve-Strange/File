#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NHASH  3001
#define MULT  37
unsigned int hash(char *str)
{
       unsigned int h=0;
       char *p;
       for(p=str; *p!='\0'; p++)
            h = MULT*h + *p;
       return h % NHASH;
}

char hashlist[NHASH+1][20][22];

char dictionary[4000][22];

int main()
{
    FILE *dic=fopen("dictionary3000.txt","r");
    char a[100];
    int cnt=0,wordlen=0;
    int index[27]={0};
    while(!feof(dic))
    {
        fscanf(dic,"%s",a);
        strcpy(dictionary[cnt],a);
        index[dictionary[cnt][0]-'a'+1]++;
        unsigned int hashnum=hash(dictionary[cnt]);
        int hashcnt=0;
        while(hashlist[hashnum][hashcnt][0]) hashcnt++;
        strcpy(hashlist[hashnum][hashcnt],dictionary[cnt]);
        cnt++;
    }
    for(int i=26;i>=1;i--){
        for(int j=0;j<i;j++){
            index[i]+=index[j];
        }
    }

    // for(int i=0;i<500;i++)
    // printf("%d\n",hashlist[500][200][0]);
    // for(int i=0;i<=26;i++){
    //     printf("%d ",index[i]);
    // }

    char temp[25]={0};
    int op;
    scanf("%s %d",temp,&op);
            if(op==1){
                for(int j=0;j<cnt;j++){
                    if(strcmp(temp,dictionary[j])==0)
                    {
                        printf("1 %d\n",j+1);
                        break;
                    }
                    if(strcmp(temp,dictionary[j])<0)
                    {
                        printf("0 %d\n",j+1);
                        break;
                    }
                }
            }
            if(op==2){
                int count=0;
                int low=0,high=cnt-1,mid=(low+high)/2;
                while(low<=high){
                    count++;
                    if(strcmp(dictionary[mid],temp)==0){
                        printf("1 %d\n",count);
                        break;
                    }
                    if(strcmp(dictionary[mid],temp)<0){
                        low=mid+1;
                    }
                    if(strcmp(dictionary[mid],temp)>0){
                        high=mid-1;
                    }
                    mid=(low+high)/2;
                    if(low>high){
                        printf("0 %d\n",count);
                        break;
                    }
                }

            }
            if(op==3){
                int count=0;
                int low=index[temp[0]-'a'],high=index[temp[0]-'a'+1]-1,mid=(low+high)/2;
                if(low>high)
                {
                    printf("0 0");
                    return 0;
                }
                while(low<=high){
                    count++;
                    if(strcmp(dictionary[mid],temp)==0){
                        printf("1 %d\n",count);
                        break;
                    }
                    if(strcmp(dictionary[mid],temp)<0){
                        low=mid+1;
                    }
                    if(strcmp(dictionary[mid],temp)>0){
                        high=mid-1;
                    }
                    mid=(low+high)/2;
                    if(low>high){
                        printf("0 %d\n",count);
                        break;
                    }
                }
            }
            if(op==4){
                int count=0;
                unsigned int hashnum=hash(temp);
                while(hashlist[hashnum][count][0]!=0)
                {
                    if(strcmp(temp,hashlist[hashnum][count])==0)
                    {
                        printf("1 %d\n",count+1);
                        break;
                    }
                    else count++;
                }
                if(!hashlist[hashnum][count][0]) printf("0 %d\n",count);
            }
    return 0;
}
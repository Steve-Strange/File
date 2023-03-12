#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define keytype int

int cnt = 0;

void  selectSort(keytype k[ ],int n)   //ѡ������  ÿһ����û��������һ����ֵ�����������ź���ĺ��� O(n^2) ���ȶ�

  {     int i, j, d;
         keytype  temp;
         for(i=0;i<n-1;i++){
              d=i;
              for(j=i+1;j<n;j++){
                    cnt++;
                    if(k[j]<k[d]) 
                    {
                        d=j;
                    }
              }
              if(d!=i){    
                      /* ��СֵԪ�ط�δ����Ԫ�صĵ�һ��Ԫ��ʱ */
                     temp=k[d] ;
                     k[d]=k[i];
                     k[i]=temp;
              }
         }
  }

void  bubbleSort(keytype k[ ],int n)     //ð������ ÿһ���ڸ���������Ԫ��֮�䰴�򽻻� O(n)-O(n^2) ƽ��O(n^2) �ȶ�
{     int i, j, flag=1;
       keytype temp;
       for(i=n-1; i>0 && flag==1; i--){
              flag=0;                        /* ÿ������ǰ��־flag��0 */ 
              for(j=0;j<i;j++) 
              {
                    cnt++;
                    if(k[j]>k[j+1]){
                         temp=k[j];
                         k[j]=k[j+1];
                         k[j+1]=temp;  /* ��������Ԫ�ص�λ�� */     
                         flag=1;              /* ��־flag��1 */   //Ϊ1�н�����Ϊ0�����Ѿ�ȫ������
                    }
              }
        }
 }

void  adjust(keytype k[ ],int i,int n)  //k :���У� i : �������Ķ������ĸ�����ţ� n :�������Ķ������Ľ����Ŀ                                       
{                                       //ֻ�и�������󶥶�ʱ �³���Ԫ�أ�����Ϊһ���󶥶�
        int j;                          //��ʼ���󶥶ѵ�ʱ�򣬾Ϳ����������ϵ�����������  for(i=n/2-1;i>=0;i--)
        keytype  temp;                                  
        temp=k[i];
        j=2*i+1;
        while(j<n){
               if(j+1<n && k[j]<k[j+1])
                      j++;
                cnt++;
               if(temp<k[j]) {
                      k[(j-1)/2]=k[j];
                      j=2*j+1;
               }
               else break;
         }
         k[(j-1)/2]=temp;
}
void heapSort(keytype k[ ],int n)   //������     O(n)+O(nlog2n)  ���ȶ�
{
       int i;
       keytype  temp;
       for(i=n/2-1;i>=0;i--)  //��ʼ����      
              adjust(k,i,n);
       for(i=n-1;i>=1;i--){   //ÿ���öѶ������ֵ���ĩβԪ�ؽ����������µ���ʣ��Ķ�  
              temp=k[i];
              k[i]=k[0];
              k[0]=temp;
              adjust(k,0,i);   
       }
}

void merge(keytype x[ ],keytype tmp[ ],int left,int leftend,int rightend)
{     
       int i=left, j=leftend+1, q=left;
       while(i<=leftend && j<=rightend)
       {
           cnt++;
              if(x[i]<=x[j]) 
                    tmp[q++]=x[i++];
              else
                    tmp[q++]=x[j++];
       }
    while(i<=leftend)
      tmp[q++]=x[i++];
     while(j<=rightend)
           tmp[q++]=x[j++];
     for(i=left; i<=rightend; i++)
           x[i]=tmp[i];
}
void mSort(keytype k[], keytype tmp[], int left, int right)
{
    int center;
    if(left < right){
        center = (left+right)/2;
        mSort(k, tmp, left, center);
        mSort(k, tmp, center+1, right);
        merge(k, tmp, left,center, right);
    }
}
void mergeSort(keytype k[ ],int n)
{
    keytype *tmp;
    tmp = (keytype *)malloc(sizeof(keytype) * n);
    if(tmp != NULL) {
        mSort(k, tmp, 0, n-1);
        free(tmp);
    }
}

void swap(int *i, int *j)
{
        keytype tmp;
        tmp=*j;
        *j=*i;
        *i=tmp;
}
void quick(int k[ ],int left,int right)
{     
    int i, last;
    if(left<right){
        last=left; 
        for(i=left+1;i<=right;i++)
        {
            cnt++;
            if(k[i]<k[left])
                swap(&k[++last],&k[i]); 
        }
        swap(&k[left],&k[last]);
        quick(k,left,last-1); 
        quick(k,last+1,right);   
    }
}
void quickSort(keytype k[],int n)     //���㷨
{
       quick(k,0,n-1);
}



int main(){
    int num,op;
    scanf("%d%d",&num,&op);
    int arr[105]={0};
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    if(op==1) selectSort(arr,num);
    if(op==2) bubbleSort(arr,num);
    if(op==3) heapSort(arr,num);
    if(op==4) mergeSort(arr,num);
    if(op==5) quickSort(arr,num);

    for(int i=0;i<num;i++){
        printf("%d ",arr[i]);
    }
    printf("\n%d",cnt);


}
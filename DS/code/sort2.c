#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define keytype int

int cnt = 0;

void  selectSort(keytype k[ ],int n)   //选择排序  每一次在没排序中找一个极值，按序连在排好序的后面 O(n^2) 不稳定

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
                      /* 最小值元素非未排序元素的第一个元素时 */
                     temp=k[d] ;
                     k[d]=k[i];
                     k[i]=temp;
              }
         }
  }

void  bubbleSort(keytype k[ ],int n)     //冒泡排序 每一趟在各两个相邻元素之间按序交换 O(n)-O(n^2) 平均O(n^2) 稳定
{     int i, j, flag=1;
       keytype temp;
       for(i=n-1; i>0 && flag==1; i--){
              flag=0;                        /* 每趟排序前标志flag置0 */ 
              for(j=0;j<i;j++) 
              {
                    cnt++;
                    if(k[j]>k[j+1]){
                         temp=k[j];
                         k[j]=k[j+1];
                         k[j+1]=temp;  /* 交换两个元素的位置 */     
                         flag=1;              /* 标志flag置1 */   //为1有交换，为0则是已经全部有序
                    }
              }
        }
 }

void  adjust(keytype k[ ],int i,int n)  //k :序列， i : 被调整的二叉树的根的序号， n :被调整的二叉树的结点数目                                       
{                                       //只有根不满足大顶堆时 下沉根元素，调整为一个大顶堆
        int j;                          //初始建大顶堆的时候，就可以自下向上调整各个子树  for(i=n/2-1;i>=0;i--)
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
void heapSort(keytype k[ ],int n)   //堆排序     O(n)+O(nlog2n)  不稳定
{
       int i;
       keytype  temp;
       for(i=n/2-1;i>=0;i--)  //初始化堆      
              adjust(k,i,n);
       for(i=n-1;i>=1;i--){   //每次用堆顶的最大值与堆末尾元素交换，后重新调整剩余的堆  
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
void quickSort(keytype k[],int n)     //主算法
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
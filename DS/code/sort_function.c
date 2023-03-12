#define keytype int
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertSort(keytype k[ ],int n)  //插入排序  每一次把没排序中的第一个按序插入到前面排完的里 O(n)-O(n^2) 平均O(n^2) 稳定
{
       int i, j;
       keytype  temp;
       for(i=1;i<n;i++){
             temp=k[i];
             for(j=i-1; j>=0 && temp<k[j]; j--) 
                    k[j+1]=k[j];
             k[j+1]=temp;
       }
}

void  insertBSort(keytype k[ ], int n)  //折半插入排序
{      int i, j, low, high, mid;
        keytype temp;
        for(i=1;i<n;i++ ){
              temp=k[i];
              low=0;
              high=i-1;
              while(low<=high){
                     mid=(low+high)/2;
                     if(temp<k[mid])
                            high=mid-1;
                     else
                            low=mid+1;
              }
              for(j=i-1;j>=low;j--)
                     k[j+1]=k[j];
              k[low]=temp;
        }
}


int searchB(keytype a[ ],int n,keytype k)  //二分查找不大于k的最大元素
{
        int low=0, high=n-1, mid;
        while(low<=high){
              mid=(low+high)/2;
              if(a[mid]==k)
                     return mid;          /*  返回mid  */
              if(k>a[mid])
                     low=mid+1;         /*  准备查找后半部分 */
              else
                     high=mid-1;        /* 准备查找前半部分 */
         }
         return high;                          /* 返回high */
}


void  selectSort(keytype k[ ],int n)   //选择排序  每一次在没排序中找一个极值，按序连在排好序的后面 O(n^2) 不稳定

  {     int i, j, d;
         keytype  temp;
         for(i=0;i<n-1;i++){
              d=i;
              for(j=i+1;j<n;j++)
                    if(k[j]<k[d]) 
                         d=j;
              if(d!=i){    
                      /* 最小值元素非未排序元素的第一个元素时 */
                     temp=k[d] ;
                     k[d]=k[i];
                     k[i]=temp;
              }
         }
  }

void selectSort2(int array[], int n)  //选择排序2
{
    int i, j, tmp;
    for(i=0; i<n; i++)
        for(j=i; j<n; j++){
            if(array[i] > array[j]){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
}


void  bubbleSort(keytype k[ ],int n)     //冒泡排序 每一趟在各两个相邻元素之间按序交换 O(n)-O(n^2) 平均O(n^2) 稳定
{     int i, j, flag=1;
       keytype temp;
       for(i=n-1; i>0 && flag==1; i--){
              flag=0;                        /* 每趟排序前标志flag置0 */ 
              for(j=0;j<i;j++) 
                    if(k[j]>k[j+1]){
                         temp=k[j];
                         k[j]=k[j+1];
                         k[j+1]=temp;  /* 交换两个元素的位置 */     
                         flag=1;              /* 标志flag置1 */   //为1有交换，为0则是已经全部有序
                    }
        }
}


void  shellSort(keytype k[ ],int n)      //谢尔排序  每次将一定间隔排列的元素冒泡排序，间隔逐次减半，直到1  O(nlog2n)-O(n^2)之间 平均<O(n^(3/2)) 不稳定

{     int  i, j, flag, gap=n;
       keytype  temp; 
       while(gap>1){
              gap=gap/2;          //跳着取
              do{
                    flag=0;                  /* 每趟排序前,标志flag置0 */  //冒泡排序
                    for(i=0;i<n-gap;i++){
                         j=i+gap;
                         if(k[i]>k[j]){
                               temp=k[i];
                               k[i]=k[j];
                               k[j]=temp;
                               flag=1;  
                         }
                    }
               }while(flag!=0);
        }
}

void  shellSort(int v[ ], int n)  //谢尔排序2  from K & R
{
    int gap, i, j, temp;
    for( gap = n/2; gap >0; gap /= 2)
        for(i=gap; i<n; i++)
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j -= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
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


void merge(keytype x[ ],keytype tmp[ ],int left,int leftend,int rightend)  //二路归并合并算法 O(nlog2n)  空间O(n)
{     
       int i=left, j=leftend+1, q=left;
       while(i<=leftend && j<=rightend)
       {
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
void mSort(keytype k[], keytype tmp[], int left, int right)   //递归  分治  每次两两合并1-2-4-8 （不足时直接复制，最后一趟合并）
{
    int center;
    if(left < right){
        center = (left+right)/2;
        mSort(k, tmp, left, center);
        mSort(k, tmp, center+1, right);
        merge(k, tmp, left,center, right);    //类似后序遍历
    }
}
void mergeSort(keytype k[ ],int n)     //二路归并排序，主算法
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
void quick(keytype k[ ],int left,int right)
{     int i, j;
       keytype pivot;
       if(left<right){
              i=left; j=right+1;
              pivot = k[left];
              while(1){ 
                     while(k[++i]<pivot && i!=right) { }
                     while(k[--j]>pivot && j!=left) { }
                     if(i<j)
                            swap(&k[i],&k[j]);  /*交换K[i]与K[j]的内容*/
                     else
                            break;
               }
               swap(&k[left],&k[j]);      /*交换K[s]与K[j]的内容*/    //类似前序遍历
               quick(k,left,j-1);       /* 对前一部分排序 */
               quick(k,j+1,right);       /* 对后一部分排序 */
       }
}
void quickSort(keytype k[],int n)     //主算法
{
       quick(k,0,n-1);
}


//标准快速排序
void swap2(keytype v[ ],int i, int j)
{
        keytype tmp;
        tmp = v[i]; v[i] = v[j]; v[j]=tmp;
}
void qsort2(keytype v[ ],int left, int right)
{
    int i, last;

    if(left >= right)
        return;
    swap2(v, left, (left+right)/2); //move partition elem to v[0]
    last = left;
    for(i=left+1; i<=right; i++)  //partition
        if(v[i] < v[left])
            swap2(v, ++last, i);
    swap2(v,left, last); //restore partition elem
    qsort2(v, left, last);  
    qsort2(v, last+1, right);
}
void quickSort2(keytype k[],int n)
{
       qsort2(k,0,n-1);
}

//时间 O(nlog2n)-O(n2) 平均O(nlog2n)
//空间 O(n)-O(log2n) 平均O(log2n)
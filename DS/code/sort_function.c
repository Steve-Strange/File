#define keytype int
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertSort(keytype k[ ],int n)  //��������  ÿһ�ΰ�û�����еĵ�һ��������뵽ǰ��������� O(n)-O(n^2) ƽ��O(n^2) �ȶ�
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

void  insertBSort(keytype k[ ], int n)  //�۰��������
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


int searchB(keytype a[ ],int n,keytype k)  //���ֲ��Ҳ�����k�����Ԫ��
{
        int low=0, high=n-1, mid;
        while(low<=high){
              mid=(low+high)/2;
              if(a[mid]==k)
                     return mid;          /*  ����mid  */
              if(k>a[mid])
                     low=mid+1;         /*  ׼�����Һ�벿�� */
              else
                     high=mid-1;        /* ׼������ǰ�벿�� */
         }
         return high;                          /* ����high */
}


void  selectSort(keytype k[ ],int n)   //ѡ������  ÿһ����û��������һ����ֵ�����������ź���ĺ��� O(n^2) ���ȶ�

  {     int i, j, d;
         keytype  temp;
         for(i=0;i<n-1;i++){
              d=i;
              for(j=i+1;j<n;j++)
                    if(k[j]<k[d]) 
                         d=j;
              if(d!=i){    
                      /* ��СֵԪ�ط�δ����Ԫ�صĵ�һ��Ԫ��ʱ */
                     temp=k[d] ;
                     k[d]=k[i];
                     k[i]=temp;
              }
         }
  }

void selectSort2(int array[], int n)  //ѡ������2
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


void  bubbleSort(keytype k[ ],int n)     //ð������ ÿһ���ڸ���������Ԫ��֮�䰴�򽻻� O(n)-O(n^2) ƽ��O(n^2) �ȶ�
{     int i, j, flag=1;
       keytype temp;
       for(i=n-1; i>0 && flag==1; i--){
              flag=0;                        /* ÿ������ǰ��־flag��0 */ 
              for(j=0;j<i;j++) 
                    if(k[j]>k[j+1]){
                         temp=k[j];
                         k[j]=k[j+1];
                         k[j+1]=temp;  /* ��������Ԫ�ص�λ�� */     
                         flag=1;              /* ��־flag��1 */   //Ϊ1�н�����Ϊ0�����Ѿ�ȫ������
                    }
        }
}


void  shellSort(keytype k[ ],int n)      //л������  ÿ�ν�һ��������е�Ԫ��ð�����򣬼����μ��룬ֱ��1  O(nlog2n)-O(n^2)֮�� ƽ��<O(n^(3/2)) ���ȶ�

{     int  i, j, flag, gap=n;
       keytype  temp; 
       while(gap>1){
              gap=gap/2;          //����ȡ
              do{
                    flag=0;                  /* ÿ������ǰ,��־flag��0 */  //ð������
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

void  shellSort(int v[ ], int n)  //л������2  from K & R
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


void  adjust(keytype k[ ],int i,int n)  //k :���У� i : �������Ķ������ĸ�����ţ� n :�������Ķ������Ľ����Ŀ                                       
{                                       //ֻ�и�������󶥶�ʱ �³���Ԫ�أ�����Ϊһ���󶥶�
        int j;                          //��ʼ���󶥶ѵ�ʱ�򣬾Ϳ����������ϵ�����������  for(i=n/2-1;i>=0;i--)
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


void merge(keytype x[ ],keytype tmp[ ],int left,int leftend,int rightend)  //��·�鲢�ϲ��㷨 O(nlog2n)  �ռ�O(n)
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
void mSort(keytype k[], keytype tmp[], int left, int right)   //�ݹ�  ����  ÿ�������ϲ�1-2-4-8 ������ʱֱ�Ӹ��ƣ����һ�˺ϲ���
{
    int center;
    if(left < right){
        center = (left+right)/2;
        mSort(k, tmp, left, center);
        mSort(k, tmp, center+1, right);
        merge(k, tmp, left,center, right);    //���ƺ������
    }
}
void mergeSort(keytype k[ ],int n)     //��·�鲢�������㷨
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
                            swap(&k[i],&k[j]);  /*����K[i]��K[j]������*/
                     else
                            break;
               }
               swap(&k[left],&k[j]);      /*����K[s]��K[j]������*/    //����ǰ�����
               quick(k,left,j-1);       /* ��ǰһ�������� */
               quick(k,j+1,right);       /* �Ժ�һ�������� */
       }
}
void quickSort(keytype k[],int n)     //���㷨
{
       quick(k,0,n-1);
}


//��׼��������
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

//ʱ�� O(nlog2n)-O(n2) ƽ��O(nlog2n)
//�ռ� O(n)-O(log2n) ƽ��O(log2n)
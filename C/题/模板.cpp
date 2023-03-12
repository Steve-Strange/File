#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>//ͷ�ļ��ϼ� 

const double eps=1e-5;
const double pi=3.1415926;
const long long bp1=998244353;
const long long bp2=1000000007;//���ó��� 

/*
������ 
0x0f00 ���򣬼��� 
0x0f01 ����������������С/�󹫱�/Լ����� 
0x0f02 �ַ��� 
0x0f03 ���㼸�� 
0x0f04 ���� 
0x0f05 ���� 
*/ 

//0x0f00 ������� 
int cmp(const void* a,const void* b) 
{
	if(*(*)a>*(*)b)	return 1;
	if(fabs(*(*)a-*(*)b)<eps)	return 0;
	if(*(*)a<*(*)b)	return -1;
}
//������� 
/*���� double���� ��С���� 
int cmp(const void* a,const void* b) 
{
	if(*(double*)a>*(double*)b)	return 1;
	if(fabs(*(double*)a-*(double*)b)<eps)	return 0;
	if(*(double*)a<*(double*)b)	return -1;
}
���� double���� �Ӵ�С 
int cmp(const void* a,const void* b) 
{
	if(*(double*)a<*(double*)b)	return 1;
	if(fabs(*(double*)a-*(double*)b)<eps)	return 0;
	if(*(double*)a>*(double*)b)	return -1;
}
���� �ṹ�� ���ȼ�����
�����и��ṹ�� student������Ҫ���ɼ��������򣬳ɼ���ͬʱ��ѧ����������
�ر�ע�⣬c����ʹ�ýṹ�壬�����¸�ʽ�Ƚ�ʡ�����ֺ�ǰ���Ǹ����������Ҫ�õĽṹ�����֣�struct�����Ǹ����ְ���ɶ��ɶ 
typedef struct Studen
{
	int grade,num;//�ɼ���ѧ�� 
}student;
int cmp(const void* a,const void* b) 
{
	student *c=(student*)a,*d=(student*)b;
	if(c->grade>d->grade)	return 1;
	if(c->grade<d->grade)	return -1;
	if(c->num>d->num)	return 1;
	if(c->num<d->num)	return -1;
	return 0;
}
������� 
*/
qsort(point,num,sizeof(),cmp);
/*
cmp���qsortʹ�ã����������int a[n]��ǰk(k<=n)��Ԫ�����������д
int a[n];
int cmp(const void* a,const void* b) 
{
	if(*(int*)a>*(int*)b)	return 1;
	if(fabs(*(int*)a-*(int*)b)<eps)	return 0;
	if(*(int*)a<*(int*)b)	return -1;
}
qsort(a,k,sizeof(int),cmp); 

�ṹ��
typedef struct Studen
{
	int grade,num;//�ɼ���ѧ�� 
}student;
student stu[n];
int cmp(const void* a,const void* b) 
{
	student *c=(student*)a,*d=(student*)b;
	if(c->grade>d->grade)	return 1;
	if(c->grade<d->grade)	return -1;
	if(c->num>d->num)	return 1;
	if(c->num<d->num)	return -1;
	return 0;
}
qsort(stu,k,sizeof(student),cmp);
*/
//����
int lower_bound(int x,int y,int e,int *a)
{
	if(e>a[y])	return -1;
	int q;
	while(x<y)
	{
		q=(x+y)>>1;
		if(a[q]<e)	x=q+1;
		else	y=q;
	}
	return x;
}
int upper_bound(int x,int y,int e,int *a)
{
	if(e>=a[y])	return -1;
	int q;
	while(x<y)
	{
		q=(x+y)>>1;
		if(a[q]<=e)	x=q+1;
		else	y=q;
	}
	return x;
}
/*
lower_bound()�����ظ������е�һ�����ڻ���ڲ���ֵ���±꣬���û�����-1.
upper_bound()�����ظ������е�һ�����ڲ���ֵ���±꣬���û�����-1.
ʹ�� ����
int a[100];ȷ��a�Ѿ����������ź�
upper_bound(0,99,233,a);
������±�0���±�99���м���(���˾�����)������ֵ233 
*/ 

//0x0f01 ����������������С/�󹫱�/Լ�����
int is_prime(int n)
{
	if(!(n&1))	return 0;
	int n2=sqrt(n);
	for(int i=3;i<=n2;i+=2)	if(!(n%i))	return 0;
	return 1;
}//����������1��������0���ǣ�n����ʱЧ���п�
int qpow(int a,int b,int p)
{
    //��(a^b) mod p ��isprime�����л��õ�
    int ret=1;
    while(b)
    {
        if(b&1) ret=1ll*ret*a%p;
        a=1ll*a*a%p,b>>=1;
    }
    return ret;
}
int isprime(int n)//����1��ʾnΪ������0��ʾn��������
{
    if(n==2||n==3) return 1;
    if(!(n&1)) return 0;
    int m=n-1,a,tmp,ans,cnt=0;
    while(!(m&1))
        m>>=1,cnt++;
    int rd=20011224,seed=998244353,seed2=20217371;
    for(int i=0;i<20;i++)
    {
        rd=rd*seed+seed2;
        if(rd<0) rd=-rd;
		a=rd%(n-1)+1;
        //��֤����С������涨��
		tmp=qpow(a,m,n);
		for(int j=0;j<cnt;j++)
        {
	    	ans=1ll*tmp*tmp%n;
	    	if(ans==1)
            {
                if(tmp!=1 && tmp!=n-1)
                    return 0;
	        	break ;
	    	}
	    	tmp=ans;
		}
		if(ans!=1) return 0;
    }
    return 1;
}//��л���̣��ж����� 
unsigned char mi[n+1]={0};
void pfd(int n) 
{
	int n2=sqrt(n);
	while(!(n%2))
	{
		mi[2]++;
		n/=2;
	}
	for(int i=3;i<=n2&&i<=n;i+=2)
	{
		while(!(n%i))
		{
			mi[i]++;
			n/=i;
		}
	}
	if(n!=1)	mi[n]++;
	return;
}//��n�ֽ���������mi[i]��ֵ��ʾn��������i��mi[i]���ݣ�0���ǲ�����i=1��������迼�ǣ�nͬ��������̫�� 
long long gcd(long long a,long long b)
{
	if(!b)	return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a*(b/gcd(a,b));
}//�������Լ������С������

//0x0f02 �ַ���
int is_palindrome(char *a)
{
	int len=strlen(a);
	for(int i=0;i<len/2;i++)	if(a[i]!=a[len-i-1])	return 0;
	return 1;
}//�ж��Ƿ�Ϊ���Ĵ�����������ַ���char s[100]��ʹ��is_palindrome(s)������ر�֤�ַ�����β����ֵ0
int bina(char *a,char *b)
{
	char *c=strstr(a,b);
	if(c==NULL)	return -1;
	return (int)(c-a);
}//�ж��ַ���b��a�е�һ�γ��ֵ�λ�ã�û�����򷵻�-1�����ַ����״γ���λ�õ������±꣬������̫���ָ���ͬѧ
 
 
//0x0f03 ���㼸��
double dis(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}//���룬������ΪС����������ռ䲻�پ���
double s(double a,double b,double c)
{
	return 0.5*a*b*sqrt(1-pow((a*a+b*b-c*c)/(2*a*b),2));
}//���������������Ϊ���߳� 

//0x0f04 ����
int Zeller(int y,int m,int d)
{
    if(m==1 || m==2) y--,m+=12;
    int c=y/100;y%=100;
    return ((y+y/4+c/4-2*c+26*(m+1)/10+d-1)%7+7)%7;
}/*
�������º������Լ���һ������Ϊ���ڼ�
����ֵ�ĺ��壺0-�����գ�1-����һ��2-���ڶ���3-��������4-�����ģ�5-�����壻6-������
*/ 
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};//ƽ��ÿ���µ�����
int isday(int y)
{
    int d=y%100;y/=100;//��
    int m=y%100;y/=100;//��
    if(m<1 || m>12) return 0;//�±�����1-12֮��
    else if(d==29&&m==2)//����2��29��
        return (y%100&&y%4==0)||y%400==0;//�Ϸ����ڵ���ݱ���Ϊ����
    return d>=1 && d<=day[m];//�յ�����
}//�������º��������ж�ĳ����λ���Ƿ��ǺϷ�������

//0x0f05 ����
long long qpow(long long a,long long b,long long p)
{
    long long ret=1;
    while(b)
    {
        if(b&1) 
            ret=1ll*ret*a%p;
        a=1ll*a*a%p,b>>=1;
    }
    return ret;
}//������a��b�η�ģp�Ľ�� 
long long qpow(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b&1) 
            ret=1ll*ret*a;
        a=1ll*a*a,b>>=1;
    }
    return ret;
}//��ģ 
long long C(long long m,long long n)
{
	if(!m)	return 0;
	if(!n)	return 1;
	return C(m-1,n-1)+C(m-1,n);
}//����� nѡm
 

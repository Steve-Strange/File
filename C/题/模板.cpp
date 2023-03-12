#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>//头文件合集 

const double eps=1e-5;
const double pi=3.1415926;
const long long bp1=998244353;
const long long bp2=1000000007;//常用常量 

/*
检索表 
0x0f00 排序，检索 
0x0f01 素数、质因数、最小/大公倍/约数相关 
0x0f02 字符串 
0x0f03 计算几何 
0x0f04 日期 
0x0f05 其它 
*/ 

//0x0f00 排序相关 
int cmp(const void* a,const void* b) 
{
	if(*(*)a>*(*)b)	return 1;
	if(fabs(*(*)a-*(*)b)<eps)	return 0;
	if(*(*)a<*(*)b)	return -1;
}
//复制填空 
/*举例 double类型 从小到大 
int cmp(const void* a,const void* b) 
{
	if(*(double*)a>*(double*)b)	return 1;
	if(fabs(*(double*)a-*(double*)b)<eps)	return 0;
	if(*(double*)a<*(double*)b)	return -1;
}
举例 double类型 从大到小 
int cmp(const void* a,const void* b) 
{
	if(*(double*)a<*(double*)b)	return 1;
	if(fabs(*(double*)a-*(double*)b)<eps)	return 0;
	if(*(double*)a>*(double*)b)	return -1;
}
举例 结构体 优先级排序
例如有个结构体 student，现需要按成绩升序排序，成绩相同时按学号升序排序
特别注意，c语言使用结构体，按如下格式比较省力，分号前面那个是你接下来要用的结构体名字，struct后面那个名字爱填啥填啥 
typedef struct Studen
{
	int grade,num;//成绩，学号 
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
按需填空 
*/
qsort(point,num,sizeof(),cmp);
/*
cmp配合qsort使用，比如对数组int a[n]的前k(k<=n)个元素升序排序就写
int a[n];
int cmp(const void* a,const void* b) 
{
	if(*(int*)a>*(int*)b)	return 1;
	if(fabs(*(int*)a-*(int*)b)<eps)	return 0;
	if(*(int*)a<*(int*)b)	return -1;
}
qsort(a,k,sizeof(int),cmp); 

结构体
typedef struct Studen
{
	int grade,num;//成绩，学号 
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
//检索
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
lower_bound()：返回该数组中第一个大于或等于查找值的下标，如果没有输出-1.
upper_bound()：返回该数组中第一个大于查找值的下标，如果没有输出-1.
使用 例如
int a[100];确保a已经按照升序排好
upper_bound(0,99,233,a);
代表从下标0到下标99进行检索(两端均包含)，检索值233 
*/ 

//0x0f01 素数、质因数、最小/大公倍/约数相关
int is_prime(int n)
{
	if(!(n&1))	return 0;
	int n2=sqrt(n);
	for(int i=3;i<=n2;i+=2)	if(!(n%i))	return 0;
	return 1;
}//暴力开根，1是素数，0不是，n不大时效率尚可
int qpow(int a,int b,int p)
{
    //求(a^b) mod p 在isprime函数中会用到
    int ret=1;
    while(b)
    {
        if(b&1) ret=1ll*ret*a%p;
        a=1ll*a*a%p,b>>=1;
    }
    return ret;
}
int isprime(int n)//返回1表示n为素数，0表示n不是素数
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
        //验证费马小定理的逆定理
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
}//感谢助教，判断素数 
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
}//将n分解质因数，mi[i]的值表示n含质因数i的mi[i]次幂，0就是不含，i=1的情况不予考虑，n同样不建议太大 
long long gcd(long long a,long long b)
{
	if(!b)	return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a*(b/gcd(a,b));
}//经典最大公约数与最小公倍数

//0x0f02 字符串
int is_palindrome(char *a)
{
	int len=strlen(a);
	for(int i=0;i<len/2;i++)	if(a[i]!=a[len-i-1])	return 0;
	return 1;
}//判断是否为回文串，例如对于字符串char s[100]，使用is_palindrome(s)，请务必保证字符串结尾有数值0
int bina(char *a,char *b)
{
	char *c=strstr(a,b);
	if(c==NULL)	return -1;
	return (int)(c-a);
}//判断字符串b在a中第一次出现的位置，没出现则返回-1，出现返回首次出现位置的数组下标，帮助不太理解指针的同学
 
 
//0x0f03 计算几何
double dis(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}//距离，点坐标为小数，或立体空间不再举例
double s(double a,double b,double c)
{
	return 0.5*a*b*sqrt(1-pow((a*a+b*b-c*c)/(2*a*b),2));
}//三角形面积，参数为三边长 

//0x0f04 日期
int Zeller(int y,int m,int d)
{
    if(m==1 || m==2) y--,m+=12;
    int c=y/100;y%=100;
    return ((y+y/4+c/4-2*c+26*(m+1)/10+d-1)%7+7)%7;
}/*
调用以下函数可以计算一个日期为星期几
返回值的含义：0-星期日；1-星期一；2-星期二；3-星期三；4-星期四；5-星期五；6-星期六
*/ 
int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};//平年每个月的天数
int isday(int y)
{
    int d=y%100;y/=100;//日
    int m=y%100;y/=100;//月
    if(m<1 || m>12) return 0;//月必须在1-12之间
    else if(d==29&&m==2)//若是2月29日
        return (y%100&&y%4==0)||y%400==0;//合法日期的年份必须为闰年
    return d>=1 && d<=day[m];//日的区间
}//调用以下函数可以判断某个八位数是否是合法的日期

//0x0f05 其它
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
}//快速求a的b次方模p的结果 
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
}//不模 
long long C(long long m,long long n)
{
	if(!m)	return 0;
	if(!n)	return 1;
	return C(m-1,n-1)+C(m-1,n);
}//组合数 n选m
 

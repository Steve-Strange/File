#include<stdio.h>
#include<math.h>
int main()
{
	double x1,y1,z1,a,b,c,d,p,pi,e,m,n,k,j,x,y,z;
	
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&a,&b,&c,&d,&p);
	if (z1<0) z1=-z1;
	pi=3.1415926535;
	e=2.718281828;
	m=(1/sqrt(2*pi*e))*pow(e,(-(x1-p)*(x1-p)+(y1-p)*(y1-p))/(2*c*c));
	n=(z1*tan(2*d)/sqrt(1+(b*b/a*a)));
	if(x1<0)
	{
		x=m*(x1+n);
	}
	if(x1<0)
	{
		x=m*(x1-n);
	}
	y=m*(y1+(b/a)*(x-x1));
	if (sin(x)<0) k=-sin(x);
	else k=sin(x);
	if (sinh(y)<0) j=-sinh(y);
	else j=sinh(y);
	z=(pow(acrtan(p*cos(x)),ln(1+k)))/(2+j);
	printf("%.2lf\n%.2lf\n%.2lf",x,y,z);
	return 0;
 }

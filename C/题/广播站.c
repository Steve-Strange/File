#include<stdio.h>
#include<math.h>
int main()
{
	int x1,y1,x2,y2,x3,y3;
	double x0,y0,r,a,b,c,p;
	scanf("(%d,%d)\n",&x1,&y1);
	scanf("(%d,%d)\n",&x2,&y2);
	scanf("(%d,%d)",&x3,&y3);
	a=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	x0=((a*x1+b*x2+c*x3)/(a+b+c));
	y0=((a*y1+b*y2+c*y3)/(a+b+c));
	printf("(%.3lf,%.3lf)\n",x0,y0);
	p=(a+b+c)/2;
	r=(2*sqrt(p*(p-a)*(p-b)*(p-c)))/(a+b+c);
	if(fabs(x0)<1e-6)
	{
		if(fabs(y0)<1e-6)
		{
			printf("x^2+y^2=%.3lf^2",r);
		}
		else printf("x^2+(y%c%.3lf)^2=%.3lf^2",y0<0? '+':'-',fabs(y0),r);
	}
	if(fabs(y0)<1e-6)
	{
		printf("(x%c%.3lf)^2+y^2=%.3lf^2",x0<0? '+':'-',fabs(x0),r);
	}
	if(fabs(x0)>=1e-6&&fabs(y0)>=1e-6)
	printf("(x%c%.3lf)^2+(y%c%.3lf)^2=%.3lf^2",x0<0? '+':'-',fabs(x0),y0<0? '+':'-',fabs(y0),r);
	return 0;
}

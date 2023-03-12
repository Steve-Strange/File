#include<stdio.h>
#include<string.h>
double eps=1e-6; //定义精度 
double f(double x) 
{
return // f(x)
}

double solve_f(double low, double high) 
{
	double mid = low+(high-low)/2;
	if(high-low < eps) return mid;
	else if( f(mid)>0 ) return solve_f(low, mid);
	else return solve_f(mid, high);
}

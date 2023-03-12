	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<ctype.h>


int main(){
    double x=1.5;
    char p[50]={0};
    sprintf(p,"%lf",x);
    puts(p);
}
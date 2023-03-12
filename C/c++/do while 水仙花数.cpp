#include<iostream>
using namespace std;
int main(){
	int a,b,c,d;
	a=100; 
	do{	
		b=a/100;
		c=a/10%10;
		d=a%10;
//		c=a/10-b*10;
//		d=a%100-c*10;
		if(a==b*b*b+c*c*c+d*d*d){
		cout<<a<<endl;
		}
		a++;
	} 
	while(a<1000);
	system("pause");	
	return 0;
} 

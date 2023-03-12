#include<iostream>
#include<cstdlib> 
using namespace std;

int main(){
	//输出0~9 十个数字
	int a=0;
	do{
		cout<<a<<endl;
		a++; 
	}   
		while(a<10);   //do....while   语句， 用while判断终止，  do while先进行一次循环，再判断while   while需先判断。 
	
	int b=1000;
	do{
		cout<<b<<endl;
		b++;
	} 
		while(b<20);  //仍会输出一次1000 
	system("pause");
	return 0;
}

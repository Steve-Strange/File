#include<iostream>
using namespace std;

int main(){
	short a=1; //32768=2^15  超出范围后循环   
	
	short e=32769; //输出 - 32767
	
	int b=2; //2^31
	
	long c=3; //2^31
	
	long long d=4; //2^63
	
	cout <<e<<endl;
	
	system("pause"); 
	
	return 0;
} 

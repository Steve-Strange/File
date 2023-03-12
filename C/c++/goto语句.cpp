#include<iostream>
using namespace std;
int main(){
	cout<<"1"<<endl;
	cout<<"2"<<endl;
	goto xx;   //如果有 goto 后面的标记，跳转到标记处   标记可以是字母，字符串  
	cout<<"3"<<endl;
	cout<<"4"<<endl;
	xx:
	cout<<"5"<<endl; 
	 
	system("pause");
	return 0;
} 

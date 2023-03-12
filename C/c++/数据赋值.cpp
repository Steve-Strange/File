#include<iostream>  
#include<string>
using namespace std;

int main(){
	
	long a=0;  //用int short float doulbe char string bool 等都可以 
	cout<<"请给变量a赋值"<<endl;
	cin>>a;
	cout<<"整形变量a="<<a<<endl; 
	
	bool x;
	cout<<"请给bool类型变量x赋值"<<endl;  //只要非0的数字 都是真 都输出1   不识别字母  输入字母都是0 
	cin>>x;
	cout<<"bool类型变量x="<<x<<endl;

	system("pause");
	
	return 0;
} 

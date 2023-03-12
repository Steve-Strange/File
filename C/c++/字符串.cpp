#include<iostream>
#include<string>  //使用string 需在开头声明  
using namespace std;

int main(){
	
	char x[]="hello world";  //双引号表示字符串   注意[]   x[字符串长度] ="字符串"   字符串长度可以省略。  
	cout<<x<<endl; 
	
	string y= "goodbye world";
	cout<<y<<endl<<sizeof(y)<<endl;
		
	system("pause");
	
	return 0;
} 

#include<iostream>
using namespace std;

int main(){

	int a=10;  //数字除了0都为真  非数字和0 都为假
	cout<<!a<<endl<<!!a<<endl;   //! 非  
	// && 与  ||或 
	int b=5,c=0;
	cout<<(b&&c)<<endl<<(b||c)<<endl<<(b&&!c)<<endl<<(b>c)<<endl<<(b==c)<<endl;
	
	system("pause");
	return 0;
}

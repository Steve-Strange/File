#include<iostream>
using namespace std;
int main(){
	int a,b,c; 
	cout<<"请输入A的体重"<<endl;
	cin >>a;
	cout<<"请输入B的体重"<<endl;
	cin >>b;
	cout<<"请输入C的体重"<<endl;
	cin >>c;
	if (a>b){
		if(a>c){
			cout<<"A最重"<<endl; 
		}
		else if (a==c){
			cout<<"A,C最重"<<endl;
		}
		else {
			cout<<"C最重"<<endl; 
		}
	}
	else if (a==b){
		if(a>c){
			cout<<"A,B最重"<<endl; 
		}
		else if (a==c){
			cout<<"A,B,C一样重"<<endl;
		}
		else {
			cout<<"C最重"<<endl; 
		}
	}
	else {
		if(b>c){
			cout<<"B最重"<<endl; 
		}
		else if (b==c){
			cout<<"B,C最重"<<endl;
		}
		else {
			cout<<"C最重"<<endl; 
		}
	}
system("pause");
return 0;
}

















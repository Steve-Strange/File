#include<iostream>
using namespace std;
int main(){
	int a,b,c; 
	cout<<"������A������"<<endl;
	cin >>a;
	cout<<"������B������"<<endl;
	cin >>b;
	cout<<"������C������"<<endl;
	cin >>c;
	if (a>b){
		if(a>c){
			cout<<"A����"<<endl; 
		}
		else if (a==c){
			cout<<"A,C����"<<endl;
		}
		else {
			cout<<"C����"<<endl; 
		}
	}
	else if (a==b){
		if(a>c){
			cout<<"A,B����"<<endl; 
		}
		else if (a==c){
			cout<<"A,B,Cһ����"<<endl;
		}
		else {
			cout<<"C����"<<endl; 
		}
	}
	else {
		if(b>c){
			cout<<"B����"<<endl; 
		}
		else if (b==c){
			cout<<"B,C����"<<endl;
		}
		else {
			cout<<"C����"<<endl; 
		}
	}
system("pause");
return 0;
}

















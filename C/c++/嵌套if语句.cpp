#include<iostream>
using namespace std;

int main(){

	int a=0; 
	cout<<"������һ������"<<endl;
	cin>>a;  //���û���ֵ ��a  ">>"  �������� 
	
	if (a>600)   //if���治Ҫ�ӷֺ�   
	{
		if(a>700){
			cout<<"�山"<<endl;
		}
		else if (a>650){
			cout<<"�˴�"<<endl;
		}
		else {
			cout<<"����"<<endl;
		}
	 } 
	else if (a>500){
		cout<<"����"<<endl;
	} 
	else {
		cout<<"ûѧ��"<<endl;
	}
	system("pause");
	return 0;
} 

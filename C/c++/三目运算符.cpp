//��Ŀ����� 
// ���ʽ1 �� ���ʽ2 �����ʽ3��
//���1�棬ִ��2  ���1�٣�ִ��3 

//��������

#include<iostream>  
using namespace std;

int main(){
	
	int a,b,c,d;
	cin>>a;
	cin>>b;
	a>b ? c=a : c=b; 
	(a>b ? a : b)=100; //Ҳ��ֱ�ӷ��ر�������ֵ 
	cout<<c<<endl<<a<<endl<<b<<endl; 
		
	system("pause");
	
	return 0;
}  

#include<iostream>
using namespace std;

//����������:��ǰ��֪�����к����Ķ���
//��������д��Σ�����ֻ��һ�Ρ� 

int max(int a,int b);   //������� ע���� ; 


int main(){
	int a,b;
	cin>>a;
	cin>>b;
	cout<<max(a,b)<<endl;

	system("pause");
	
	return 0;
} 

int max(int a,int b)     //���������ں��棬�����ǰ��֪�� 
{
	return a>b ? a : b; 
 } 


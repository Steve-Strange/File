#include<iostream>  
using namespace std;

int main(){

	int a=5,b=9;  // int �� integer  ������ֵ����, 
	// �������� + - * / 
	cout<<a+b<<endl<<a-b<<endl<<a*b<<endl<<a/b<<endl;  //�������� ����ֻ�����������

	float c=1.3 ,d=2.4;
	cout<<c/d<<endl;  //��������С�����������Ҳ��С�� 
	
	//ȡģ���㣬�������  С�����ɽ���ȡģ���� 
	cout<<b%a<<endl; 
	
	/*
	ǰ�õ��� ++a a=a+1  �Ƚ���+1 ���������   (ֱ�Ӹı�a��ֵ) 
	���õ��� a++ a=a+1  �Ȳ������� �����+1 
	*/
	int e=10,f=++e*10;
	cout<<e<<endl<<f<<endl;
	
	int g=10,h=g++*10;
	cout<<g<<endl<<h<<endl;
	
	int x=1;
	++x;   //Ҳ��ֱ����Ϊһ��ָ�� 
	cout<<x<<endl;
	
	/*
	ǰ�õݼ����õݼ�ͬ������ 
	 */
	
	system("pause");
	
	return 0;
} 

#include<iostream>
using namespace std;

int main(){

	int a=0; 
	cout<<"������һ������"<<endl;
	cin>>a;  //���û���ֵ ��a  ">>"  �������� 
	
	if (a>600)   //if���治Ҫ�ӷֺ�   
	{
		cout<<"����һ��"<<endl;
	 } 
	
	else if (500<a)  //��һ���������������£��ж�����Ƿ����  ������ֱ����������if�ṹ  ����else���� 
	{
		cout<<"���϶���"<<endl;
	}
	
	else if (a>400) {
		cout <<"��������"<<endl;
	}
	else {  //ǰ��������������������ǰ���£���� 
		cout<<"��ûѧ����"<<endl;
	}
	system("pause");
	return 0;
} 

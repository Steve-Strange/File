#include<iostream>
using namespace std;

int main(){
	//switch ���
	//����Ӱ���  �ּ������
	
	int a=0;
	cout<<"����"<<endl;
	cin>>a; 
	switch(a)   //������ֻ�ܷ����������ַ��� 
	{
		case 10:  //���Ϊ10�������   ��ע����ð�� 
			cout<<"��"<<endl;
			break;   //�˳�switch��֧     
		case 9: 
			cout<<"��"<<endl;
			break;   //�˳�switch��֧   
		case 8:
			cout<<"һ��"<<endl;
			break;
		case 7:
		cout<<"һ��"<<endl;
		break;
		default:   //������������������ʱִ�� 
		cout<<"����"<<endl; 
		break;  	
	}
	system("pause");
	return 0; 
} 

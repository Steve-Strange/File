#include<iostream>
#include<cstdlib> 
using namespace std;

int main(){
	//���0~9 ʮ������
	int a=0;
	do{
		cout<<a<<endl;
		a++; 
	}   
		while(a<10);   //do....while   ��䣬 ��while�ж���ֹ��  do while�Ƚ���һ��ѭ�������ж�while   while�����жϡ� 
	
	int b=1000;
	do{
		cout<<b<<endl;
		b++;
	} 
		while(b<20);  //�Ի����һ��1000 
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
int main(){
	for (int i=0; i<=100; i=i+1)
	{
		if (i/10==7||i%10==7||i%7==0)    //�����λ��ʮλΪ1  ����7�ı��������������   
		{
			cout<<"������"<<endl; 
		}
		else 
		{
			cout<<i<<endl;
		}
	}
	system("pause");
	return 0;
} 

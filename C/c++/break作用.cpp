#include<iostream>
using namespace std;
int main(){
	//break������      switch case default break��   forѭ��  break�˳�ѭ��   Ƕ��ѭ��  �˳��ڲ�ѭ�� 
	cout<<"��ѡ���Ѷȣ�1��2��3"<< endl;
	int a;
	cin>>a; 
	switch(a)
	{
		case 1:
			cout<<"��"<<endl;
			break;                 //����˳��ִ����ȥ 
		case 2:
			cout<<"��ͨ"<<endl;
			break;
		case 3:
			cout<<"����"<<endl;
			break ;
	}
	
	for (int i=0;i<10;i++) 
	{
		if (i==5)
		{
			break;  //��if ��һ������  ������˳��ڲ�ѭ�� 
		}
		cout<<i<<endl;
	}
	
	for  (int x=0; x<10;x++)
	{
		for (int y=0 ; y<10;y++){
			if (y==5)
			{
				break;
			 } 
			 cout<<". ";
		}
		cout<<""<<endl;
	}	
	
	
	
	
	system("pause");
	return 0;
}

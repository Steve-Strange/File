#include<iostream>
#include<cstdlib>
#include<ctime>    //����ϵͳʱ�� 
using namespace std;

int main(){
	//������ 
	int a=0;
	srand((unsigned int)time(NULL));  //�����������ӣ����õ�ǰʱ����������� 
	a=rand()%100+1;    //rand()% �Ͻ� ����0~99����������Ǹ������Ͻ�С1��  +1����1~100
	
	int x,n=0;
	while(n<=4){    //�������ѭ�����ܲ�5��   
	cout<<"����²������"<<endl; 
	cin >>x ;
		if (x>a){
			cout<<"����"<<endl;
		}
		if (x<a){
			cout<<"С��"<<endl;
		}
		if (x==a){
			cout<<"����"<<endl;
			break;   //����֮��ִ��������֣�ֱ���˳�ѭ�� 
		}
		n++;
	}

	
	system("pause");
	return 0;
}



#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

	struct contact{
		string name;
		string gender;
		int age;
		string number;
		string address;
	};

	struct addressbook{
		struct contact personarray[MAX];
		int size;
	};

void f0 (){
	cout<<"��ӭ�´�ʹ��"<<endl;
}

void f1(addressbook *x){
	if (x->size==MAX)
	{
		cout<<"ͨѶ¼�����޷����"<<endl;
		return;
	}
	else 
	{
	cout<<"����������"<<endl;
	string name;
	cin>>name;
	x->personarray[x->size].name=name;
	cout<<"�������Ա�"<<endl; 
	string gender;
	cin>>gender;
	x->personarray[x->size].gender=gender;
	cout<<"����������"<<endl;
	int age;
	cin>>age;
	x->personarray[x->size].age=age;
	cout<<"������绰"<<endl;
	string number;
	cin>>number;
	x->personarray[x->size].number=number;
	cout<<"������סַ"<<endl;
	string address;
	cin>>address;
	x->personarray[x->size].address=address;

	}
	}




int main()
{

	int f=0;
	contact y;
	addressbook abs;
	abs.size=0;
	

	string function[7]={"�����ϵ��","��ʾ��ϵ��","ɾ����ϵ��",
	"������ϵ��","�޸���ϵ��","�����ϵ��","�˳�ͨѶ¼"}; 
	for (int i=0;i<27;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	for (int k=0;k<7;k++)
	{
		cout<<"*****  "<<(k+1)%7<<"��"<<function[k]<<"  *****"<<endl;
	}
	for (int j=0;j<27;j++)
	{
		cout<<"*";
	}
	cout<<endl;

	cin>>f;
	switch(f)
	{
		case 1:
			f1(&personarray);
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		case 6:
		break; 
		case 0:
			f0();
		break;
		
	}

	
	
 } 

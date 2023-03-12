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
	cout<<"欢迎下次使用"<<endl;
}

void f1(addressbook *x){
	if (x->size==MAX)
	{
		cout<<"通讯录满，无法添加"<<endl;
		return;
	}
	else 
	{
	cout<<"请输入姓名"<<endl;
	string name;
	cin>>name;
	x->personarray[x->size].name=name;
	cout<<"请输入性别"<<endl; 
	string gender;
	cin>>gender;
	x->personarray[x->size].gender=gender;
	cout<<"请输入年龄"<<endl;
	int age;
	cin>>age;
	x->personarray[x->size].age=age;
	cout<<"请输入电话"<<endl;
	string number;
	cin>>number;
	x->personarray[x->size].number=number;
	cout<<"请输入住址"<<endl;
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
	

	string function[7]={"添加联系人","显示联系人","删除联系人",
	"查找联系人","修改联系人","清空联系人","退出通讯录"}; 
	for (int i=0;i<27;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	for (int k=0;k<7;k++)
	{
		cout<<"*****  "<<(k+1)%7<<"、"<<function[k]<<"  *****"<<endl;
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

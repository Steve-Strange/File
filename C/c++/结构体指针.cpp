#include <iostream>
#include<string> 
using namespace std;

//�ṹ��ָ�� 



main(){
struct student
{
	string name;
	int age;
	int score;
}; 
struct student s={"a",18,100};
struct student*p=&s;  //����һ��ָ��Ԫ�أ�������ָ��s 
cout<<p->name<<"  "<<p->age<<"  " <<p->score<<endl;
//�� -> ������Ԫ�صĳ�Ա 


system("pause");
return 0;
}

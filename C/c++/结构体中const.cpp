#include<iostream>
using namespace std;

struct student
{
	string name;
	int age;
	int score;
}; 

void printstudent(const student *s)  //��ָ�����ʵ�Σ������Ƹ�������ʡ�ڴ� 
{               //�ں�����������const����  ��ֹ�ں����ڱ��޸� 
	cout<<s->name<<"  "<<s->age<<"  "<<s->score<<endl;
}

int main(){
	struct student s={"zhang",15,70};
	printstudent(&s); 
	
	system("pause");
	return 0;
};

#include <iostream>
#include<string> 
using namespace std;

//�������ͣ�   struct ������������  {��Ա1;��Ա2};
struct Student
{
	string name;
	int age;
	int score;
}s3,s4;   //ֱ���ڶ���������� 

int main()
{

//������������Ԫ�أ�  struct Student s1;   struct Student s2={}
	
	struct Student s1;   //��������ʱ����ʡ��struct 
	s1.name="wang" ;
	s1.age=17;
	s1.score=100;   //��������Ա��ֵ 
	cout<<s1.name<<"\n"<<s1.age<<"\n"<<s1.score<<"\n";
	
	struct Student s2={"zhang",18, 100};   //Ҳ����һ���� 


system("pause");
return 0;

}

#include <iostream>
#include<string> 
using namespace std;

//数据类型：   struct 数据类型名称  {成员1;成员2};
struct Student
{
	string name;
	int age;
	int score;
}s3,s4;   //直接在定义这儿创建 

int main()
{

//创建数据类型元素：  struct Student s1;   struct Student s2={}
	
	struct Student s1;   //创建变量时可以省略struct 
	s1.name="wang" ;
	s1.age=17;
	s1.score=100;   //给各个成员赋值 
	cout<<s1.name<<"\n"<<s1.age<<"\n"<<s1.score<<"\n";
	
	struct Student s2={"zhang",18, 100};   //也可以一起来 


system("pause");
return 0;

}

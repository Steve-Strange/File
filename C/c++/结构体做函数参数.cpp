#include <iostream>
#include<string> 
using namespace std;

//结构体做函数参数 
//用函数输出一个参数   值传递、地址传递 

struct student
{
	string name;
	int age;
	int score;
};


void printstudent(struct student s)
{
	cout<<s.name<<"  "<<s.age<<"  "<<s.score<<endl; 
}

void printstudent2(struct student *p)
{
	cout<<p->name<<"  "<<p->age<<"  "<<p->score<<endl;
 } 

main(){
struct student s={"a",18,100};
struct student *p;
p=&s;

printstudent(s);
printstudent2(p);
system("pause");
return 0;
}

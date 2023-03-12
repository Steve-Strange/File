#include<iostream>
using namespace std;

struct student
{
	string name;
	int age;
	int score;
}; 

void printstudent(const student *s)  //用指针接收实参，不复制副本，节省内存 
{               //在函数变量处用const修饰  防止在函数内被修改 
	cout<<s->name<<"  "<<s->age<<"  "<<s->score<<endl;
}

int main(){
	struct student s={"zhang",15,70};
	printstudent(&s); 
	
	system("pause");
	return 0;
};

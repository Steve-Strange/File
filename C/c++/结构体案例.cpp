#include<iostream>
using namespace std;
#include<string>
#include<ctime>
#include <stdlib.h>

struct student
{
	string sname;
	int score;
};

struct teacher
{
	string tname;
	struct student s[5];
 } ;
 
 void inputinfo(struct teacher t[],int len)
 {
 	string nameseed="ABCDE";
 	int i=0;
 	for (int i=0;i<len;i++)
 	{
 		t[i].tname ="teacher_";
 		t[i].tname+=nameseed[i];
	 
	 	for (int j=0;j<5;j++)
	 	{
	 		t[i].s[j].sname="student_";
	 		t[i].s[j].sname+=nameseed[j];
	 	int random=rand()%61+40;  //����� 40~100   %61�� 0~60 
	 		t[i].s[j].score=random;
		 }
	}	
 }
 
 void printinfo(struct teacher t[],int len)
 {
 	for (int i=0;i<len;i++)
 	{
 		cout<<"��ʦ����:"<<t[i].tname<<endl;
 		for (int j=0;j<5;j++)
 		{
 			cout<<"\tѧ������:"<<t[i].s[j].sname<<"  ���Է���"<<
			 t[i].s[j].score<<endl; 
		 }
	 }
 }
 
 int main(){
 	srand((unsigned int)time(NULL));   //���������  ��rand����������� 
 	
 	struct teacher t[3];
 
 	int len=sizeof(t)/sizeof(t[0]);
 	inputinfo(t,len);
	printinfo(t,len);
	system("pause");
	return 0; 	
 	}

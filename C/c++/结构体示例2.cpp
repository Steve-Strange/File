#include<iostream>
#include<string>
using namespace std;

struct hero{
	string name;
	string gender;
	int age;
};


int main(){
	int i,j,k,x;
	string m,n; 
	struct hero arr[5]={{"a","male",23},{"b","male",22},
	{"c","male",20},{"d","male",21},{"e","female",19}};
	for (i=0;i<5;i++){
		for (j=0;j<4-i;j++){
			if (arr[j+1].age<arr[j].age){
				struct hero temp;
				temp=arr[j];   //数组元素可直接整体赋值 
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for (x=0;x<5;x++){
		cout<<arr[x].name<<"  "<<arr[x].gender<<"  "<<arr[x].age<<endl;
	}
	system("pause");
	return 0;
}

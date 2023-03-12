#include<iostream>
#include<cstdlib>
#include<ctime>    //加入系统时间 
using namespace std;

int main(){
	//猜数字 
	int a=0;
	srand((unsigned int)time(NULL));  //添加随机数种子，利用当前时间生成随机数 
	a=rand()%100+1;    //rand()% 上界 生成0~99的随机数（非负，比上界小1）  +1后变成1~100
	
	int x,n=0;
	while(n<=4){    //构建多次循环，能猜5次   
	cout<<"输入猜测的数字"<<endl; 
	cin >>x ;
		if (x>a){
			cout<<"大了"<<endl;
		}
		if (x<a){
			cout<<"小了"<<endl;
		}
		if (x==a){
			cout<<"对了"<<endl;
			break;   //对了之后执行这个部分，直接退出循环 
		}
		n++;
	}

	
	system("pause");
	return 0;
}



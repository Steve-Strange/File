#include<stdio.h>
int main()
{
	//16进制的一位可以直接对应为2进制的四位，使得人脑进制转换非常方便
	unsigned int a = 0xff000000; //11111111 00000000 00000000 00000000
	unsigned int b = 0x00ff0000; //00000000 11111111 00000000 00000000
	unsigned int c = 0x0000ff00; //00000000 00000000 11111111 00000000
	unsigned int d = 0x000000ff; //00000000 00000000 00000000 11111111
	//低n位为1
	int n=13;
	unsigned int e = (1 << n) - 1; //00000000 00000000 00011111 11111111
	//低[l,r]位为1，其余为0
	int l=5,r=15;
	unsigned int f = ((1<<(l-1))-1) ^ ((1<<r)-1);
	//00000000 00000000 01111111 11110000
}

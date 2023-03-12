#include<stdio.h>
#include<string.h>
int arr[500005];

int lower_bound(int key, int l, int h) 
{
	int mid;
	if(l==h)
	{
//		if(xxx) return -1;
//		else return l;
	}
	mid = (l + h)/2;
	if(key<=arr[mid])
	return lower_bound(key, l, mid);
	if(key>arr[mid])
	return lower_bound(key, mid+1, h);
}

int upper_bound(int key, int l, int h) 
{
	int mid;
	if(l==h)
	{
//		if(xxx) return -1;
//		else return l;
	}
	mid = (l + h)/2;
	if(key<arr[mid])
	return upper_bound(key, l, mid);
	if(key>=arr[mid])
	return upper_bound(key, mid+1, h);
}


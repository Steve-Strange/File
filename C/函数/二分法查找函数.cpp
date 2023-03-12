#include<stdio.h>
// binary find
int rec_bin_find(int b[], int key, int low, int high) 
{
	int mid;
	if( low > high ) return -1;
	mid = (low + high)/2; 
	if( key == b[mid] ) 
	return mid;
	else if( key < b[mid]) 
	return rec_bin_find(b, key, low, mid-1);
	else 
	return rec_bin_find(b, key, mid+1, high);
}




// non-recursive version
int bin_find(int b[], int key, int low, int high) 
{
	int mid; while( low <= high ) 
	{
	mid = (low + high)/2; 
	if( key == b[mid] ) 
	return mid;
	else if (key < b[mid]) high = mid-1;
	else low = mid+1;
	}
	return -1;
}

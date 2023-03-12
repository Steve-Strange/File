#include<stdio.h>
#include<math.h>
#include<string.h>

void replace(char originalString[], char key[], char swap[]){

int lengthOfOriginalString, lengthOfKey, lengthOfSwap, i, j , flag;

char tmp[1000]; 

lengthOfOriginalString = strlen(originalString);

lengthOfKey = strlen(key);

lengthOfSwap = strlen(swap);

for( i = 0; i <= lengthOfOriginalString - lengthOfKey; i++){

flag = 1;

for(j  = 0; j < lengthOfKey; j ++){

if(originalString[i + j] != key[j]){

flag = 0; 

break;

}

}

if(flag){

strcpy(tmp, originalString);

strcpy(&tmp[i], swap);

strcpy(&tmp[i + lengthOfSwap], &originalString[i  + lengthOfKey]);

strcpy(originalString, tmp);

i += lengthOfSwap - 1;

lengthOfOriginalString = strlen(originalString);

}

}

}

int main()
{
		char key[] = {"Ä¿±ê"};
		char swap[] = {"Ìæ²¹"}; 
		replace(//×Ö·û´®, key, swap);
		printf("%s\n",x);
	return 0;
}

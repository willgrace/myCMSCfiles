//number 4

#include <stdio.h>
#define n 5

main(){

int a, num, neg=0, pos=0;

	for(a=0;a<n;a++){
	printf("Enter num except zero:");
	scanf("%d", &num);
	
		if(num<0)
			neg=neg+1;
		else
			pos=pos+1;

	}
	
	if(neg>pos)
		printf("there are more negative numbers\n");
	else
		printf("there are more positive numbers\n");



}

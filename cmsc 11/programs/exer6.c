#include <stdio.h>
#define n 10

main(){

int a, b, num;

printf("Entern num:");
scanf("%d", &num);

	for(a=0;a<num;a++){
		for(b=0;b<num;b++){
			if(a<=b)
				printf("*");
		
			else
				printf(".");		
		}
	printf("\n");
	
	
	}
	





}

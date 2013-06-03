#include <stdio.h>

main()
{
	int intj, inti, intn;
	
	do{
	printf("Enter a number (greater than 1): ");
	scanf("%d", &intn);
	
	} while(intn<1);{
		
		for(intj=intn;intj>0;intj--){
			
			for(inti=0;inti<intj+1;inti++){
				printf("x");	
			
			}
		}
		putchar('\n');
	}	
}		

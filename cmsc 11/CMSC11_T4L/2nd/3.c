#include <stdio.h>

main()
{
	int intj, inti, intn;
	
	do{
	printf("Enter a number (greater than 1): ");
	scanf("%d", &intn);
	
	} while(intn<1);{
		for(intj=0; intj<intn-1; intj++){
			for(inti=0; inti<intj+1; inti++){
				printf("x");
			}
			printf("\n");
		}	
		for(intj=intn;intj>0;intj--){
			
			for(inti=0;inti<intj;inti++){
				printf("x");
			}
		printf("\n");		
		}	
	}	
}		

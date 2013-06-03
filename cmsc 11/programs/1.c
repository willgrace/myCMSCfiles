#include <stdio.h>

main()
{
	int inta, intb, intc;
	
	printf("enter 3 positive numbers: ");
	scanf("%d %d %d", &inta, &intb, &intc);
	
	if(inta>intb && inta>intc){
		if(intb>intc){
			printf("\nthe numbers are %d, %d, and %d.\n", intc, intb, inta);
		}
		else{
			printf("\nthe numbers are %d, %d, and %d.\n", intb, intc, inta);
		}
	}
	else{
		if(intb>inta && intb>intc){
			if(inta>intc){
				printf("\nthe numbers are %d, %d, and %d.\n", intc, inta, intb);
			}
			else{
				printf("\nthe numbers are %d, %d, and %d.\n", inta, intc, intb);
			}
		}
		else{
			if(inta>intb){
				printf("\nthe numbers are %d, %d, and %d.\n", intb, inta, intc);
			}
			else{
				printf("\nthe numbers are %d, %d, and %d.\n", inta, intb, intc);
			}
		}
	}
}		

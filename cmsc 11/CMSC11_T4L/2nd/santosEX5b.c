/*Graycel Santos T-4L*/

#include <stdio.h>

main()
{
	int choice;
	int inta, intb, intc;							//varialbe for number 1
	int intj, inti, intn;								//varialbe for number 3
	char chartemp;								
	float intTEMP, intF, intC;							//varialbe for number 2
	
	do{
	
	printf("\n[1] Increasing order of numbers\n");
	printf("[2] Temperature converter\n");
	printf("[3] Isosceles triangle\n");
	printf("[4] Exit\n");
	printf("\nEnter the number of your choice: ");
	scanf("%d", &choice);
	
		switch(choice){
			case 1:	printf("\nEnter 3 positive numbers: ");							//case 1: Nested if-else
					scanf("%d %d %d", &inta, &intb, &intc);						//error if they dont enter 3 numbers
	
					if(inta>intb && inta>intc){								//first condition, if a is greater than b & c
						if(intb>intc){
							printf("\nthe numbers are %d, %d, and %d.\n\n", intc, intb, inta);
						}
						else{
							printf("\nthe numbers are %d, %d, and %d.\n\n", intb, intc, inta);
						}
					}
					else{
						if(intb>inta && intb>intc){								//2nd condition, if b is greater than a & c
							if(inta>intc){
								printf("\nthe numbers are %d, %d, and %d.\n\n", intc, inta, intb);
							}
							else{
								printf("\nthe numbers are %d, %d, and %d.\n\n", inta, intc, intb);
							}
						}
						else{
							if(inta>intb){								//3rd conditon, if c is greater than a & b
								printf("\nthe numbers are %d, %d, and %d.\n\n", intb, inta, intc);
							}
							else{
								printf("\nthe numbers are %d, %d, and %d.\n\n", inta, intb, intc);
							}
						}
					}
				break;
			case 2:	printf("\nEnter the current temperature in the room (include F or C): ");		//case 2: Temperature converter
				scanf("%f %c", &intTEMP, &chartemp);					//error if F or C were not entered with the temp
	
				if(chartemp=='C'){
					intF=(intTEMP*9.0/5.0)+32.0;					//formula for Farenheit
						printf("\nThe current temperature in your room is %.1f F\n\n", intF);
				}
				else{
					if(chartemp=='F'){
						intC=((intTEMP-32.0)*5.0)/9.0;				//formula for Celcius
							printf("\nThe current temperature in your room is %.1f C\n\n", intC);
					}
				}
				break;
			case 3:	do{
					printf("\nEnter a number (greater than 1): ");				//case 3: Iso Tringle
					scanf("%d", &intn);						//input will loop if its less than one
	
					} while(intn<1);{
						for(intj=0; intj<intn-1; intj++){				//right triangle
							for(inti=0; inti<intj+1; inti++){
								printf("x");
							}
							printf("\n");
						}	
						for(intj=intn;intj>0;intj--){					//inverted right triangle
			
							for(inti=0;inti<intj;inti++){
								printf("x");
							}
							printf("\n");		
						}	
					}
				break;
			case 4: printf("\nThank you and Goodbye!\n");					//case 4: exit and farewell output
				break;
		default: printf("\nSorry, invalid input. There is no such choice!\n\n");				//invalid input corrector; use can enter 1 to 4 numbers only
		}
	
	} while(choice!=4);										//end of loop if choice is number 4
		
}

/*End of exer 5b*/

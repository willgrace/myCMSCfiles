#include<stdio.h>

main()
{
	int intx, inty, intz;

	printf("enter three numbers: ");
	scanf("%d %d %d", &intx, &inty, &intz);

	if((intx<inty)&&(intx<intz)){
		if(inty>intz){
			printf("the numbers you entered are %d, %d and %d \n", intx, intz, inty);
		}
		else{
			printf("the numbers you entered are %d, %d and %d \n", intx, inty, intz);
		}
	}
	else{
		if((intz<inty)&&(intz<intx)){
			if(inty>intx){
				printf("the numbers you entered are %d, %d and %d \n", intz, intx, inty);
			}
			else{
				printf("the numbers you entered are %d, %d and %d \n", intz, inty, intx);
			}
		}
		else{
			if(intz>intx){
				printf("the numbers you entered are %d, %d and %d \n", inty, intx, intz);
			}
			else{
				printf("the numbers you entered are %d, %d and %d \n", inty, intz, intx);
			}
		}
	}
}

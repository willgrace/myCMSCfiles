/*assuming the numbers are not equal*/
#include<stdio.h>

main()
{
	int intx, inty;

	printf("enter two numbers separated by space: ");
	scanf("%d %d", &intx, &inty);

	if(intx>inty){
		printf("the numbers you entered from lowest to highest are %d and %d \n", inty, intx);
	}
	else{
		printf("the numbers you entered from lowest to highest are %d and %d \n", intx, inty);
	}
}

#include <stdio.h>

main(){

int num;
printf("Enter number:");
scanf("%d", &num);

	while(num>=0){
	printf("%d", num%2);
	num=num-(num/2);
	}

}


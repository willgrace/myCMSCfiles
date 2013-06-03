/*Tibay, Nicole I.
CMSC 21 UV-3L
Description: Converting Decimal to Binary
*/

#include <stdio.h>

main(){

int x, num, y=0,b=0,t=1, bin=0;
printf("Enter number:");
scanf("%d", &num);

/*while(num>0){
	x=num%2;
	num=num/2;
	printf("%d", x);


}

printf("\n");
*/
	while(num>0){
		x=num%2;	
		b=x*t;
		num=num/2;
		t=t*10;
		bin=bin+b;
		
}
	printf("%d\n", bin);

}

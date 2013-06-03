#include <stdio.h>
#define pi 3.14159
main()
{
	char charName[15];
	char charMI='A';
	int intX, intY=10, intZ=10.5;
	float floatNum1=100.25;
	double doubleNum1=10.432432;
	
	printf("Enter 2 numbers (separated by space): ");
	scanf("%d %d", &intX, &intY);
	printf("intX=%d intY=%d intZ=%d", intX, intY, intZ);
	
	getchar();
	printf("\n\nEnter your firstname: ");
	scanf("%s", charName);
	printf("charName=%s charMI=%c", charName, charMI);
	
	printf("\n\ndoubleNum1=%lf floatNum1=%f", doubleNum1, floatNum1);
	printf("\npi = %f", pi);    
}
/*end of program*/

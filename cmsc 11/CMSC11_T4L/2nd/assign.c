#include <stdio.h>
#define pi 3.14159
main()
{
	char charName;
	char charMI='A';
	int intX, intY=10, intZ=10.5;
	float floatNum1=100.25;
	double doubleNum1=10.432432;

	printf("Enter 2 numbers (separated by space) : ");
	scanf("%d %d", &intX, &intY);
	printf("intX=%d intY=%d int Z=%d", intX, intY, intZ);

	getchar();
	printf("\n\nEnter your firstname: ");
	scanf("%c", &charName);
	printf("charName=%c charMI=%c", charName, charMI);

	printf("\n\ndoubleNum1=%1f floatNum1=%f", doubleNum1, floatNum1);
	printf("\npi = %f", pi);
}
/*end of program*/

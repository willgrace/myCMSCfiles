#define y 0.03937
#include <stdio.h>
main()
{
	char name[50];
	float x, z;
	
	printf("Irrashaimase!! (Welcome!) \n");
	printf("What is your first name? ");
	scanf("%s", name);
	printf("\nOh, hi %s! Nice to meet you!", name);
	printf("\nNow, um, how tall are you in cm? ");
	scanf("%f", &x);
	z=x*y;
	printf("Oh, so you are %f in inches\n", z);
	
	printf("\nJa, matashita ne!\n\n");    
}

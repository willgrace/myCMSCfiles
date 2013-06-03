#include <stdio.h>

void doStuff(int *val);

int main()
{
	int x = 5;
	
	printf("x = %d\n", x);
	doStuff(&x);
	printf("After function");
	printf("x = %d\n", x);
	return 0;
}

void doStuff(int *val)
{
	*val = 3;
}

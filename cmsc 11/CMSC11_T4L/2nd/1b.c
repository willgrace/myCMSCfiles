#include <stdio.h>

/* Implementation of a program without function prototype */
/* This function computes the double of a number */

int computeTwice (int intNum)
{
	int intResult = intNum * 2;
	return intResult;
}

main( )
	{
	int intNum = 13;
	int intA = 1;
	int intB = 2;
	intA = computeTwice(intA);
	intB = computeTwice(intB + intNum);
}

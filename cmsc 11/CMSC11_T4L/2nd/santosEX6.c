/*Graycel Santos, T-4L*/

#include <stdio.h>

int isPrime(int x){
	
	int j;
		for(j=2;j<=x-1;j++){
		if(x%j==0) return 0; 	//Number is divisble by some other number. So break out
		if(x-1==j) return 1; 		//Number was divisible by itself (that is, i was same as j)
	
	}

}

void printAllPrimes(int n){
	
	int j;
	
	printf("These are the numbers bet 2 to %d\n", n);
	printf("2 ");
	
	for(j=2;j<=n;j++)
	{

		if(isPrime(j)==1) printf("%d ", j); 		//Number was divisible by itself (that is, i was same as j)
	
	}
}

main()
{
	int n;
	
	printf("Enter an integer: ");
	scanf("%d", &n);
	printAllPrimes(n);

} 


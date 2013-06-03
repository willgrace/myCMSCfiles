/*Graycel Santos, T-4L*/

#include <stdio.h>
#include <string.h>

main( )
{
	 
	char orig[20];							
	char rev[20];
	int i,j,x;
	
	printf("\nPalindrome identifier\n");
	printf("Enter any word: ");
	scanf("%s", orig);						//original word input from the user
	
	x = strlen(orig);						//length of the original word assigned to x
	
	for(i=x-1,j=0; i>=0,j<=x-1; i--,j++){		//loop to reverse the origanal word
			rev[i] = orig[j];	
		
	}
	strcat(rev,"\0");
	
		rev[x]=orig[x];				
			putchar('\n');
		
			printf("%s", rev);						//print reverse word
				if(strcmp(orig,rev)==0){			//compare if the reverse is equal to the original word
					printf("\nGreat! it's a palindrome!\n\n");
					}
				else{
					printf("\nI'm sorry, but it is not a palindrome\n\n");
					}
}
// end of program

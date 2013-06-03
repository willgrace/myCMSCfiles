/*Kristela Mae-Joy R. Valentin UV-4L Exercise 3 July 10,2010*/
#include <stdio.h>

int prime(int a);
int evenodd(int c);

main(){
int a,c,choice;

printf("\t============================================\n");
printf("\t|  [1] Identify if a number is prime.      |\n");
printf("\t|  [2] Identify if number is odd or even.  |\n");
printf("\t|  [3] Exit                                |\n");
printf("\t============================================\n");
scanf("%d", &choice);


switch(choice){
	case 1:	{
		printf("Enter a positive integer number: ");
		scanf("%d", &a);
		if (prime(a)==1)
		     printf("PRIME NUMBER\n");	
		else
		     printf("COMPOSITE, NOT A PRIME NUMBER.\n");
		}
		break;

	case 2:{
		printf("Enter a positive integer number: ");
		scanf("%d", &c);
		if(evenodd(c)==0)		
		    printf("EVEN\n");
		else if(evenodd(c)==1)
		    printf("ODD\n");
		else if(evenodd(c)==2) 
		    printf("you've entered a non positive integer number.\n");
		}
		break;
	default: printf("----end----\n");		

}
}

int prime(int a){
	int b,ans;
		for(b=2; b<a-1; b++)
	{
		ans=a%b;
		if(ans==0)
		 return 0;
	}
		     	
	  return 1;	
}


int evenodd(int c){
	int ans;
		ans=c%2;	
		if(ans==0)		
			return 0;			

		else if(ans<=0)
			return 2;		
		else 
			return 1;
}

#include<stdio.h>  
main()  
{  
int number;  
int prime(int number);  
int primefactor(int number);  
printf("Enter the number whose prime factors are to be calculated:");  
scanf ("%d", &number);  
primefactor(number);  
}  
  
//The following is the function that detects a Prime number.  
  
prime(int num)  
{  
int i, ifprime;  
for (i=2; i<=num-1; i++)   
{   
if (num%i==0)   
{   
ifprime=0;   
}   
else   
ifprime=1;  
}  
return   
(ifprime);   
}   //The following function prints the prime factors of a number.    
   
primefactor(int num)   
{   
int factor,  
ifprime;   
for (factor=2; factor<=num;)   
{ prime(factor);   
//so that the factors are only prime and nothing else.   
if (ifprime)   
{ if (num%factor==0) //diving by all the prime numbers less than the number itself.   
{   
printf("%d ", factor);   
num=num/factor; continue;   
}   
else   
{ factor++;//this cannot be made a part of the for loop   
}   
}   
}   
return 0;   
}      

// Kristela Mae-Joy R. Valentin CMSC 11 t-3L 
// This function compares two strings.

#include <stdio.h>
#include <string.h>
int compare2strings(char a[],char b[]){
int x,y,i=0;
x=strlen(a); y=strlen(b);

	if(x<y)
	return -1; //-1 will be printed when the numer of character x is less than y
	else if(x>y)
	return 1; // 1 will be printed when the number of character x is greater than y
	else if(x==y){
	while(a[i]!='\0'){
	if(a[i]!=b[i])
	return 2; //2 will be printed when x and y have the same number of characters but do not have the same content
	i++;
		}
	}
	return 0; // 0 will be printed when x and y are equal
}

main(){
char a[10], b[10];
int x;
	printf("Enter a word:\n"); // the entered word will serve as the first string
	scanf("%s",a);
	printf("Enter another word:\n"); // This entered word will serve as the second string
	scanf("%s",b);
	x=compare2strings(a,b);
	printf("%d\n",x); // Depending upon the result of the comparison of the two strings, it is either -1,0,1, or 2 will be printed
}

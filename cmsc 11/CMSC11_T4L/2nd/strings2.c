#include <stdio.h>
#include <string.h>

main( )
{
	char name1[12],name2[12],mixed[25];
	char title[20];
	
	printf("enter your name: ");
	scanf("%s", name1);
	getchar();
	
	printf("enter another name: ");
	gets(name2);
	
	strcpy(title,"This is the title.");
	
	printf(" %s\n\n",title);
	printf("Name 1 is %s\n",name1);
	printf("Name 2 is %s\n",name2);
	
	if(strcmp(name1,name2)>0) /* return 1 if name1 > name2; -1 if name1 < name2 */
		strcpy(mixed,name1);
	else
		strcpy(mixed,name2);
	
	printf("The biggest name alphabetically is %s\n",mixed);
	strcpy(mixed,name1);
	strcat(mixed," ");
	strcat(mixed,name2);
	printf("Both names are %s\n",mixed);
}
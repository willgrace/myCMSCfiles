#include <stdio.h>
#define N 10

countvotes( int votes[], int counts[] )
{	
	int i;
	for(i=0;i<N;i++)
	{
		if (votes[i]==0) counts[0]=counts[0]+1;
		if (votes[i]==1) counts[1]=counts[1]+1;
		if (votes[i]==2) counts[2]=counts[2]+1;
	}
}
printresults( int counts[], char* candidates[])
{
	int i;
	for(i=0; i<3; i++)
	{
	printf(" %s has %d votes, ", candidates[i], counts[i]);
	}
		if(counts[0]>counts[1])
		{
			if(counts[0]>counts[2])
			{
				printf("the winner is %s", candidates[0]);
			}
			else{
				if(counts[0]==counts[2])
				{
					printf("the winner is %s %s", candidates[0], candidates[2]);
				}
				else{
					printf("the winner is %s", candidates[2]);
				}	
			}
		}
		else{
			if(counts[2]>counts[1])
			{
				printf("the winner is %s", candidates[2]);
			}
			else{
				if(counts[2]==counts[1])
				{
					printf("the winner is %s %s ", candidates[2], candidates[1]);
				}
					else{
						printf("the winner is %s", candidates[1]);}
				}
					
			}
}
                 
main()                  
{       
	int i; 
	int votes[N]={2,2,1,2,1,0,0,1,2,1};
    	char* candidates[3]={"ERAP", "FVR", "GMA"};
	int counts[3]={0,0,0};
	
	countvotes( votes, counts );
	printresults( counts, candidates);
}

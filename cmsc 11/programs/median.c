

#include <stdio.h>

int median(int x, int y, int z);

main(){
	int a[3], b[3], c[3], m[3], count, final;

	system("clear");
	
	printf("Finds the median of 9 numbers\n");
	printf("Input 9 numbers: ");
	for(count=0;count<3;count++){
		scanf("%d %d %d", &a[count] ,&b[count], &c[count]);
		m[count] = median(a[count] ,b[count] ,c[count]);
	}
	final = median(m[0], m[1], m[2]);
	
	
	printf("\n\nFor numbers: ");
	
	for(count=0;count<3;count++){	
		printf("%d %d %d ",a[count] ,b[count] ,c[count]);
	}
	putchar('\n');	
	printf("The median is \"%d\".\n", final);
}

int median( x, y, z ){	
	int med;
	if((y<=z)&&(y>=x)) med=y;
	else if((x<=z)&&(x>=y)) med=x;
	else if((z<=x)&&(z>=y)) med=z;
	
	return med;
	// nalito na.
}

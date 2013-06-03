/*password checking problem practice*/

# include <stdio.h>

main()
{
	int secret = 1990;
	int pass;
	int count = 0;

	do {
		printf("Enter your password: ");
		scanf("%d", &pass);
		count++;
	
	} while ((pass != secret) && (count < 6));

	if (pass == secret); {
		printf("Congratulation!\n");
	}
	else {
		printf("Sorrry!\n");
	}
}

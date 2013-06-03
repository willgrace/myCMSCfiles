#include <stdio.h>

#define NUM_STUDENTS 25
#define NUM_TESTS 10

int get_highest(int a[][NUM_TESTS], int row, int col)
/* Assumes that there is at least one element */
{
   int i, j;
   int highest = a[0][0];

   for( i = 0; i < row; i++)
      for( j = 0; j < col; j++)
         if ( a[i][j] > highest)
            highest = a[i][j];
   return highest;
}



int main()
{
   int grades[NUM_STUDENTS][NUM_TESTS] = { {55, 60, 65},
                                           {85, 90, 95} };
   int num_students = 2;
   int num_tests = 3;
   int high_test;
   
   high_test = get_highest( grades, num_students, num_tests);

   printf("The highest score is %d.\n", high_test);
   return 0;
}



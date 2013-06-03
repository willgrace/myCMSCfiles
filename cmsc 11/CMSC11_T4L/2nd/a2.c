#include <stdio.h>

#define NUM_STUDENTS1 25
#define NUM_TESTS1 10
#define NUM_STUDENTS2 15
#define NUM_TESTS2 8

int get_highest(int *a, int cols, int row, int col)
/* Assumes that the elements with usable values are
   in the upper left corner of the array as 
   delimited by row and col;
   cols is the number of columns in the array passed */
{
   int i, j;
   int highest = *a;

   for( i = 0; i < row; i++)
      for( j = 0; j < col; j++)
         if ( *(a + i*cols + j) > highest)
            highest = *(a + i*cols + j);
   return highest;
}

int main()
{
   int grades1[NUM_STUDENTS1][NUM_TESTS1] = { {55, 60, 65},
                                              {85, 90, 95} };
   int num_students1 = 2;
   int num_tests1 = 3;
   int high_test1;

   int grades2[NUM_STUDENTS2][NUM_TESTS2] = { {55, 60},
                                              {85, 90},
                                              {75, 70} };
   int num_students2 = 3;
   int num_tests2 = 2;
   int high_test2;
   
   high_test1 = 
      get_highest( (int *)grades1, NUM_TESTS1, num_students1, num_tests1);
   printf("The highest score in the first class is %d.\n", high_test1);

   high_test2 = 
      get_highest( (int *)grades2, NUM_TESTS2, num_students2, num_tests2);
   printf("The highest score in the second class is %d.\n", high_test2);

   return 0;
}




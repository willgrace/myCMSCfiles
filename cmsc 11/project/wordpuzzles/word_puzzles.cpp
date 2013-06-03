/* Word puzzles by Steven Ramponi*/


#include <time.h>
#include <iostream.h>
#include <string.h>
#include <conio.h>
#include "vga.h"
#include "Snake.h"
#include "line.h"


   int main()

   {

   int done=0, x, right=0, wrong=0, choose=1;


   char one[] = {"ski"};             char five[] = {"three"};
   char two[] = {"drwarf"};          char six[] = {"influence"};
   char three[] = {"metallica"};     char seven[] = {"hint"};
   char four[] = {"chevrolet"};      char eight[] = {"saunter"};
   char nine[] = {"obey"};           char ten[] = {"revise"};
   char eleven[] = {"pollen"};       char twelve[] = {"clear"};
   char thirteen[] = {"excel"};      char forteen[] = {"fifty"};
   char fifteen[] = {"pie"};         char sixteen[] = {"circuits"};
   char seventeen[] = {"car"};       char eighteen[] = {"plasma"};
   char nineteen[] = {"spar"};       char twenty[] = {"ship"};
   char twenty_one[] = {"saturn"};   char twenty_two[] = {"earth"};
   char twenty_three[] = {"windbreaker"}; char twenty_four[] = {"pawn"};
   char twenty_five[] = {"nerd"};    char twenty_six[] = {"carbon"};
   char twenty_seven[] = {"cranium"}; char twenty_eight[] = {"janitor"};
   char twenty_nine[] = {"zero"};     char thirty[] = {"factoid"};
   char thirty_one[] = {"sun"};       char thirty_two[] = {"hundred"};
   char thirty_three[] = {"integer"}; char thirty_four[] = {"virus"};
   char thirty_five[] = {"venus"};    char thirty_six[] = {"rogue"};
   char thirty_seven[] = {"war"};     char thirty_eight[] = {"orbs"};


   char pick[15];
   char buffer[15];

   char again, letter;


   VGAScreen();

   setborderc(56);

   cout << "\n   WORD PUZZLES by STEVEN RAMPONI\n";
   cout <<"\n\n\n\n\n      Hit spacebar to continue..\n";
   getch();
   key_tap();
   ship();

     for(int I = 0; I <= 400; I++) {
     buzz(1500); quiet();
     Fill_Screen(random(256));  }

   TextScreen();



   while (!done) {

   setborderc(1+rand() %256);

   clrscr();

   cout << "\n             Do not use capital letters in your answers..\n\n";

   cout << "\n RIGHT ANSWERS: " << right << endl;
   cout << "\n WRONG ANSWERS: " << wrong << "\n\n\n\n";


   switch (choose++) {

   case 1: x = strlen(one);
	   strcpy(pick, one);
	   cout << " What a person might like to do in the winter.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 2: x = strlen(two);
	   strcpy(pick, two);
	   cout << " A person smaller than average size.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 3: x = strlen(three);
	   strcpy(pick, three);
	   cout << " Most popular heavy metal band of the 90s.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 4:  x = strlen(four);
	   strcpy(pick, four);
	   cout << " Hot dogs, apple pie and ________\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 5:  x = strlen(five);
	   strcpy(pick, five);
	   cout << " The square root of nine. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


     case 6: x = strlen(six);
	   strcpy(pick, six);
	   cout << " That which tends to produce results by invisible means.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


     case 7: x = strlen(seven);
	   strcpy(pick, seven);
	   cout << " An indirect allusion or suggestion.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 8:  x = strlen(eight);
	   strcpy(pick, eight);
	   cout << " To wander about idly, stroll, loiter.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 9:  x = strlen(nine);
	   strcpy(pick, nine);
	   cout << " To do as bidden.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 10:  x = strlen(ten);
	   strcpy(pick, ten);
	   cout << " To review and correct.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 11: x = strlen(eleven);
	   strcpy(pick, eleven);
	   cout << " The fertilizing powder in the cell of a flower.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 12: x = strlen(twelve);
	   strcpy(pick, twelve);
	   cout << " Open space. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 13:  x = strlen(thirteen);
	   strcpy(pick, thirteen);
	   cout << " To surpass in good qualities. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 14:  x = strlen(forteen);
	   strcpy(pick, forteen);
	   cout << " Grant's face is shown on a______dollar bill. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 15:  x = strlen(fifteen);
	   strcpy(pick, fifteen);
	   cout << " 3.14 is also known as. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 16:  x = strlen(sixteen);
	   strcpy(pick, sixteen);
	   cout << " A number of transistors which work together in a computer. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 17:  x = strlen(seventeen);
	   strcpy(pick, seventeen);
	   cout << " Short for the word carriage. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 18:  x = strlen(eighteen);
	   strcpy(pick, eighteen);
	   cout << " Liquid part of blood. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 19:  x = strlen(nineteen);
	   strcpy(pick, nineteen);
	   cout << " Go a few rounds.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 20:  x = strlen(twenty);
	   strcpy(pick, twenty);
	   cout << " Ocean cruiser.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 21:  x = strlen(twenty_one);
	   strcpy(pick, twenty_one);
	   cout << " The sixth planet of our solar system.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 22:  x = strlen(twenty_two);
	   strcpy(pick, twenty_two);
	   cout << " The third planet of our solar system.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 23:  x = strlen(twenty_three);
	   strcpy(pick, twenty_three);
	   cout << " A cold weather jacket.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 24:  x = strlen(twenty_four);
	   strcpy(pick, twenty_four);
	   cout << " A chess piece that can only move forward.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 25:  x = strlen(twenty_five);
	   strcpy(pick, twenty_five);
	   cout << " Social misfit.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 26: x = strlen(twenty_six);
	   strcpy(pick, twenty_six);
	   cout << " An elementry substance found in organic compounds.\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 27:  x = strlen(twenty_seven);
	   strcpy(pick, twenty_seven);
	   cout << " Another name for SKULL. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 28:  x = strlen(twenty_eight);
	   strcpy(pick, twenty_eight);
	   cout << " Building caretaker. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 29:  x = strlen(twenty_nine);
	   strcpy(pick, twenty_nine);
	   cout << " The number of wings on a flea. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 30:  x = strlen(thirty);
	   strcpy(pick, thirty);
	   cout << " It is almost the truth. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 31:  x = strlen(thirty_one);
	   strcpy(pick, thirty_one);
	   cout << " The center of our solar system. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


    case 32:  x = strlen(thirty_two);
	   strcpy(pick, thirty_two);
	   cout << " Ben Franklin's face appears on a ______ dollar bill. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 33:  x = strlen(thirty_three);
	   strcpy(pick, thirty_three);
	   cout << " A whole decimal number. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 34:  x = strlen(thirty_four);
	   strcpy(pick, thirty_four);
	   cout << " A computer disease. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 35:  x = strlen(thirty_five);
	   strcpy(pick, thirty_five);
	   cout << " The closest planet to the earth. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 36:  x = strlen(thirty_six);
	   strcpy(pick, thirty_six);
	   cout << " A defiant person, scoundrel. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 37:  x = strlen(thirty_seven);
	   strcpy(pick, thirty_seven);
	   cout << " Armed conflict\n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 38:  x = strlen(thirty_eight);
	   strcpy(pick, thirty_eight);
	   cout << " Planets. \n\n";
	   cout << " Number of letters in word: " << x << endl;
	   win(); pong();
	   break;


   case 39: cout << "\n\n\n\n            THATS ALL FOLKS !!\n\n";
	     key_tap(); pong(); lose();
	     delay(2500);
	     goto end;



	     } // End of switch statement.


	   cout << "\n\n";

	   cout << " Your answer: ";

	   cin >> buffer;

	   if (strcmp(buffer, pick) == 0) {
	   right++;
	   ship(); win(); win();
	   cout << "\n RIGHT !!" << endl; }

	   else {
	   wrong++;
	   pong(); lose(); lose();
	   cout << "\n WRONG !!" << endl;
	   cout << "\n\nThe answer was: " << pick << endl; }


	printf("\n\n Would you like to try again ? (y-n) :  ");


       do {
       again = getchar();
       } while (again != 'y' && again != 'n');

       if (again == 'n') done=1;


       } // End of while.


       end:

       VGAScreen();

       srand(time(0));

       setborderc(12+rand() %256);

     for(int I1 = 0; I1 <= 400; I1++) {
     buzz(1500); quiet();
     Fill_Screen(random(256));  }


     cout << "\n            END GAME STATUS\n\n\n\n\n";

     cout << "\n\n You answered " << right << " questions right.\n\n\n";

     cout << " You answerd " << wrong << " questions wrong. \n\n\n";

     cout << "\n\n\n\n Hit spacebar to exit.." << endl;

     getch();

     pong();

     TextScreen();

     return 0;

     }





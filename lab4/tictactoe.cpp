// tictactoe.cpp
// Implementation file for Lab 4 Part 1: tictactoe example

// Name: Chris Roe
// Date: 1/31/17

#include <iostream>
using namespace std;

int main()
{
   // TODO:  Below each numbered comment, write one or more lines of code to
   // accomplish the stated task.

   // NOTE:  Refer to Jumping p.193-194.  This program is a variation of what
   // you see there.  We are storing chars instead of ints, and the dimensions
   // of the dynamic 2D array are read from the keyboard instead of being
   // hard-coded as 3s.

   // 1. Declare `p_p_tictactoe` of type pointer-to-a-pointer-to-a-char
      char**p_p_tictactoe;

   // 2. Prompt your user to enter a number of rows, then a number of columns.
   //    store their answers in the variables `rows` and `cols`.
      int rows;
      int cols;
      cout<< "Enter how many rows you would like: \n";
      cin>> rows;
      cout<< "Enter the number of columns you would like \n";
      cin>> cols;
   // 3. Allocate a 1-dimensional array of pointers-to-chars (length == `rows`)
   //    and store its address in `p_p_tictactoe`
      p_p_tictactoe = new char *[rows];

   // 4. Use a for-loop to allocate a dynamic array of chars (length == `cols`)
   //    for i from 0 to rows - 1 and store its address in `p_p_tictactoe[i]`.
      for (int i = 0; i<cols; i++)
      {	 	  	 	  	   	    	  	      	 	
         p_p_tictactoe[i] = new char [cols]; 
      }

   // 5. Use a for-loop to prompt the user to enter a char for each position in
   //    the array, displaying the message, "Enter a single character for position
   //    (" << i << ", " << j << "): "
   //    As you read each char, store it in the array.
        for (int i = 0; i<rows; i++)
        {
            for (int j = 0; j<cols; j++)
            {
               cout<< " Enter the number you want to use for,"<< " " << i << ", "<< j << "\n";
               cin>> p_p_tictactoe[i][j];
               cout<<"\n";
            }
        }
      
           

   // 6. Use a nested for-loop to print the array, one row per line.  The chars
   //    for each row should be space-separated.  For example, if the array is
   //    2 x 3 and stores the values A, B, C, X, !, &, the output should look
   //    like:
   //       A B C
   //       X ! &
         for (int i=0; i<rows; i++)
         {
            for (int j = 0; j<cols; j++)
            {
               cout<< p_p_tictactoe[i][j];
            }
            cout<< "\n";
         }

   // *** Prevent memory leaks by deallocating dynamic memory when you are done
   // using it. ***

   // 7. Use a for-loop to delete each row of the dynamic array.
         for (int i = 0; i<rows;i++)
         {	 	  	 	  	   	    	  	      	 	
            delete []  p_p_tictactoe[i];
            p_p_tictactoe == NULL;
         }
        

   // 8. Delete the pointer-to-a-pointer to release the array of row pointers,
   //    and set its value to NULL to avoid accessing invalid memory.
      delete [] p_p_tictactoe;
      p_p_tictactoe == NULL;

   cout << "Bye!" << endl;
   return 0;
}
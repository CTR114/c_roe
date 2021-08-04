//chris roe
//1/17/17

// count_fives.cpp

#include <iostream>
using namespace std;

int count_fives( int arr[], int len)
/* The function count_fives takes two parameters -- an integer array `arr`
and the integer length of the array, `len`.  The function is SUPPOSED
to return a count of how many of the entries in `arr` are equal to five.
*/
{
   int acc=0;
   for (int i = 0; i <len; i++)
   {
      if (arr[i] == 5)
      {
         ++acc;
      }
   }
   return acc;
}


int main()
{
   int arr[10] = { 2, 5, -1, 10, 5, 5, 0, 15, 6, 5 };
   int len = 10;

   int num = count_fives( arr, len);

   cout << "the array contains " << num << " fives" << endl;

}
	 	  	 	  	   	    	  	      	 	

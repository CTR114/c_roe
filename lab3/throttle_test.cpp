// File: throttle_test.cpp
// Author:  YOUR_NAME_HERE
// Date:  CURRENT_DATE
//
// Description: Unit testing code for the throttle class.

#include "throttle.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace main_savitch_2A;

/* @function   compareDoubles
 * @param      double d1
 * @param      double d2
 * @return     returns true if abs(d1-d2) < 0.001; otherwise, returns false
 */
bool compareDoubles(double d1, double d2)
{
   double diff = d1 - d2;
   if (diff < 0)
     diff = -diff;
   return (diff < 0.001);
}

/* @function   Test basic functionality of the throttle class.
 * @desc    Function for testing both throttle constructors;
 *             use the is_on and flow member functions to test
 *              that a throttle is created correctly.
 */
void test_basic_functionality()
{
   cout << "Testing default constructor . . . " ;
   throttle throt1;
   assert(! throt1.is_on());
   assert(compareDoubles(throt1.flow(), 0));
   cout << "PASSED!" << endl;

   // TO DO: Add test here for 1-parameter constructor

}	 	  	 	  	   	    	  	      	 	

/* @function   Test additional functionality of the throttle class.
 * @desc    Unit testing for shift, flow, and shut_off member functions.
 */
void test_additional_functionality()
{
   // TO DO:
   //        - Add tests for shut_off()
   //        - Add tests for shift() and flow()
   //        - Create additional throttle objects as needed for your tests
   //
   // HINT 1: Use is_on and flow to help you test the other member functions
   // HINT 2: Use the compareDoubles helper function in your asserts when
   //         testing the value returned by flow; for example, if the flow
   //         for throt1 should be 3/8:
   //         assert(compareDoubles(throt1.flow(),0.375));

   // Test basic shift() functionality for throttle created
   // with default constructor.
   throttle throt1;
   cout << "Testing shift() to throttle maximum  . . . " ;
   throt1.shift(1);
   assert(throt1.is_on());
   assert(compareDoubles(throt1.flow(), 1));
   cout << "PASSED!" << endl;


   // TO DO: Write your additional tests here
   throt1.shift(6);
   assert( throt1.is_on());
   assert(compareDoubles(throt1.flow(),6));
   cout<< "PASSED";

    throt1.shift(0);
   assert( throt1.is_on());
   assert(compareDoubles(throt1.flow(),0));
   cout<< "PASSED";

    throt1.shift(5);
   assert( throt1.is_on());
   assert(compareDoubles(throt1.flow(),5));
   cout<< "PASSED";

   

}	 	  	 	  	   	    	  	      	 	

int main()
{
   cout << "TESTING THROTTLE CLASS" << endl;

   // Test Basic Functionality
   test_basic_functionality();

   // Test Additional Functionality
   test_additional_functionality();

   cout << "DONE" << endl;

}



// Pixel_test.cpp
//
// Unit Tests for the Pixel Class
// CS 223, Winter 2017, Lab 4
//
// Name:Chris Roe
// Date: 2/7/17

#include <cassert>
#include <sstream>
#include <iostream>
#include <string>
#include "Pixel.h"

using namespace std;
using namespace imagelab;

// test_basic_functionality() should test the following:
//    Pixel (constructor)
//    getRed (done)
//    getGreen (done)
//    getBlue (Done)
//    set done
//    setRed done
//    setGreen done
//    setBlue done
void test_basic_functionality()
{
   Pixel p1(222,111,47);
   assert(p1.getRed()==222);
   assert(p1.getBlue()==47);
   assert(p1.getGreen()==111);
   p1.setRed(200);
   assert(p1.getRed()==200);
   p1.setGreen(100);
   assert(p1.getGreen()==100);
   p1.setBlue(40);
   assert(p1.getBlue()==40);
   // p1.set(260,-2,300);
   // assert(p1.getRed()==255);
   // assert(p1.getGreen()==0);
   //  assert(p1.getBlue()==255);

}

// test equivalence (==) and inequivalence (!=) operators
void test_equality_inequality()
{
   Pixel p3(200,100,40);
   Pixel p4(200,100,40);
   assert(p3==p4);
   Pixel p7(201,201,41);
   Pixel p6(207,222,47);
   assert(p7!=p6);
   Pixel p5(201,201,41);
   Pixel p9(201,201,47);
   assert(p5!=p9);

}


// test_streamIO() should test the following:
//    stream output (<<)
//    stream input (>>)
void test_streamIO()
{

   // Follow the steps below for testing stream output and input.
   // See stream IO tests that were given for Labs 3 and 4 for examples.

   // 1. Create local variables:
   //      - a stringstream for input, called "in"

   //      - a stringstream for output, called "out"

   //      - a Pixel called "pix"

   //      - a string called "correct" for storing the expected output for "pix"

   //
  //    (To read more about stringstreams, see the bottom of the following
   //    tutorial page: http://www.cplusplus.com/doc/tutorial/basic_io/)
   //
   stringstream in, out;
   string correct;
   Pixel pix;
   pix.setRed(200);
   pix.setGreen(103);
   pix.setBlue(45);

   // 2. Store the expected output in the string variable "correct"
   //
   correct = "200 103 45";

   // 3. Use the output stream variable "out" and the operator "<<" to
   //    (hopefully) put the expected output for Pixel variable "pix"
   //    into "out".
   //
   out << pix;

   // 4. Inside an assert, test whether the result of "out.str()"
   //    (.str() converts stream to string) equals the expected output
   //    in the variable "correct".
   string actual = out.str();
   assert(actual == correct);

   //
   // 5. To test stream input, use the input stream variable "in" and the
   //    operator "<<" to store an appropriate output representation for
   //    a pixel.  NOTE: Use different RGB values than were used originally
   //    for the Pixel variable "pix".
   //
   in << "17 50 100";


   // 6. Use the input stream variable "in" and the operator ">>" to
   //    change the value of "pix".
   //
   in >> pix;
   // 7. Use asserts to test that the attributes of "pix" were changed
   //    correctly.

   assert(pix.getRed() == 17);
   assert(pix.getGreen() == 50);
   assert(pix.getBlue() == 100);

}

int main()
{

   cout << "Ready to try some tests . . . " << endl;

   // TODO: Uncomment ONE test method call at a time, along with its cout line.
   //       Once that test function and the methods it is testing are fully
   //       implemented all those tests are, uncomment the call to the next
   //       test method and repeat.

   test_basic_functionality();
   cout << "basic methods passed" << endl;

   test_equality_inequality();
   cout << "tests for (in)equality passed" << endl;

   test_streamIO();
   cout << "stream IO passed" << endl;

   cout << "All current tests passing!" << endl;
   return 0;

}


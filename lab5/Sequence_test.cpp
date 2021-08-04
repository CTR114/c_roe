//  Sequence_test.cpp
//
//  Unit Tests for Sequence Class
//
//  <chris Roe>

#include <cassert>
#include <sstream>
#include <iostream>
#include <string>
#include "Sequence.h"

using namespace std;
using namespace main_savitch_3;

// ********* FOR PART ONE **********

// test part 1 methods together:
//    Sequence (constructor)
//    size
//    is_item
//    current
//    start
//    advance
//    append
void test_part1_methods() 
{
   Sequence s1;
   assert(s1.size() == 0);
   assert(!s1.is_item());

   s1.append('a');
   // s1 should now have one item, 'a', and it's the current item
   assert(s1.is_item());
   assert(s1.size() == 1);
   assert(s1.current() == 'a');

   s1.append('b');
   assert(s1.is_item());
   assert(s1.size() == 2);
   assert(s1.current() == 'b');
   s1.start();
   assert(s1.current() == 'a');

   // add more tests here once the tests above are passing
   Sequence s2;
   assert(s2.size() == 0);
   assert(!s2.is_item());
   s2.append('b');
   s2.append('c');
   s2.append('b');
   s2.append('c');
   assert(s2.is_item());
   assert(s2.size()==4);
   assert(s2.current() == 'c');


   Sequence s3;
   assert(s3.size() == 0);
   assert(!s3.is_item());
   s3.append('1');
   s3.append('2');
   s3.append('3');
   s3.append('4');
   s3.append('5');
   s3.append('6');
   s3.append('7');
   s3.append('8');
   assert(s3.is_item());
   assert(s3.size()==8);
   assert(s3.current() == '8');
   s3.start();
   assert(s3.current()== '1');
   s3.advance();
   assert(s3.current()== '2');

}	 	  	 	  	   	    	  	      	 	

// ********* FOR PART TWO **********

// test the remaining functions

// insert
void test_insert()
{
   Sequence s1;
   s1.insert('a');
   // s1 should now have one item, 'a', and it's the current item
   assert(s1.is_item());
   assert(s1.size() == 1);
   assert(s1.current() == 'a');

   s1.insert('b');
   // s1 should now have two items
   assert(s1.is_item());
   assert(s1.size() == 2);
   Sequence s2;
   s2.insert('h');
   s2.insert('5');
   assert(s2.is_item());
   assert(s2.size()==2);
   s2.insert ('y');
   s2.insert ('a');
   s2.insert ('r');
   s2.insert ('8');
   s2.insert ('9');
   s2.insert ('2');
   s2.insert ('d');
   s2.insert ('e');
   s2.insert ('u');
   assert(s2.size()==11);

   Sequence s3;
   s3.insert('a');
   s3.insert('b');
   assert(s3.current()=='b');
   s3.insert('c');
   assert(s3.current()=='c');

}	 	  	 	  	   	    	  	      	 	

// remove_current
void test_remove_current()
{
   Sequence s1;
   s1.append('a');
   s1.remove_current();
   assert(!s1.is_item());
   assert(s1.size() == 0);

   s1.append('p');
   s1.append('o');
   s1.append('p');
   s1.start();
   // s1 is (p, o, p); current item is the first p
   s1.remove_current();
   // s1 is (o, p); current item is o
   assert(s1.is_item());
   assert(s1.current() == 'o');
   assert(s1.size() == 2);
   s1.advance();
   assert(s1.current() == 'p');

   Sequence s2;
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('g');
   s2.append('h');
   assert(s2.current()=='h');
   s2.remove_current();
   assert(s2.size()==29);
   s2.advance();  

}	 	  	 	  	   	    	  	      	 	

// == operator and != operator
void test_equals_unequals()
{
   Sequence s1;
   Sequence s2;
   s1.append('a');
   assert(!(s1 == s2));
   assert(s1 != s2);
   s2.append('a');
   assert(s1 == s2);
   assert(!(s1 != s2));

   Sequence s3;
   s3.append('c');
   s3.append('h');
   s3.append('r');
   s3.append('i');
   s3.append('s');

//sequence s3 = (c,h,r,i,s)
   Sequence s4;
   s4.append('r');
   s4.append('o');
   s4.append('e');
   //sequence s4 = (r,o,e)
   Sequence s5;
   s5.append('c');
   s5.append('h');
   s5.append('r');
   s5.append('i');
   s5.append('s');
   //ssequence s5 = (c,h,r,i,s)
   assert(!(s3==s4));
   assert(s3==s5);
   assert(!(s4==s5));
   
}	 	  	 	  	   	    	  	      	 	

// + operator and += operator
void test_adding_two_ways()
{
   Sequence s1;
   s1.insert('c');
   Sequence s2;
   s2.insert('t');
   s2.insert('a');
   Sequence s3 = s1 + s2;  // s3 = (c, a, t); current item c
   assert(s3.size() == 3);
   assert(s3.is_item());
   assert(s3.current() == 'c');
   s3.advance();
   assert(s3.current() == 'a');
   s3.advance();
   

   // add more tests here

   Sequence s4;
   s4.insert('c');
   s4.insert('h');
   s4.insert('r');
   s4.insert('i');
   s4.insert('s');
   assert(s4.current()=='s');

   Sequence s5;
   s5.insert('r');
   s5.insert('o');
   s5.insert('e');
   Sequence s6 = s4 + s5;
   assert(s6.size()==8);
   assert(s6.is_item());

   s4+=s5;
   assert(s4.size()==8);
   //assert(s4.current()=='s');



   Sequence s7;
   s7.insert('1');
   s7.append('2');
   s7.append('3');
   s7.append('4');
   s7.append('5');
   s7.append('6');
   s7.append('7');
   s7.append('8');
   s7.append('9');
   s7.append('a');
   s7.append('b');
   s7.append('c');
   s7.append('d');
   s7.append('e');
   s7.append('f');
   Sequence s8;
   s8.append('1');
   s8.append('3');
   s8.append('3');
   s8.append('4');
   s8.append('5');
   s8.append('6');
   s8.append('7');
   s8.append('8');
   s8.append('9');
   s8.append('a');
   s8.append('b');
   s8.append('c');
   s8.append('d');
   s8.append('e');
   s8.append('g');

   s7+=s8;
   assert(s7.size()==30);
   assert(s7.current()== 'f');






}	 	  	 	  	   	    	  	      	 	

// test stream I/O for typical sequences
// All tests are provided.
void test_streamIO_1()
{
   // 1. Create local variables:
   //  - a stringstream for input, called in
   //  - a stringstream for output, called out
   //  - a string for storing the expected message, called correct
   //  - a Sequence with specific name and age, called p
   stringstream in, out;
   string correct;
   Sequence seq;
   seq.append('h');
   seq.append('i');
   seq.append('!');
   seq.start();

   // 2. Store the expected message in the string variable "correct"
   // Get it exactly right!
   correct = "sequence: h i !";

   // 3. Use the output stream variable "out" and the operator "<<" to
   // (hopefully) put the expected message for seq into the stream
   out << seq;

   // 4. Inside an assert, test whether the "out.str()" result
   // (.str() converts stream to string) equals the expected message string
   string actual = out.str();
   assert(actual == correct);

   // 5. To test stream input, use the input stream variable "in" and the
   // operator "<<" to store an appropriate message such as,
   in << "Sequence: c a t s";

   // 6. Use the input stream variable "in" and the operator ">>" to
   // change seq
   in >> seq;

   // 7. Use asserts to test that the attributes of seq
   // have been modified as expected
   assert(seq.size() == 4);
   assert(seq.current() == 'c'); // operator>> should move current to start
   seq.advance();
   assert(seq.current() == 'a');
   seq.advance();
   assert(seq.current() == 't');
   seq.advance();
   assert(seq.current() == 's');
}	 	  	 	  	   	    	  	      	 	

// test stream I/O for empty sequences
// All tests are provided.
void test_streamIO_2()
{
   // 1. Create local variables:
   //  - a stringstream for input, called in
   //  - a stringstream for output, called out
   //  - a string for storing the expected message, called correct
   //  - a Sequence with specific name and age, called p
   stringstream in, out;
   string correct;
   correct = "sequence: <empty sequence>";
   Sequence seq; // empty sequence
   assert(seq.size()==0);



   // 3. Use the output stream variable "out" and the operator "<<" to
   // (hopefully) put the expected message for seq into the stream
   out << seq;

   // 4. Inside an assert, test whether the "out.str()" result
   // (.str() converts stream to string) equals the expected message string
   string actual = out.str();
   assert(actual == correct );

   // 5. To test stream input, use the input stream variable "in" and the
   // operator "<<" to store an appropriate message such as,
   in << "sequence: <empty sequence>";


   // put some items into seq to make sure they disappear after stream input
   seq.append('s');
   seq.append('t');
   seq.append('u');
   seq.append('f');
   seq.append('f');

   // 6. Use the input stream variable "in" and the operator ">>" to
   // change seq
   in >> seq;

   // 7. Use asserts to test that the attributes of seq
   // have been modified as expected
   assert(seq.size() == 0);
   assert(seq.is_item() == false);
}	 	  	 	  	   	    	  	      	 	

int main() {
   cout << "Ready to try some tests . . . " << endl;

   // TODO:  UNCOMMENT one test call at a time, along with its cout line.
   // Once that test is fully implemented and passing, uncomment the next
   // test call and repeat.

   test_part1_methods();
   cout << "basic methods passed" << endl;

    test_insert();
    cout << "insert passed" << endl;

    test_remove_current();
    cout << "remove_current passed" << endl;

    test_equals_unequals();
    cout << "== and != passed" << endl;

    test_adding_two_ways();
    cout << "+ and += passed" << endl;

    test_streamIO_1();
    cout << "streamIO_1 (typical << and >>) passed" << endl;

    test_streamIO_2();
    cout << "streamIO_2 (<< and >> for empty sequence) passed" << endl;

   cout << "All current tests passing!" << endl;
   return 0;
}
	 	  	 	  	   	    	  	      	 	

/*
*  stack_test.cpp
*
*  Unit Tests for stack template class, Lab 7 Part 2
*
*  name: Chris      
*  date: Roe
*/

#include <stdexcept>
#include <cassert>
#include <iostream>
#include <sstream>
#include "node2.h"
#include "stack.h"

using namespace std;
using namespace main_savitch_7B;

void test_string_stack_constructor()
{
    string test = "  constr.test.1: empty string stack";
    cout << test << endl;;

    stack<string> s1;
    assert(s1.empty());
}

void test_int_stack_constructor()
{
    string test = "  constr.test.2 empty int stack";
    cout << test << endl;;

    stack<int> s1;
    assert(s1.empty());
}

void test_constructor()
{	 	  	 	  	   	    	  	      	 	
    // Test stack() and empty() together
    cout << "\nTesting stack constructor . . ." << endl;

    // Test 1: empty string stack
    test_string_stack_constructor();

    // Test 2: empty int stack
    test_int_stack_constructor();

    cout << ". . . constructor OK!" << endl << endl;
}

void test_push_pop_empty_top1()
{
    string test = "  test_push_pop_empty_top.test.1:strings add and remove and check";
    cout << test << endl;;
    stack<string> s1;
    s1.push("C");
    assert(s1.top() == "C");
    s1.pop();
    assert(s1.empty());
}

void test_push_pop_empty_top2()
{
    string test = "  test_push_pop_empty_top.test.2:ints add and remove and check";
    cout << test << endl;;
    stack<int> s1;
    s1.push(1);
    assert(s1.top() == 1);
    s1.pop();
    assert(s1.empty());
}

void test_push_pop_empty_top3()
{	 	  	 	  	   	    	  	      	 	
    string test = "  test_push_pop_empty_top.test.3:strings(3) add and remove and check";
    cout << test << endl;;
    stack<string> s1;
    s1.push("C");
    assert(s1.top() == "C");
    s1.push("H");
    s1.push("R");
    assert(s1.top() == "R");
    s1.pop();
    assert(s1.top() == "H");
}

void test_push_pop_empty_top4()
{
    string test = "  test_push_pop_empty_top.test.4:ints(3) add and remove and check";
    cout << test << endl;;
    stack<int> s1;
    s1.push(1);
    assert(s1.top() == 1);
    s1.push(2);
    s1.push(3);
    assert(s1.top() == 3);
    s1.pop();
    assert(s1.top() == 2);
}


void test_push_pop_empty_top()
{
    // Test push, top, and empty
    cout << "\nTesting push, pop, empty, and top . . ." << endl;
    // test using both int stacks and string stacks
    test_push_pop_empty_top1();
    test_push_pop_empty_top2();
    test_push_pop_empty_top3();
    test_push_pop_empty_top4();
    

    cout << ". . . push, pop, empty, and top OK!" << endl << endl;
}	 	  	 	  	   	    	  	      	 	

void test_size1()
{
    string test = "  test_size.1:string of 1 and 0";
    cout << test << endl;;
    stack<string> s1;
    s1.push("c");
    assert(s1.size() == 1);
    stack<string> s2;
    assert(s2.size() == 0);
}
void test_size2()
{
    string test = "  test_size.2:int of 1 and 0";
    cout << test << endl;;
    stack<int> s1;
    s1.push(1);
    assert(s1.size() == 1);
    stack<int> s2;
    assert(s2.size() == 0);
}
void test_size3()
{
    string test = "  test_size.3:string of 3";
    cout << test << endl;;
    stack<string> s1;
    s1.push("c");
    s1.push("h");
    s1.push("r");
    assert(s1.size() == 3);
}
void test_size4()
{
    string test = "  test_size.4:doubles of 3";
    cout << test << endl;;
    stack<double> s1;
    s1.push(1.2);
    s1.push(2.5);
    s1.push(3.7);
    assert(s1.size() == 3);
}	 	  	 	  	   	    	  	      	 	

void test_size()
{
    cout << "\nTesting size . . ." << endl;
    // test using stacks of strings, ints, chars, or doubles
    test_size1();
    test_size2();
    test_size3();
    test_size4();

    cout << ". . . size OK!" << endl << endl;
}

void test_equiv_inequiv1()
{
    string test = "  test_equiv_inequiv.1:all types of stack 0 == to eachother";
    cout << test << endl;;
    stack<int> s1;
    assert(s1.size() == 0);
    stack<int> s2;
    assert (s2.size() == 0);
    assert (s1 == s2);
    s2.push(1);
    assert(s1 != s2);

    stack<char> s3;
    assert(s3.size() == 0);
    stack<char> s4;
    assert(s4.size() == 0);
    assert(s3 == s4);
    s4.push('c');
    assert(s3 != s4);

    stack<double> s5;
    assert(s5.size() == 0);
    stack<double> s6;
    assert(s6.size() == 0);
    assert(s5 == s6);
    s6.push(1.3);
    assert(s5 != s6);

    stack<string> s7;
    assert(s7.size() == 0);
    stack<string> s8;
    assert(s8.size() == 0);
    assert(s7 == s8);
    s8.push("C");
    assert(s7 != s8);
}	 	  	 	  	   	    	  	      	 	
void test_equiv_inequiv2()
{
    string test = "  test_equiv_inequiv.2:int stack 3 == and and stack 4 uneq";
    cout << test << endl;;
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    stack<int> s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    assert (s1 == s2);
    s2.push(2);
    assert(s1 != s2);

}
void test_equiv_inequiv3()
{
    string test = "  test_equiv_inequiv.3:double stack 3 == and and stack 4 uneq";
    cout << test << endl;
    stack<double> s5;
    stack<double> s6;
    s5.push(7.3);
    s5.push(8.3);
    s5.push(9.3);
    s6.push(7.3);
    s6.push(8.3);
    s6.push(9.3);
    assert(s5 == s6);
    s6.push(9.3);
    assert(s5 != s6);

}
void test_equiv_inequiv4()
{	 	  	 	  	   	    	  	      	 	
    string test = "  test_equiv_inequiv.4:char stack 3 == and and stack 4 uneq";
    cout << test << endl;
    stack<char> s3;
    stack<char> s4;
    s3.push('c');
    s3.push('h');
    s3.push('r');
    s4.push('c');
    s4.push('h');
    s4.push('r');
    assert(s3 == s4);
    s4.push('c');
    assert(s3 != s4);

}
void test_equiv_inequiv5()
{
    string test = "  test_equiv_inequiv.2:string stack 3 == and and stack 4 uneq";
    cout << test << endl;
    stack<string> s7;
    stack<string> s8;
    s7.push("Chris");
    s7.push("Roe");
    s7.push("Lucas");
    s8.push("Chris");
    s8.push("Roe");
    s8.push("Lucas");
    assert(s7 == s8);
    s8.push("Roe");
    assert(s7 != s8);

}

void test_equiv_inequiv()
{
    cout << "\nTesting (in)equivalence . . ." << endl;
    // test using stacks of strings, ints, chars, or doubles
    test_equiv_inequiv1();
    test_equiv_inequiv2();
    test_equiv_inequiv3();
    test_equiv_inequiv4();
    test_equiv_inequiv5();
    
    cout << ". . . equivalence and inequivalence OK!" << endl;
}	 	  	 	  	   	    	  	      	 	
void test_reverse1()
{
    string test = "  test_reverse.1:int of 3 reverse";
    cout << test << endl;;
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    assert(s1.size() == 3);
    s1.reverse();
    assert(s1.top() == 1);
}
void test_reverse2()
{
    string test = "  test_reverse.2:string of 3 reverse";
    cout << test << endl;;
    stack<string> s1;
    s1.push("C");
    s1.push("H");
    s1.push("R");
    assert(s1.size() == 3);
    s1.reverse();
    assert(s1.top() == "C");
}
void test_reverse3()
{
    string test = "  test_reverse.3:double of 2 reverse";
    cout << test << endl;;
    stack<double> s1;
    s1.push(2.4);
    s1.push(7.5);
    assert(s1.size() == 2);
    s1.reverse();
    assert(s1.top() == 2.4);
}

void test_reverse4()
{	 	  	 	  	   	    	  	      	 	
    string test = "  test_reverse.4:char of 3 reverse";
    cout << test << endl;;
    stack<char> s1;
    s1.push('c');
    s1.push('h');
    s1.push('r');
    assert(s1.size() == 3);
    s1.reverse();
    assert(s1.top() == 'c');
}
void test_reverse()
{
    cout << "\nTesting reverse . . ." << endl;
    // test using stacks of strings, ints, chars, or doubles
    test_reverse1();
    test_reverse2();
    test_reverse3();
    test_reverse4();
    cout << ". . . reverse is OK!" << endl << endl;
}
void test_copy_constr1()
{
    string test = "  test_copy_constr.1:char of 3 copy";
    cout << test << endl;;
    stack<char> s1;
    s1.push('c');
    s1.push('h');
    s1.push('r');
    assert(s1.size() == 3);
    assert(s1.top() == 'r');
    stack<char> s2(s1);
    assert(s2.size() == 3);
    assert(s2.top() == 'r');
}
void test_copy_constr2()
{	 	  	 	  	   	    	  	      	 	
    string test = "  test_copy_constr.2:string of 3 copy";
    cout << test << endl;;
    stack<string> s1;
    s1.push("c");
    s1.push("h");
    s1.push("r");
    assert(s1.size() == 3);
    assert(s1.top() == "r");
    stack<string> s2(s1);
    assert(s2.size() == 3);
    assert(s2.top() == "r");
}
void test_copy_constr3()
{
    string test = "  test_copy_constr.3:int of 3 copy";
    cout << test << endl;;
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    assert(s1.size() == 3);
    assert(s1.top() == 3);
    stack<int> s2(s1);
    assert(s2.size() == 3);
    assert(s2.top() == 3);
}
void test_copy_constr4()
{
    string test = "  test_copy_constr.4:double of 3 copy";
    cout << test << endl;;
    stack<double> s1;
    s1.push(1.1);
    s1.push(2.5);
    s1.push(7.7);
    assert(s1.size() == 3);
    assert(s1.top() == 7.7);
    stack<double> s2(s1);
    assert(s2.size() == 3);
    assert(s2.top() == 7.7);

}	 	  	 	  	   	    	  	      	 	
void test_copy_constr()
{
    cout << "\nTesting copy constructor . . ." << endl;
    // test using stacks of strings, ints, chars, or doubles

   test_copy_constr1();
   test_copy_constr2();
   test_copy_constr3();
   test_copy_constr4();

    cout << ". . . copy constructor is OK!" << endl << endl;
}
void test_assignment1()
{
    string test = "  test_assignment.1:char of 3 assignment";
    cout << test << endl;;
    stack<char> s1;
    s1.push('c');
    s1.push('h');
    s1.push('r');
    assert(s1.size() == 3);
    assert(s1.top() == 'r');
    stack<char> s2;
    s2 = s1;
    assert(s2.size() == 3);
    assert(s2.top() == 'r');
}
void test_assignment2()
{
    string test = "  test_assignment.2:string of 3 assignment";
    cout << test << endl;;
    stack<string> s1;
    s1.push("c");
    s1.push("h");
    s1.push("r");
    assert(s1.size() == 3);
    assert(s1.top() == "r");
    stack<string> s2;
    s2 = s1;
    assert(s2.size() == 3);
    assert(s2.top() == "r");

}	 	  	 	  	   	    	  	      	 	
void test_assignment3()
{
    string test = "  test_assignment.3:int of 3 assignment";
    cout << test << endl;;
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    assert(s1.size() == 3);
    assert(s1.top() == 3);
    stack<int> s2;
    s2 = s1;
    assert(s2.size() == 3);
    assert(s2.top() == 3);

}
void test_assignment4()
{
    string test = "  test_assignment.4:double of 3 assignment";
    cout << test << endl;;
    stack<double> s1;
    s1.push(1.1);
    s1.push(2.5);
    s1.push(7.7);
    assert(s1.size() == 3);
    assert(s1.top() == 7.7);
    stack<double> s2;
    s2 = s1;
    assert(s2.size() == 3);
    assert(s2.top() == 7.7);

}

void test_assignment()
{
    cout << "\nTesting assignment operator . . ." << endl;
    // test using stacks of strings, ints, chars, or doubles
    test_assignment1();
    test_assignment2();
    test_assignment3();
    test_assignment4();
    cout << ". . . assignment operator is OK!" << endl << endl;
}	 	  	 	  	   	    	  	      	 	

int main()
{
    cout << "Testing stack class... " << endl;

    // Tests provided
    test_constructor();

    // Tests not provided
    test_push_pop_empty_top();
    test_size();
    test_equiv_inequiv();
    test_reverse();
    test_copy_constr();
    test_assignment();

    cout << "All current tests are passing.  Need to add more??" << endl;
}


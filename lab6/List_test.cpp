// FILE: List.cpp
// CS 223 Winter 2017, Lab 6, Part 2
//
// <chris Roe March 12th>
//
// List class implementation for a circular DLL with sentinel node.
//
// Instance data:  Every List has a pointer to its sentinel node.
//
// Class invariants:
//    1. All of the list nodes, including the sentinel node,
//       are stored in dynamic memory.
//    2. The head pointer for the list always points to the sentinel node.
//    3. The sentinel node's data is always the default value for
//       DLL_node::value_type.
//    4. For an EMPTY list, the sentinel node's links (prev, next) refer to
//       the sentinel node itself.
//
// NOTE: The DLL_node class is already completely implemented in DLL_node.h.
//    Use `DLL_node::value_type` to refer to the type of data stored in
//    a node.
//

#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "Person.h"
#include "DLL_node.h"
#include "List.h"

using namespace std;
using namespace lab6_part2;

// create some global Person objects to use in tests
Person p1;  // default Person
Person Mickey_Mouse("Mickey", "Mouse", 45);
Person Minnie_Mouse("Minnie", "Mouse", 45);
Person Peter_Pan("Peter", "Pan", 100);
Person Ziggy_Wilson("Ziggy", "Wilson", 5);
Person Skye_Wilson("Skye", "Wilson", 4);
Person Mister_Gray("Mister", "Gray", 10);
Person Dopey_Dwarf("Dopey", "Dwarf", 73);
Person Sleepy_Dwarf("Sleepy", "Dwarf", 73);
Person Happy_Dwarf("Happy", "Dwarf", 73);
Person Snow_White("Snow", "White", 21);

// an array of 10 persons
Person person[] =
    { Mickey_Mouse, Minnie_Mouse, Peter_Pan, Ziggy_Wilson, Skye_Wilson,
      Mister_Gray, Dopey_Dwarf, Sleepy_Dwarf, Happy_Dwarf, Snow_White};

void test_constructor1()
{	 	  	 	  	   	    	  	      	 	
    string test = "  constructor.test.1: create new list with default constructor";  // NOLINT
    cout << test << endl;
    List l1;
    assert(l1.is_empty());
}

void test_head_insert_and_basics1()
{
    string test = "  test.head.insert.and.basics.1: head_insert into empty list";  // NOLINT
    cout << test << endl;
    List l1;
    l1.head_insert(Snow_White);
    assert(!l1.is_empty());
    assert(l1.front() == Snow_White);
    assert(l1.back() == Snow_White);
}

void test_head_insert_and_basics2()
{
    string test = "  test.head.insert.and.basics.2: head_insert into 1-elt list";  // NOLINT
    cout << test << endl;
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Happy_Dwarf);
    assert(!l1.is_empty());
    assert(l1.front() == Happy_Dwarf);
    assert(l1.back() == Snow_White);
}

void test_head_insert_and_basics3()
{
    string test = "  test.head.insert.and.basics.3: head_insert into 2-elt list";  // NOLINT
    cout << test << endl;
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Happy_Dwarf);
    l1.head_insert(Sleepy_Dwarf);
    assert(!l1.is_empty());
    assert(l1.front() == Sleepy_Dwarf);
    assert(l1.back() == Snow_White);
}	 	  	 	  	   	    	  	      	 	

void test_assignment_operator1()
{
    string test = "  assignment.test.1: assignment from length 0 to length 2";  // NOLINT
    cout << test << endl;
    List l1;
    List copyOfl1;
    copyOfl1.head_insert(Sleepy_Dwarf);
    copyOfl1.head_insert(Happy_Dwarf);
    copyOfl1 = l1;
    assert(copyOfl1.is_empty());
}

void test_assignment_operator2()
{
    string test = "  assignment.test.2: assignment from length 1 to length 4";  // NOLINT
    cout << test << endl;
    List l1;
    l1.head_insert(Sleepy_Dwarf);
    List copyOfl1;
    copyOfl1.head_insert(Happy_Dwarf);
    copyOfl1.head_insert(Happy_Dwarf);
    copyOfl1.head_insert(Happy_Dwarf);
    copyOfl1.head_insert(Happy_Dwarf);
    copyOfl1 = l1;
    assert(copyOfl1.front() == Sleepy_Dwarf);
    copyOfl1.head_remove();
    assert(copyOfl1.is_empty());
}

void test_assignment_operator3()
{
    string test = "  assignment.test.3: assignment from length 5 to length 0";  // NOLINT
    cout << test << endl;
    List l1;
    for (int i = 0; i < 5; i++)
    {	 	  	 	  	   	    	  	      	 	
        l1.tail_insert(person[i]);
    }
    List copyOfl1;
    copyOfl1 = l1;
    for (int i = 0; i < 5; i++)
    {
        assert(copyOfl1.front() == person[i]);
        copyOfl1.head_remove();
    }
    assert(copyOfl1.is_empty());
}

void test_assignment_operator4()
{
    string test = "  assignment.test.4: assignment from length 5 to length 1";  // NOLINT
    cout << test << endl;
    List l1;
    for (int i = 0; i < 5; i++)
    {
        l1.tail_insert(person[i]);
    }
    List copyOfl1;
    copyOfl1.head_insert(Snow_White);
    copyOfl1 = l1;
    for (int i = 0; i < 5; i++)
    {
        assert(copyOfl1.front() == person[i]);
        copyOfl1.head_remove();
    }
    assert(copyOfl1.is_empty());
}

void test_assignment_operator5()
{
    string test = "  assignment.test.5: self-assignment is OK";  // NOLINT
    cout << test << endl;
    List l1;
    for (int i = 0; i < 5; i++)
    {	 	  	 	  	   	    	  	      	 	
        l1.tail_insert(person[i]);
    }
    l1 = l1;
    for (int i = 0; i < 5; i++)
    {
        assert(l1.front() == person[i]);
        l1.head_remove();
    }
    assert(l1.is_empty());
}

void test_copy_constructor1()
{
    string test = "  copy_constructor.test.1: create copy from length 0";  // NOLINT
    cout << test << endl;
    List l1;
    List copyOfl1(l1);
    assert(copyOfl1.is_empty());
}

void test_copy_constructor2()
{
    string test = "  copy_constructor.test.2: create copy from length 1";  // NOLINT
    cout << test << endl;
    List l1;
    l1.head_insert(Ziggy_Wilson);
    List copyOfl1(l1);
    assert(copyOfl1.front() == Ziggy_Wilson);
    copyOfl1.head_remove();
    assert(copyOfl1.is_empty());
}

void test_copy_constructor3()
{
    string test = "  copy_constructor.test.3: create copy from length 5";  // NOLINT
    cout << test << endl;
    List l1;
    for (int i = 0; i < 5; i++)
    {	 	  	 	  	   	    	  	      	 	
        l1.tail_insert(person[i]);
    }
    List copyOfl1(l1);
    for (int i = 0; i < 5; i++)
    {
        assert(copyOfl1.front() == person[i]);
        copyOfl1.head_remove();
    }
    assert(copyOfl1.is_empty());
}

void test_copy_constructor4()
{
    string test = "  copy_constructor.test.4: copy is independent of original";  // NOLINT
    cout << test << endl;
    List l1;
    l1.head_insert(Ziggy_Wilson);
    List copyOfl1(l1);
    l1.clear();
    assert(l1.is_empty());
    assert(!copyOfl1.is_empty());
}

void test_constructor()  // PROVIDED
{
    cout << "\nTesting list constructor . . ." << endl;

    // Test 1: create a list with the default constructor
    test_constructor1();

    cout << ". . . list constructor OK!" << endl;
}

void test_head_insert_and_basic_methods()  // PROVIDED
{
    cout << "\nTesting head_insert and basic methods . . ." << endl;

    // Test 1: head_insert into empty list
    test_head_insert_and_basics1();

    // Test 2 head_insert into 1-element list
    test_head_insert_and_basics2();

    // Test 3: head_insert into 2-element list
    test_head_insert_and_basics3();

    cout << ". . . head_insert OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_assignment_operator()  // PROVIDED
{
    cout << "\nTesting assignment_operator . . ." << endl;

    // Test 1: assignment from length 0 to length 2
    test_assignment_operator1();

    // Test 2: assignment from length 1 to length 4
    test_assignment_operator2();

    // Test 3: assignment from length 5 to length 0
    test_assignment_operator3();

    // Test 4: assignment from length 5 to length 1
    test_assignment_operator4();

    // Test 5: self-assignment is OK
    test_assignment_operator5();

    cout << ". . . assignment_operator OK!" << endl;
}

void test_copy_constructor()  // PROVIDED
{
    cout << "\nTesting copy_constructor . . ." << endl;

    // Test 1: create copy from length 0
    test_copy_constructor1();

    // Test 2: create copy from length 1
    test_copy_constructor2();

    // Test 3: create copy from length 5
    test_copy_constructor3();

    // Test 4: copied list is independent of the original list
    test_copy_constructor4();

    cout << ". . . copy_constructor is OK!" << endl;
}	 	  	 	  	   	    	  	      	 	



void test_tail_insert1()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.tail_insert(Happy_Dwarf);
    l1.tail_insert(Ziggy_Wilson);
    assert(!l1.is_empty());
    assert(l1.front() == Snow_White);
    assert(l1.back() == Ziggy_Wilson);
}

void test_tail_insert2()
{
    List l1;
    l1.tail_insert(Ziggy_Wilson);
    assert(l1.front() == Ziggy_Wilson);
    assert(l1.back() == Ziggy_Wilson);
}

void test_tail_insert3()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.tail_insert(Happy_Dwarf);
    l1.tail_insert(Ziggy_Wilson);
    l1.tail_insert(Skye_Wilson);
    l1.tail_insert(Dopey_Dwarf);
    assert(!l1.is_empty());
    assert(l1.front() == Snow_White);
    assert(l1.back() == Dopey_Dwarf);
}

void test_tail_insert()
{	 	  	 	  	   	    	  	      	 	
    cout << "\nTesting tail_insert . . ." << endl;
    test_tail_insert1();
    test_tail_insert2();
    test_tail_insert3();

    cout << ". . . tail_insert OK!" << endl;
}
void test_clear1()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.tail_insert(Happy_Dwarf);
    l1.tail_insert(Ziggy_Wilson);
    l1.tail_insert(Skye_Wilson);
    l1.tail_insert(Dopey_Dwarf);
    assert(!l1.is_empty());
    l1.clear();
    assert(l1.is_empty());

}

void test_clear2()
{
    List l1;
    l1.head_insert(Snow_White);
    assert(!l1.is_empty());
    l1.clear();
    assert(l1.is_empty());
}

void test_clear()
{
    cout << "\nTesting clear . . ." << endl;

    test_clear1();
    test_clear2();


    cout << ". . . clear is OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_head_remove1()
{
    List l1;
    l1.head_insert(Snow_White);
    assert(!l1.is_empty());
    assert( l1.head_remove());
    assert(l1.is_empty());
}
void test_head_remove2()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Ziggy_Wilson);
    l1.head_insert(Skye_Wilson);
    l1.head_insert(Dopey_Dwarf);
    assert(l1.front() == Dopey_Dwarf);
    assert( l1.head_remove());
    assert(l1.front() == Skye_Wilson);
    
}

void test_head_remove()
{
    cout << "\nTesting head_remove . . ." << endl;

    test_head_remove1(); // List of 1 item and removes it from list
    test_head_remove2(); // list of 4 items remove the head_ptr

     cout << ". . . head_remove is OK!" << endl;
}

void test_tail_remove1()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Skye_Wilson);
    assert(!l1.is_empty());
    assert(l1.tail_remove());
    assert(l1.back() == Skye_Wilson);
    
}	 	  	 	  	   	    	  	      	 	
void test_tail_remove2()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Skye_Wilson);
    l1.head_insert(Happy_Dwarf);
    l1.head_insert(Ziggy_Wilson);
    l1.head_insert(Dopey_Dwarf);
    assert(!l1.is_empty());
    assert(l1.tail_remove());
    assert(l1.back() == Skye_Wilson);
}
void test_tail_remove3()
{
    List l1;
    l1.head_insert(Snow_White);
    assert(!l1.is_empty());
    assert(l1.tail_remove());
    assert(l1.is_empty());
}

void test_tail_remove()
{
    cout << "\nTesting tail_remove . . ." << endl;

    test_tail_remove1(); // removes tail end of a list holding 2
    test_tail_remove2(); // removes item from list of 5
    test_tail_remove3(); // removes item from list of 1
     cout << ". . . tail_remove is OK!" << endl;  
     // try to add a test after turning it in wouldnt let me turn in a 
     // brand new file so i changed it in edit
}

void test_contains1()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Skye_Wilson);
    assert(!l1.is_empty());
    assert(l1.contains(Snow_White));

}	 	  	 	  	   	    	  	      	 	

void test_contains2()
{
    List l1;
    l1.head_insert(Skye_Wilson);
    assert(!l1.is_empty());
    assert(l1.contains(Skye_Wilson));
}

void test_contains3()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Happy_Dwarf);
    l1.head_insert(Ziggy_Wilson);
    l1.head_insert(Skye_Wilson);
    l1.head_insert(Mickey_Mouse);
    assert(!l1.is_empty());
    assert(l1.contains(Ziggy_Wilson));
}

void test_contains()
{
    cout << "\nTesting contains . . ." << endl;

    test_contains1(); // finding 1 item in list of 2
    test_contains2(); // 1 item in list finding it
    test_contains3(); // finding item in list of 5

    cout << ". . . contains is OK!" << endl;
}

void test_remove_first_of1()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Happy_Dwarf);
    l1.head_insert(Ziggy_Wilson);
    l1.head_insert(Skye_Wilson);
    l1.head_insert(Mickey_Mouse);
    assert(!l1.is_empty());
    l1.remove_first_of(Mickey_Mouse);
    assert(!(l1.contains(Mickey_Mouse)));
}	 	  	 	  	   	    	  	      	 	

void test_remove_first_of2()
{
    List l1;
    l1.head_insert(Snow_White);
    assert(!l1.is_empty());
    l1.remove_first_of(Snow_White);
    assert(!(l1.contains(Mickey_Mouse)));
}
void test_remove_first_of3()
{
    List l1;
    l1.head_insert(Snow_White);
    l1.head_insert(Ziggy_Wilson);
    l1.head_insert(Snow_White);
    assert(!l1.is_empty());
    l1.remove_first_of(Snow_White);
    assert(l1.back()==Snow_White);
}

void test_remove_first_of4()
{
    List l1;
    assert(l1.remove_first_of(Snow_White)==false);
}


void test_remove_first_of()
{
    cout << "\nTesting remove_first_of . . ." << endl;

    test_remove_first_of1(); // removes an item out of 5
    test_remove_first_of2(); // removes the item out of 1
    test_remove_first_of3(); // removes first snow white last one still there
    test_remove_first_of4(); // returning false
    cout << ". . . remove_first_of is OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

// Only need to implement this if you did the extra credit
void test_bracket_indexing()
{
    cout << "\nTesting bracket_indexing . . ." << endl;

    cout << "-- tests not implemented --" << endl << endl;

    // cout << ". . . bracket_indexing is OK!" << endl;
}

int main()
{
    // ONE TEST AT A TIME:
    //   - Uncomment the call to the testing function.
    //   - Implement the testing function if it was not provided, including
    //     edge cases and typical cases.  (Do not test invalid use cases.)
    //   - Build and run.
    //   - In response to failing test(s), revise the implementation file.

    // Provided tests
    test_constructor();
    test_head_insert_and_basic_methods();

    // Student-generated tests
    test_tail_insert();
    test_clear();
    test_head_remove();
    test_tail_remove();
    test_contains();
    test_remove_first_of();

    // Provided tests
    test_assignment_operator();
    test_copy_constructor();

    // Student-generated test (optional extra credit)
    // test_bracket_indexing();

    cout << "All current tests are passing!" << endl << endl;

    return 0;
}	 	  	 	  	   	    	  	      	 	

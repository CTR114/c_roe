//  node1_test.cpp
//  Unit Tests for CS 223, Winter 2017, Lab 6 Part 1
//
//  <Chris Roe>

#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "Person.h"
#include "node1.h"

using namespace std;
using namespace main_savitch_5;

// Create some global Person objects to use in tests
Person default_person;
Person Mickey_Mouse("Mickey", "Mouse", 45);
Person Minnie_Mouse("Minnie", "Mouse", 45);
Person Peter_Pan("Peter", "Pan", 100);
Person Ziggy_Wilson("Ziggy", "Wilson", 5);
Person Skye_Wilson("Skye", "Wilson", 4);
Person Peter_Piper("Peter", "Piper", 0);
Person Dopey_Dwarf("Dopey", "Dwarf", 73);

// Reminder about node functionality:
//
// Retrieve the current data with `data()`
//    value_type data( ) const { return data_field; }
//
// Retrieve the current link with `link()`
//    const node* link( ) const { return link_field; }
//          node* link( )       { return link_field; }
//
// Set the data and link fields with `set_data` and `set_link`
//    void set_data(const value_type& new_data) { data_field = new_data; }	 	  	 	  	   	    	  	      	 	
//    void set_link(node* new_link)             { link_field = new_link; }

void test_constructor1()
{
    string test = "  constr.test.1: create new node with default constructor";
    cout << test << endl;

    // Setup: node n0
    node n0;

    // Assert: n0 was created correctly
    assert(n0.data() == default_person);
    assert(n0.link() == NULL);

}

void test_constructor2()
{
    string test = "  constr.test.2: create new node with 1-arg constructor";
    cout << test << endl;

    // Setup: node n1
    node n1(Mickey_Mouse);

    // Assert: n1 was created correctly
    assert(n1.data() == Mickey_Mouse);
    assert(n1.link() == NULL);
}

void test_constructor3()
{
    string test = "  constr.test.3: create new node with 2-arg constructor";
    cout << test << endl;

    // Setup: node n1, node n2 -> n1
    node n1(Mickey_Mouse);
    node n2(Ziggy_Wilson, &n1);

    // Assert: n2 was created correctly
    assert(n2.link() == &n1);
    assert(n2.link() -> data() == Mickey_Mouse);
}	 	  	 	  	   	    	  	      	 	

void test_set_data()
{
    string test = "  setdata.test.1: use set_data to change the data field of a node";  // NOLINT
    cout << test << endl;

    // Setup: node n1
    node n1(Ziggy_Wilson);

    // Execute: change data of n1
    n1.set_data(Peter_Pan);

    // Assert: n1 was changed correctly
    assert(n1.data() == Peter_Pan);
}

void test_set_link()
{
    string test = "  setlink.test.1: use set_link to change link field of a node";  // NOLINT
    cout << test << endl;

    // Setup: nodes n1, n2
    node n1(Ziggy_Wilson);
    node n2(Skye_Wilson);

    // Execute: change link of n2
    n2.set_link(&n1);  // n2 -> n1

    // Assert: n2 was changed correctly
    assert(n2.link() == &n1);
}

void test_const_link()
{
    string test = "  setlink.test.2: check const version of link()";
    cout << test << endl;

    // Setup: node ziggy, const node c_skye -> ziggy
    node ziggy(Ziggy_Wilson);
    node* zig_ptr = &ziggy;
    const node c_skye(Skye_Wilson, zig_ptr);

    // Assert: get link from const node c_skye
    assert(c_skye.link() -> data() == Ziggy_Wilson);
}	 	  	 	  	   	    	  	      	 	

void test_node_functions()
{
    cout << "\nTesting node functionality . . ." << endl;

    // Test 1: create a node with the default constructor
    test_constructor1();

    // Test 2: create a node with the 1-argument constructor
    test_constructor2();

    // Test 3: create a node with the 2-argument constructor
    test_constructor3();

    // Test 4: set the data field for a node
    test_set_data();

    // Test 5: set the link field for a node
    test_set_link();

    // Test 6: check the const version of link()
    test_const_link();

    cout << ". . . node functionality OK!" << endl << endl;
}
void test_list_length_and_head_insert1()
{
    //test1 test length of empty list
    node* head_ptr = NULL;
    assert(list_length(head_ptr) == 0);
    list_clear(head_ptr);
}
void test_list_length_and_head_insert2() 
{
    //test2:use head insert to add 1 node to list
    node* head_ptr = NULL;
    assert(list_length(head_ptr) == 0);
    //step 1 add a node to list
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    //step 2 make sure it is correctly added
    assert(head_ptr -> data() == Peter_Pan);
    assert(list_length(head_ptr) == 1);
    list_clear(head_ptr);
}	 	  	 	  	   	    	  	      	 	
void test_list_length_and_head_insert3()
{
    //test3 create a list of 4 nodes
    node* head_ptr = NULL;
    //create and check the node is in list
    assert(list_length(head_ptr) == 0);
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    assert(head_ptr -> data() == Peter_Pan);
    assert(list_length(head_ptr) == 1);
    // step 1 add another node and check to make sure it was added
    head_ptr = list_head_insert(head_ptr, Mickey_Mouse);
    assert(head_ptr -> data() == Mickey_Mouse);
    assert(list_length(head_ptr) == 2);
    // repeat step 1
    head_ptr = list_head_insert(head_ptr, Minnie_Mouse);
    assert(head_ptr -> data() == Minnie_Mouse);
    assert(list_length(head_ptr) == 3);
    //repeat step 1
    head_ptr = list_head_insert(head_ptr, Peter_Piper);
    assert(head_ptr -> data() == Peter_Piper);
    assert(list_length(head_ptr) == 4);
    list_clear(head_ptr);


}

void test_list_length_and_head_insert()
{
    cout << "\nTesting list_length and list_head_insert . . ." << endl;
    //test 1:
    test_list_length_and_head_insert1();
    cout << "test_list_length_and_head_insert1 passed.. empty list \n";
    test_list_length_and_head_insert2();
    cout << "test_list_length_and_head_insert2 passed... added 1 \n";
    test_list_length_and_head_insert3();
    cout << "test_list_length_and_head_insert3 passed... added 4  \n";
    cout << ". . . list_length and list_head_insert OK!" << endl << endl;
}	 	  	 	  	   	    	  	      	 	

void test_list_insert1()
{
   //test1 
    node* head_ptr = NULL;
    // step1 create a node
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    //create a temp to hold nodes
    node* temp = head_ptr;
    // step 3 insert node after first node
    list_insert(temp,Mickey_Mouse);
    // check to make sure a node was added
    assert(list_length(head_ptr)== 2);
    // make sure they are they are holding correct values
    assert(head_ptr -> data() == Peter_Pan);
    assert(head_ptr -> link() -> data()== Mickey_Mouse);
    list_clear(head_ptr);
}
void test_list_insert2()
{
    //test 2- insert a node into a list of 5
    node* head_ptr = NULL;
    // step1 create 4 nodes
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    head_ptr = list_head_insert(head_ptr, Peter_Piper);
    head_ptr = list_head_insert(head_ptr, Mickey_Mouse);
    head_ptr = list_head_insert(head_ptr, Minnie_Mouse);
    assert(list_length(head_ptr) == 4);
    //create a temp to hold the nodes place
    node* temp = head_ptr;
    // step 3 insert node 
    list_insert(head_ptr,Dopey_Dwarf);
    // check to make sure a node was added
    assert(list_length(head_ptr)== 5);
    // make sure they are they are holding correct values
    assert(head_ptr -> data() == Minnie_Mouse);
    assert(head_ptr -> link() -> data() == Dopey_Dwarf);
    list_clear(head_ptr);
    
}	 	  	 	  	   	    	  	      	 	

void test_list_insert3()
{
     //test1 
    node* head_ptr = NULL;
    // step1 create a node
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    //create a temp to hold node
    node* temp = head_ptr;
    // step 3 insert node after first node
    list_insert(temp,Mickey_Mouse);
     list_insert(temp,Peter_Piper);
    // check to make sure a node was added
    assert(list_length(head_ptr)== 3);
    // make sure they are they are holding correct values
    assert(head_ptr -> data() == Peter_Pan);
    assert(head_ptr -> link() -> data()== Peter_Piper);
    assert(head_ptr -> link() -> link() -> data()== Mickey_Mouse);
    list_clear(head_ptr);
}



void test_list_insert()
{
    cout << "\nTesting list_insert . . ." << endl;

    test_list_insert1();
    cout << "test 1 passed.... added 1 to list of 1 \n";
    test_list_insert2();
    cout << "test 2 passed... added 1 to list of 4 \n";
    test_list_insert3();
    cout << "test 3 passed... added 2 to list of 1 \n";
    cout << ". . . list_insert OK!" << endl << endl;
  
}	 	  	 	  	   	    	  	      	 	

void test_search1()
{
    string test = "  search.test.1: empty list";
    cout << test << endl;

    // Setup: create empty list
    node* head = NULL;

    // Execute: search for Dopey
    node* result = list_search(head, Dopey_Dwarf);

    // Assert: nothing was found
    assert(result == NULL);

    // Testing const version
    // Setup: create empty list
    const node* c_head = &(*head);

    // Execute: search for Dopey
    const node* c_result = list_search(c_head, Dopey_Dwarf);

    // Assert: nothing was found
    assert(c_result == NULL);
    
}

void test_search2()
{
    string test = "  search.test.2: list of length 1, item is found";
    cout << test << endl;

    // Setup: create list with 1 item
    node* head = NULL;
    head = list_head_insert(head, Ziggy_Wilson);

    // Execute: search for Ziggy
    node* result = list_search(head, Ziggy_Wilson);

    // Assert: Ziggy was found
    assert(result != NULL);
    assert(result -> data() == Ziggy_Wilson);

    // Testing const version
    // Setup: create list with 1 item
    const node* c_head = &(*head);

    // Execute: search for Ziggy
    const node* c_result = list_search(c_head, Ziggy_Wilson);

    // Assert: Ziggy was found
    assert(c_result != NULL);
    assert(c_result -> data() == Ziggy_Wilson);
    
}	 	  	 	  	   	    	  	      	 	

void test_search3()
{
    string test = "  search.test.3: list of length 1, item not found";
    cout << test << endl;

    // Setup: create list with 1 item
    node* head = NULL;
    head = list_head_insert(head, Ziggy_Wilson);

    // Execute: search for Skye_Wilson
    node* result = list_search(head, Skye_Wilson);

    // Assert: Skye was not found
    assert(result == NULL);

    // Testing const version
    // Setup: create list with 1 item
    const node* c_head = &(*head);

    // Execute: search for Skye_Wilson
    const node* c_result = list_search(c_head, Skye_Wilson);

    // Assert: Skye was not found
    assert(c_result == NULL);
    
}

void test_search4()
{
    string test = "  search.test.4: list of length 3, item not found";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: search for Skye Wilson
    node* result = list_search(head, Skye_Wilson);

    // Assert: Skye was not found
    assert(result == NULL);

    // Testing const version
    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    const node* c_head = &(*head);

    // Execute: search for Skye Wilson
    const node* c_result = list_search(c_head, Skye_Wilson);

    // Assert: Skye was not found
    assert(c_result == NULL);
    
}	 	  	 	  	   	    	  	      	 	

void test_search5()
{
    string test = "  search.test.5: list of length 3, item is first in list";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: search for Minnie
    node* result = list_search(head, Minnie_Mouse);

    // Assert: Minnie was found
    assert(result != NULL);
    assert(result -> data() == Minnie_Mouse);

    // Testing const version
    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    const node* c_head = &(*head);

    // Execute: search for Minnie
    const node* c_result = list_search(c_head, Minnie_Mouse);

    // Assert: Minnie was found
    assert(c_result != NULL);
    assert(c_result -> data() == Minnie_Mouse);
    
}

void test_search6()
{
    string test = "  search.test.6: list of length 3, item is second in list";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: search for Peter_Pan
    node* result = list_search(head, Peter_Pan);

    // Assert: Peter_Pan was found
    assert(result != NULL);
    assert(result -> data() == Peter_Pan);

    // Testing const version
    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    const node* c_head = &(*head);

    // Execute: search for Peter_Pan
    const node* c_result = list_search(c_head, Peter_Pan);

    // Assert: Peter_Pan was found
    assert(c_result != NULL);
    assert(c_result -> data() == Peter_Pan);
    
}	 	  	 	  	   	    	  	      	 	

void test_search7()
{
    string test = "  search.test.8: list of length 3, item is last in list";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: search for Mickey
    node* result = list_search(head, Mickey_Mouse);

    // Assert: Mickey_Mouse was found
    assert(result != NULL);
    assert(result -> data() == Mickey_Mouse);

    // Testing const version
    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    const node* c_head = &(*head);

    // Execute: search for Mickey
    const node* c_result = list_search(c_head, Mickey_Mouse);

    // Assert: Mickey_Mouse was found
    assert(c_result != NULL);
    assert(c_result -> data() == Mickey_Mouse);
 
}

void test_search8()
{
    string test = "  search.test.8: list of length 3, item has duplicates";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Peter_Pan
    node* head = NULL;
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: search for Peter_Pan
    node* result = list_search(head, Peter_Pan);

    // Assert: first Peter_Pan was found
    assert(result != NULL);
    assert(result -> data() == Peter_Pan);
    assert(result -> link() -> data() == Peter_Pan);

    // Testing const version
    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Peter_Pan
    const node* c_head = &(*head);

    // Execute: search for Peter_Pan
    const node* c_result = list_search(c_head, Peter_Pan);

    // Assert: first Peter_Pan was found
    assert(c_result != NULL);
    assert(c_result -> data() == Peter_Pan);
    assert(c_result -> link() -> data() == Peter_Pan);
    
}	 	  	 	  	   	    	  	      	 	

void test_list_search()
{
    cout << "\nTesting list_search, both versions . . ." << endl;

    // Test 1: search an empty list
    test_search1();

    // Test 2: search a list of length 1, item is found
    test_search2();

    // Test 3: search a list of length 1, item not found
    test_search3();

    // Test 4: search a list of length 3, item not found
    test_search4();

    // Test 5: search a list of length 3, item is first in list
    test_search5();

    // Test 6: search a list of length 3, item is second in list
    test_search6();

    // Test 7: search a list of length 3, item is last in list
    test_search7();

    // Test 8: search a list of length 3, item has duplicates
    test_search8();

    cout << ". . . list_search OK!" << endl << endl;
}

void test_locate1()
{
    string test = "  locate.test.1: locate non-exist item in an empty list";
    cout << test << endl;

    // Setup: create empty list
    node* head = NULL;

    // Execute: locate 1st item
    node* result = list_locate(head, 1);

    // Assert: nothing was found
    assert(result == NULL);

    // Testing const version
    // Setup: create empty list
    const node* c_head = &(*head);

    // Execute: locate 1st item
    const node* c_result = list_locate(c_head, 1);

    // Assert: nothing was found
    assert(c_result == NULL);
  
}	 	  	 	  	   	    	  	      	 	

void test_locate2()
{
    string test = "  locate.test.2: locate first item in list of length 1";
    cout << test << endl;

    // Setup: create list with 1 item
    node* head = NULL;
    head = list_head_insert(head, Ziggy_Wilson);

    // Execute: locate 1st item
    node* result = list_locate(head, 1);

    // Assert: 1st item (Ziggy) was found
    assert(result != NULL);
    assert(result -> data() == Ziggy_Wilson);

    // Testing const version
    // Setup: create list with 1 item
    const node* c_head = &(*head);

    // Execute: locate 1st item
    const node* c_result = list_locate(c_head, 1);

    // Assert: 1st item (Ziggy) was found
    assert(c_result != NULL);
    assert(c_result -> data() == Ziggy_Wilson);
    
}

void test_locate3()
{
    string test = "  locate.test.3: locate non-exist item in list of length 1";
    cout << test << endl;

    // Setup: create list with 1 item
    node* head = NULL;
    head = list_head_insert(head, Ziggy_Wilson);

    // Execute: locate 2nd item
    node* result = list_locate(head, 2);

    // Assert: no 2nd item, so result should be null
    assert(result == NULL);

    // Testing const version
    // Setup: create list with 1 item
    const node* c_head = &(*head);

    // Execute: locate 2nd item
    const node* c_result = list_locate(c_head, 2);

    // Assert: no 2nd item, so result should be null
    assert(c_result == NULL);

}	 	  	 	  	   	    	  	      	 	

void test_locate4()
{
    string test = "  locate.test.4: locate first item in list of length 3";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: locate 1st item
    node* result = list_locate(head, 1);

    // Assert: 1st item (Minnie) was found
    assert(result != NULL);
    assert(result -> data() == Minnie_Mouse);

    // Testing const version
    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    const node* c_head = &(*head);

    // Execute: locate 1st item
    const node* c_result = list_locate(c_head, 1);

    // Assert: 1st item (Minnie) was found
    assert(c_result != NULL);
    assert(c_result -> data() == Minnie_Mouse);
   
}

void test_locate5()
{
    string test = "  locate.test.5: locate middle item in list of length 3";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: locate 2nd item
    node* result = list_locate(head, 2);

    // Assert: 2nd item (Peter_Pan) was found
    assert(result != NULL);
    assert(result -> data() == Peter_Pan);

    // Testing const version
    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    const node* c_head = &(*head);

    // Execute: locate 2nd item
    const node* c_result = list_locate(c_head, 2);

    // Assert: 2nd item (Peter_Pan) was found
    assert(c_result != NULL);
    assert(c_result -> data() == Peter_Pan);

}	 	  	 	  	   	    	  	      	 	

void test_locate6()
{
    string test = "  locate.test.6: locate last item in list of length 3";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: locate 3rd item in list
    node* result = list_locate(head, 3);

    // Assert: 3rd item (Mickey_Mouse) was found
    assert(result != NULL);
    assert(result -> data() == Mickey_Mouse);

    // Testing const version
    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    const node* c_head = &(*head);

    // Execute: locate 3rd item in list
    const node* c_result = list_locate(c_head, 3);

    // Assert: 3rd item (Mickey_Mouse) was found
    assert(c_result != NULL);
    assert(c_result -> data() == Mickey_Mouse);
 
}

void test_list_locate()
{
    cout << "\nTesting list_locate, both versions . . ." << endl;

    // Test 1: locate 1st item in an empty list
    test_locate1();

    // Test 2: locate 1st item in a list of length 1
    test_locate2();

    // Test 3: locate 2nd item in a list of length 1
    test_locate3();

    // Test 4: locate 1st item in a list of length 3
    test_locate4();

    // Test 5: locate 2nd item in a list of length 3
    test_locate5();

    // Test 6: locate 3rd item in a list of length 3
    test_locate6();

    cout << ". . . list_locate OK!" << endl << endl;
}	 	  	 	  	   	    	  	      	 	

void test_list_head_remove1()
{
    //test 1- create a head ptr and then delete it (list of 2)
    node* head_ptr = NULL;
    //step 1 create the node
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    //step 2 get a baseline length
    assert(list_length(head_ptr) == 1);
    //step4 remove the head_ptr
    head_ptr = list_head_remove(head_ptr);
    //step 5 check to see if it removed the head_ptr
    assert(list_length(head_ptr) == 0);
    list_clear(head_ptr);
}

void test_list_head_remove2()
{
    //test2- remove head_ptr from list of 3
    node* head_ptr = NULL;
    //step1- create list of 3
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    head_ptr = list_head_insert(head_ptr, Mickey_Mouse);
    head_ptr = list_head_insert(head_ptr, Minnie_Mouse);
    //step2 check to make sure length is 3
    assert(list_length(head_ptr) == 3);\
    //step3 remove the head_ptr
    head_ptr = list_head_remove(head_ptr);
    //step4 Make sure length changed to 2
    assert(list_length(head_ptr) == 2);
    //step 5 make sure the new head_ptr is right
    assert(head_ptr -> data() == Mickey_Mouse);
    list_clear(head_ptr);
}
void test_list_head_remove()
{	 	  	 	  	   	    	  	      	 	
    cout << "\nTesting list_head_remove . . ." << endl;

    test_list_head_remove1();
    cout << "Test1 passed removed head_ptr from list of 1 \n";
    test_list_head_remove2();\
    cout << "test 2 passed removed head_ptr from list of 3 \n"; 
    cout << ". . . list_head_remove OK!" << endl << endl;
}

void test_list_remove1()
{
    //test 1 create a list of 3 and remove 1 from it
    node* head_ptr = NULL;
    assert(list_length(head_ptr) == 0);
    //step 1 add the nodes to list
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    head_ptr = list_head_insert(head_ptr, Mickey_Mouse);
    head_ptr = list_head_insert(head_ptr, Minnie_Mouse);
    //step 2 make sure it is correctly added
    assert(list_length(head_ptr) == 3);
    // create a pointer pointing to a node to remove item in list (Mickey)
    node* temp = head_ptr; 
    //remove that node
    list_remove(temp);
    // check to make sure deleted correct node
    assert(list_length(head_ptr) == 2);
    assert(head_ptr -> data()== Minnie_Mouse);
    assert(head_ptr -> link() -> data() == Peter_Pan);
    list_clear(head_ptr);
}

void test_list_remove2()
{
    // test2 create a list of 5 items and delete 3rd one
    node* head_ptr = NULL;
    assert(list_length(head_ptr) == 0);
    //step 1 add the nodes to list
    head_ptr = list_head_insert(head_ptr, Peter_Pan);
    head_ptr = list_head_insert(head_ptr, Mickey_Mouse);
    head_ptr = list_head_insert(head_ptr, Minnie_Mouse);
    head_ptr = list_head_insert(head_ptr, Ziggy_Wilson);
    head_ptr = list_head_insert(head_ptr, Skye_Wilson);
    //step 2 make sure it is correctly added
    assert(list_length(head_ptr) == 5);
    // create a pointer pointing to a node to remove 3rd item in list (Minnie)
    node* temp = head_ptr -> link();
    //remove that node
    list_remove(temp);
    // check to make sure deleted correct node
    assert(list_length(head_ptr) == 4);
    assert(head_ptr -> data()== Skye_Wilson);
    assert(head_ptr -> link() -> data() == Ziggy_Wilson);
    assert(head_ptr -> link() -> link() -> data() == Mickey_Mouse);
    assert(head_ptr -> link() ->  link() -> link() -> data() == Peter_Pan);
    list_clear(head_ptr);
}	 	  	 	  	   	    	  	      	 	

void test_list_remove()
{
    cout << "\nTesting list_remove . . ." << endl;
    test_list_remove1();
    cout<< "Test 1 passed.... removed a node from list of 3 \n";
    test_list_remove2();
    cout<< "Test 2 passed.. removed node 3 from list of 5 \n";

 cout << ". . . list_remove OK!" << endl << endl;
}

void test_clear1()
{
    string test = "  clear.test.1: clear an empty list";
    cout << test << endl;

    // Setup: create list
    node* head = NULL;

    // Execute: clear the list
    list_clear(head);

    // Assert: list is still empty
    assert(list_length(head) == 0);
    
}

void test_clear2()
{
    string test = "  clear.test.2: clear a list of length 1";
    cout << test << endl;

    // Setup: create list
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);

    // Execute: clear the list
    list_clear(head);

    // Assert: list is empty
    assert(list_length(head) == 0);
    
}	 	  	 	  	   	    	  	      	 	

void test_clear3()
{
    string test = "  clear.test.3: clear a list of length 3";
    cout << test << endl;

    // Setup: create list: head -> Minnie_Mouse -> Peter_Pan -> Mickey_Mouse
    node* head = NULL;
    head = list_head_insert(head, Mickey_Mouse);
    head = list_head_insert(head, Peter_Pan);
    head = list_head_insert(head, Minnie_Mouse);

    // Execute: clear the list
    list_clear(head);

    // Assert: list is empty
    assert(list_length(head) == 0);

}

void test_list_clear()
{
    cout << "\nTesting list_clear . . ." << endl;

    // Test 1: clear an already empty list
    test_clear1();

    // Test 2: clear a list of length 1
    test_clear2();

    // Test 3: clear a list of length 3
    test_clear3();

    cout << ". . . list_clear OK!" << endl << endl;
}

int main()
{	 	  	 	  	   	    	  	      	 	
    test_node_functions();
    test_list_length_and_head_insert();
    test_list_insert();
    test_list_search();
    test_list_locate();
    test_list_head_remove();
    test_list_remove();
    test_list_clear();

    return 0;
}

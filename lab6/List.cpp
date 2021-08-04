// FILE: List.cpp
// CS 223 Winter 2017, Lab 6, Part 2
//
// Student Name: Chris Roe
// Date: march 11
//
// List class implementation for a circular DLL with sentinel node.
//
// Instance data:  Every List has a pointer (called "head_ptr") to its sentinel
//    node.
//
// Class invariants:
//    1. All the list nodes, including the sentinel node, are stored in dynamic
//       memory.
//    2. The head pointer for the list ALWAYS points to the sentinel node.
//    3. The sentinel node's data is always the default value for
//       DLL_node::value_type.
//    4. For an EMPTY list, the sentinel node's links (prev, next) refer to
//       the sentinel node itself.
//
// NOTE 1: The DLL_node class is already completely implemented in DLL_node.h.
//
// NOTE 2: Use `DLL_node::value_type` to refer to the type of data stored in
//         a node.
//

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
#include "Person.h"
#include "DLL_node.h"
#include "List.h"

using namespace std;
using namespace lab6_part2;

 // ***** Basic Member Functions *****

    // default constructor
    // Postcondition: the list has no items (just a sentinel node)
    List::List() 
    {	 	  	 	  	   	    	  	      	 	
    	head_ptr = new DLL_node;
    	head_ptr -> set_next(head_ptr);
    	head_ptr -> set_prev(head_ptr);
    }

    // is_empty
    // checks if the list is empty
    // Postcondition: Returns true iff there are no items in the list.
    bool List::is_empty() const 
    {
    	if ( head_ptr -> next() == head_ptr)
    	{
    		return true;
    	}
    	return false;
    }

    // clear
    // deletes all items from the list
    // Postcondition: List is empty.
    void List::clear()
	{

     	while (!(is_empty()))
     	{
        	head_remove();
    	}
	}

    // List::front
    // get the value at the front of the list
    // Precondition: This list is not empty.
    // Postcondition: Return value is a copy of the value stored at
    //    the front of the list.
    DLL_node::value_type List::front() const
    {	 	  	 	  	   	    	  	      	 	
    	if (is_empty() == false)
    	{
    		return (head_ptr -> next() -> data());
    	}
    }	

    // List::back
    // get the value at the end of the list
    // Precondition: This list is not empty.
    // Postcondition: Return value is a copy of the value stored at
    //    the back of the list.
    DLL_node::value_type List::back() const
    {
    	if (is_empty() == false)
    	{
    		return (head_ptr -> prev() -> data());
    	}

    }

    // List::head_insert
    // add an item to the front of the list
    // Postcondition: The list has one more node than before, and the
    //    value `val` is stored at the front of the list.
    // EXAMPLE: If the list had items:  <r, o, n, t>, and then the call was
    //    to head_insert('f'), the list now has items: <f, r, o, n, t>
    void List::head_insert(DLL_node::value_type val)
    {
    	DLL_node* temp = new DLL_node;
    	temp -> set_data(val);
    	temp -> set_prev(head_ptr);
    	head_ptr -> next() -> set_prev(temp);
    	temp -> set_next(head_ptr -> next());
    	head_ptr -> set_next(temp);
  
    }	 	  	 	  	   	    	  	      	 	

    // add an item to the end of the list
    // Postcondition: The list has one more node than before, and the
    //    value `val` is stored at the end of the list.
    // EXAMPLE: If the list had items:  <p, i, g>, and then the call was
    //    to tail_insert('g'), the list now has items: <p, i, g
    void List::tail_insert(DLL_node::value_type val)
    {
    	DLL_node *temp = new DLL_node;
    	temp -> set_data(val);
    	temp -> set_next(head_ptr);
    	temp -> set_prev(head_ptr -> prev());
    	head_ptr -> prev() -> set_next(temp);
    	if (head_ptr -> next() == head_ptr)
    	{
    		head_ptr -> set_next(temp);
    	}
    	head_ptr -> set_prev(temp);
    }


// ***** Other Member Functions *****


    // tail_remove
    // remove an item from the end of the list
    // Postcondition:  Return value is `true` iff an item was removed.
    //    If the list was empty before tail_remove(), return value is
    //    `false`.
    // EXAMPLE:  If the list had items <c, a, t, s> before the call to
    //    tail_remove(), after the call the list has: <c, a, t>
    bool List::tail_remove()
    {
    	if (is_empty())
    	{
    		return false;
    	}	 	  	 	  	   	    	  	      	 	
    	else
    	{
    		DLL_node* temp = head_ptr -> prev();
    		head_ptr -> set_prev(temp -> prev());
    		temp -> prev() -> set_next(head_ptr);
    		
    		delete temp;
    		return true;
    	}

    }

    // contains
    // checks for an item in the list
    // Postcondition: Returns true iff there is an item equivalent to
    //    `val` in this list.
    bool List::contains(DLL_node::value_type val) const
    {
    	DLL_node* temp = head_ptr -> next();
    	while ( temp != head_ptr)
    	{
    		if (temp -> data() == val)
    		{
    			return true;
    		}
    		temp = temp -> next();
    	}
    	return false;
    }

    // remove_first_of
    // tries to remove the first instance of an item from the list
    // Postcondition: Removes the front-most item in the list that is
    //    equivalent (==) to the given value `val`.  Return value is
    //    true iff an item was removed from the list.
    // NOTE: If no item in the list is equivalent to `val`, the list
    //    is unchanged and `false` is returned.
    // EXAMPLE: The list has items: <2, 9, 2>.  A call to
    //    remove_first_of('2') will return true, and the list items
    //    are now: <9, 2>
    bool List::remove_first_of(DLL_node::value_type val)
    {	 	  	 	  	   	    	  	      	 	
    	DLL_node* temp = head_ptr -> next();
    	while (temp != head_ptr)
    	{
    		if (temp -> data() == val)
    		{
    			temp -> prev() -> set_next( temp -> next());
    			temp -> next() -> set_prev( temp -> prev());
    			delete temp;
    			return true;
    		}
    		temp = temp -> next();
    	}
    	return false;
    }


    // head_remove
    // remove an item from the front of the list
    // Postcondition:  Return value is `true` iff an item was removed.
    //    If the list was empty before head_remove(), return value is
    //    `false`.
    // EXAMPLE:  If the list had items <f, r, o, g> before the call to
    //    head_remove(), after the call the list has: <r, o, g>
    bool List::head_remove()
    {
    	if (is_empty())
    	{
    		return false;
    	}
    	else
    	{
    		DLL_node* temp = head_ptr -> next();
    		head_ptr -> set_next(temp -> next());
    		temp -> next() -> set_prev(head_ptr);
    		delete temp;
    		return true;
    	}	 	  	 	  	   	    	  	      	 	
    }


//***** Copy Constructor and Assignment Operator *****

    // copy constructor
    // Postcondition: The new list is an independent copy of `other`.
    //    Subsequent changes to one of the lists will *not* affect the
    //    other list.
    List::List(const List &other)
    {
    	head_ptr = new DLL_node;
    	head_ptr -> set_next(head_ptr);
    	head_ptr -> set_prev(head_ptr);
    	DLL_node* curr = other.head_ptr;
    	while (curr -> next() != other.head_ptr)
    	{
    		curr = curr -> next();
    		tail_insert(curr -> data());
    	}
    }

    // assignment operator
    // Postcondition: This list becomes an identical -- but indepedent --
    //    copy of `other` list.
    // NOTE: Returns the updated list to enable chaining of assignment.
    List& List::operator=(const List &other)
    {
    	if ( head_ptr != other.head_ptr)
    	{
    		clear();
    		DLL_node* temp = other.head_ptr;
    		while( temp -> next() != other.head_ptr)
    		{
    			temp = temp -> next();
    			tail_insert(temp -> data());

    		}	 	  	 	  	   	    	  	      	 	
    	}

    }
    // //  destructor - test it indirectly by checking for memory leaks
    List::~List()
    {
    	this -> clear();
     	delete head_ptr;
    }
     	






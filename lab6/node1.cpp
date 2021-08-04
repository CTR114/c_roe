// FILE: node1.cpp
// CS 223 Winter 2017, Lab 6 Part 1
//
//  <Chris Roe March 7>
//
// IMPLEMENTS the functions of the linked list toolkit (see node1.h for
// documentation).
//
// NOTE: The node class is already implemented in node1.h.
//
// INVARIANT for the node class: The data of a node is stored in data_field,
//    and the link is stored in link_field.
//
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "node1.h"

using namespace std;

namespace main_savitch_5 
{

 // end namespace main_savitch_5

// FUNCTIONS in the Linked List Toolkit:
//
  size_t list_length(const node* head_ptr)
  {
  	const node* cursor;
  	size_t answer;
  	answer = 0;
  	for (cursor = head_ptr; cursor !=NULL; cursor = cursor -> link())
  	{
  		++answer;
  	}	 	  	 	  	   	    	  	      	 	
  	return answer;
  }


  node* list_head_insert(node* head_ptr, const node::value_type& entry)
  {
  	head_ptr = new node(entry,head_ptr);

  }


  void list_insert(node* previous_ptr, const node::value_type& entry)
  {
  	node* insert_ptr;

    insert_ptr = new node;
  	insert_ptr -> set_data(entry);
  	insert_ptr -> set_link(previous_ptr->link());
  	previous_ptr -> set_link(insert_ptr);

  }

  const node* list_search(const node* head_ptr,const node::value_type& target)
  {
  	const node* cursor;
  	for (cursor = head_ptr;cursor !=NULL;cursor = cursor -> link())
  	{
  		if (target == cursor -> data())
  		{
  			return cursor;
  		}
  	}
  	return NULL;
  }

  node* list_search(node* head_ptr, const node::value_type& target)
  {	 	  	 	  	   	    	  	      	 	
  	node* cursor;
  	for (cursor = head_ptr;cursor !=NULL;cursor = cursor -> link())
  	{
  		if (target == cursor -> data())
  		{
  			return cursor;
  		}
  	}
  	return NULL;
  }


  const node* list_locate(const node* head_ptr, size_t position)
  {
    const node* cursor;
    size_t i;
    assert(0 < position);
    cursor = head_ptr;
    for (i = 1; (i < position) && (cursor != NULL);i++)
    {
      cursor = cursor -> link();
    }
    return cursor;

  }
  node* list_locate(node* head_ptr, size_t position)
  {
    node* cursor;
    size_t i;
    assert(0 < position);
    cursor = head_ptr;
    for (i = 1; (i < position) && (cursor != NULL); i++)
    {
      cursor = cursor -> link();
    }
    return cursor;
  }	 	  	 	  	   	    	  	      	 	

  node* list_head_remove(node* head_ptr)
  {
  	node* remove_ptr;
  	remove_ptr = head_ptr;
  	head_ptr = head_ptr -> link();
  	delete remove_ptr;
    return head_ptr;

  }

  void list_remove(node* previous_ptr)
  {
  	node* remove_ptr;

  	remove_ptr = previous_ptr -> link();
  	previous_ptr -> set_link(remove_ptr -> link());
  	delete remove_ptr;

  }

 void list_clear(node*& head_ptr)
 {
    while (head_ptr !=NULL)
    {
      head_ptr = list_head_remove(head_ptr);
    }
 }

}
	 	  	 	  	   	    	  	      	 	

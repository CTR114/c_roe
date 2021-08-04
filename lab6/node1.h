// FILE: node1.h
// Header file for Lab 6 Part 1, CS 223, Winter 2016
// Modified version of the node1.h file provided by Main/Savitch, Chap. 5
// Barb Wahl, 2-13-16
// Theresa Wilson, 3-3-17
//
//
// ********** DO NOT CHANGE THIS FILE **********
//
// PROVIDES: A class for a node in a linked list, and list manipulation
//   functions, all within the namespace main_savitch_5
//
// TYPEDEF for the node class:
//    Each node of the list contains an item of data and a pointer to the
//    next node. The type of the data is defined as node::value_type in a
//    typedef statement. The value_type may be any of the built-in C++ classes
//    (int, char, ...) or a class with a copy constructor, an assignment
//    operator, and a test for equality (operator==).
//
// CONSTRUCTOR for the node class: Takes two parameters, `init_data` and
//    `init_link` (for initializing the node), and provides default values
//    for both parameters
//
//    node(const value_type& init_data = value_type(),
//         node* init_link = NULL )
//
//    Postcondition: The node contains the specified data and link.
//    NOTE: The default value for init_data is obtained from the
//          call to value_type(), which is an alias for the default
//          constructor / value initializer for the type represented
//          by value_type.
//
// ************************************************************************
// NOTE: Some of the following functions have a return value which is a
//       pointer to a node (node*).  Each of these functions comes in two
//       versions:
//         - a const version, where the return type is const node*
//         - a non-const version, where the return type is node*.
//
//    EXAMPLES:
//       const node * c;
//       c->link() // activates the const version of link on the node
//                    referenced by c, since c is const
//       list_search(c,... // calls the const version of list_search
//
//       node * p;
//       p->link() // activates the non-const version of link on the node
//                    referenced by p, since p is not const
//       list_search(p,... // calls the non-const version of list_search
//
// ************************************************************************
//
// MEMBER FUNCTIONS for the node class:
//  void set_data(const value_type& new_data)
//    Postcondition: The node now contains the specified new data.
//
//  void set_link(node* new_link)
//    Postcondition: The node now contains the specified new link.
//
//  value_type data() const
//    Postcondition: The return value is the data from this node.
//
//  const node* link() const  <----- const version
//  node* link()  <----------------- non-const version
//    See the note (above) about the const version and non-const versions.
//    Postcondition: The return value is the link from this node.
//
// ************************************************************************
//
// FUNCTIONS in the Linked List Toolkit:
//
//  size_t list_length(const node* head_ptr)
//    Precondition: head_ptr is the head pointer of a linked list.
//    Postcondition: The value returned is the number of nodes in the 
//       linked list.
//
//  node* list_head_insert(node* head_ptr, const node::value_type& entry)
//    Precondition: head_ptr is the head pointer of a linked list.
//    Postcondition: A new node containing the given entry has been added 
//       at the head of the linked list; returns a pointer to the head of 
//       the new, longer linked list.
//
//  void list_insert(node* previous_ptr, const node::value_type& entry)
//    Precondition: previous_ptr points to a node in a linked list.
//    Postcondition: A new node containing the given entry has been added
//       after the node that previous_ptr points to.
//
//  const node* list_search(const node* head_ptr, 
//                          const node::value_type& target)
//  node* list_search(node* head_ptr, const node::value_type& target)
//    See the note (above) about the const version and non-const versions.
//    Precondition: head_ptr is the head pointer of a linked list.
//    Postcondition: The pointer returned points to the first node containing
//       the specified target in its data member. If there is no such node, the
//       null pointer is returned.
//
//  const node* list_locate(const node* head_ptr, size_t position)
//  node* list_locate(node* head_ptr, size_t position)
//    See the note (above) about the const version and non-const versions.
//    Precondition: head_ptr is the head pointer of a linked list, and
//       position > 0.
//    Postcondition: The pointer returned points to the node at the specified
//       position in the list. If there is no such position, then the null
//       pointer is returned.
//    IMPORTANT NOTE:  The head node is position 1 -- NOT POSITION ZERO!
//       The node pointed to by the head node is position 2, and so on.
//
//  node* list_head_remove(node* head_ptr)
//    Precondition: head_ptr is the head pointer of a linked list, with at
//       least one node.
//    Postcondition: The head node has been removed and returned to the heap;
//       returns a pointer to the head of the new, shorter linked list.
//
//  void list_remove(node* previous_ptr)
//    Precondition: previous_ptr points to a node in a linked list, and this
//       is not the tail node of the list.
//    Postcondition: The node after previous_ptr has been removed from the
//       linked list.
//
//  void list_clear(node*& head_ptr)
//    Precondition: head_ptr is the head pointer of a linked list.
//    Postcondition: List pointed to by head_ptr is empty (head_ptr is NULL).
//        
// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc:
//      - node constructor
//      - list_head_insert
//      - list_insert

#ifndef MAIN_SAVITCH_NODE1_H
#define MAIN_SAVITCH_NODE1_H
#include <cstdlib>    // Provides size_t and NULL
#include "Person.h"   // so we can store Person data

namespace main_savitch_5 {

class node
{
 public:
    // TYPEDEF
    typedef Person value_type;  // NOTE CHANGE from textbook version

    // CONSTRUCTOR
    node(const value_type& init_data = value_type(),
         node* init_link = NULL)
    { data_field = init_data; link_field = init_link; }

    // Member functions to set the data and link fields:
        void set_data(const value_type& new_data) { data_field = new_data; }
        void set_link(node* new_link)             { link_field = new_link; }

    // Constant member function to retrieve the current data:
    value_type data() const { return data_field; }

    // Two slightly different member functions to retrieve the current link:
    const node* link() const { return link_field; }
          node* link()       { return link_field; }

 private:
    value_type data_field;
    node* link_field;
};  // end node class

// FUNCTIONS for the linked list toolkit
std::size_t list_length(const node* head_ptr);
node* list_head_insert(node* head_ptr, const node::value_type& entry);
void list_insert(node* previous_ptr, const node::value_type& entry);
node* list_search(node* head_ptr, const node::value_type& target);
const node* list_search(const node* head_ptr, const node::value_type& target);
node* list_locate(node* head_ptr, std::size_t position);
const node* list_locate(const node* head_ptr, std::size_t position);
node* list_head_remove(node* head_ptr);
void list_remove(node* previous_ptr);
void list_clear(node*& head_ptr);  // NOLINT We're allowing this. TW/BW

}  // end namespace main_savitch_5

#endif

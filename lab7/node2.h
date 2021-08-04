// FILE: node2.h
// Header file for Lab 7 Part 2, CS 223
// Modified version of the node2.h file provided by Main/Savitch, Chap. 6
// Theresa Wilson, 3-11-16
// Updated by Barb Wahl, 3-12-2017
//
// ********** DO NOT CHANGE THIS FILE **********
//
// PROVIDES: A class for a node in a linked list, and list manipulation
//    functions, all within the namespace main_savitch_6B. The template
//    parameter is the type of the data in each node.
//
// TYPEDEF for the node<Item> template class:
//    Each node of the list contains an item of data and a pointer to the
//    next node. The type of the data (node<Item>::value_type) is the Item
//    type from the template parameter. The type may be any of the built-in
//    C++ classes (int, char, ...) or a class with a default constructor,
//    an assignment operator, and a test for equality (x == y).
//
//    NOTE: Many compilers require the use of the keyword `typename` before
//          using the expression node<Item>::value_type. Otherwise the
//          compiler doesn't have enough information to realize that it
//          is the name of a data type.
//
// CONSTRUCTOR for the node<Item> template class:
//    Takes two parameters, `init_data` and `init_link` (for initializing
//    the node), and provides default values for both parameters
//
//       explicit node(const Item& init_data = Item(), node* init_link = NULL)
//
//    Postcondition: The node contains the specified data and link.
//
//    NOTE: The default value for init_data is obtained from the call to
//          Item(), which is an alias for the default constructor / value
//          initializer for the type represented Item.
//
// ************************************************************************
// NOTE: The data function returns a reference to the data field of a node,
//       and the link function returns a copy of the link field of a node.
//       Each of these functions comes in two versions: a const version and
//       a non-const version. If the function is activated by a const node,
//       then the compiler choses the const version (and the return value
//       is const).  If the function is activated by a non-const node, then
//       the compiler choses the non-const version (and the return value
//       will be non-const).
//
//    EXAMPLES:
//       const node<int> *c;
//       c->link() activates the const version of link returning const node*
//       c->data() activates the const version of data returning const Item&
//       c->data() = 42; ... is forbidden
//
//       node<int> *p;
//       p->link() activates the non-const version of link returning node*
//       p->data() activates the non-const version of data returning Item&
//       p->data() = 42; ... actually changes the data in p's node
//
// ************************************************************************
//
// MEMBER FUNCTIONS for the node<Item> template class:
//   const Item& data() const <----- const version
//   Item& data() <----------------- non-const version
//     Postcondition: Return value is a reference to the data from this node.
//     See the note (above) about the const version and non-const versions.
//
//   const node* link() const <----- const version
//   node* link() <----------------- non-const version
//     See the note (above) about the const version and non-const versions.
//     Postcondition: The return value is the link from this node.
//
//   void set_data(const Item& new_data)
//     Postcondition: The node now contains the specified new data.
//
//   void set_link(node* new_link)
//     Postcondition: The node now contains the specified new link.
//
// ************************************************************************
//
// NON-MEMBER TEMPLATE FUNCTIONS for Linked List Toolkit (Main/Savitch p.324):
//
//  std::size_t list_length(const node<Item>* head_ptr)
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
//  void list_insert(node<Item>* previous_ptr, const Item& entry)
//    Precondition: previous_ptr points to a node in a linked list.
//    Postcondition: A new node containing the given entry has been added
//       after the node that previous_ptr points to.
//
//  node* list_head_remove(node* head_ptr)
//    Precondition: head_ptr is the head pointer of a linked list, with at
//       least one node.
//    Postcondition: The head node has been removed and returned to the heap;
//       returns a pointer to the head of the new, shorter linked list.
//
//  void list_clear(node*& head_ptr)
//    Precondition: head_ptr is the head pointer of a linked list.
//    Postcondition: List pointed to by head_ptr is empty (head_ptr is NULL).
//
//  node* list_copy(node<Item>* source_ptr)
//    Precondition: source_ptr is the head pointer of a linked list or is NULL
//       (to represent an empty linked list).
//    Postcondition: Returns a pointer to the head of a new linked list, an
//       *independent* copy of the original list pointed to by source_ptr.
//    Postcondition: The original list is unchanged, and changes to the new list
//       have no effect on the original list.
//
// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc:
//      - node constructor
//      - list_head_insert
//      - list_insert

#ifndef MAIN_SAVITCH_NODE2_H
#define MAIN_SAVITCH_NODE2_H
#include <cstdlib>    // Provides size_t and NULL

namespace main_savitch_6B
{
template <class Item>
class node
{
 public:
    // TYPEDEF
    typedef Item value_type;

    // CONSTRUCTOR -- note use of keyword "explicit" to prevent the compiler
    //    from automatically using the node constructor to convert an Item
    //    into a node.
    explicit node(const Item& init_data = Item(), node* init_link = NULL) {
        data_field = init_data; link_field = init_link;
    }

    // Member functions to set the data and link fields:
    void set_data(const Item& new_data) { data_field = new_data; }
    void set_link(node* new_link)       { link_field = new_link; }

    // Two slightly different member functions to retrieve the current data:
    const Item& data() const { return data_field; }
    Item& data()             { return data_field; }

    // Two slightly different member functions to retrieve the current link:
    const node* link() const { return link_field; }
    node* link()             { return link_field; }

 private:
    Item data_field;
    node* link_field;
};

// NON-MEMBER TEMPLATE FUNCTIONS to manipulate a linked list
template <class Item>
bool list_empty(const node<Item>* head_ptr);

template <class Item>
std::size_t list_length(const node<Item>* head_ptr);

template <class Item>
node<Item>* list_head_insert(node<Item>* head_ptr,
                             const Item& entry);

template <class Item>
void list_insert(node<Item>* previous_ptr, const Item& entry);

template <class Item>
node<Item>* list_head_remove(node<Item>* head_ptr);

template <class Item>
void list_clear(node<Item>*& head_ptr);  // NOLINT We're allowing this. TW/BW

template <class Item>
node<Item>* list_copy(node<Item>* source_ptr);
}   // end namespace main_savitch_6B

#include "toolkit.template"
#endif

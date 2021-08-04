// FILE: stack.h
// Header file for Lab 7 Part 2
// Modified version of the stack2.h file provided by Main/Savitch, Chap. 8
// Theresa Wilson, 3-11-16; revised 3-13-17
//
// ********** DO NOT CHANGE THIS FILE **********
//
// TEMPLATE CLASS PROVIDED: stack<Item> (a stack of items)
//   The template parameter `Item` is the data type of the items in the
//   stack, also defined as stack<Item>::value_type.  The Item data type
//   may be any of the C++ built-in types (int, char, etc.), or a class
//   with a default constructor, a copy constructor, and an assignment
//   operator.
//
//   The definition stack<Item>::size_type is the data type of
//   any variable that keeps track of how many items are in a stack.
//
// VALUE SEMANTICS for the stack<Item> class:
//   Assignments and the copy constructor may be used with stack<Item>
//   objects.
//
// DYNAMIC MEMORY USAGE by the stack<Item> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   the copy constructor, push, and the assignment operator.

#ifndef MAIN_SAVITCH_STACK2_H
#define MAIN_SAVITCH_STACK2_H

#include <cstdlib>
#include "node2.h"

namespace main_savitch_7B
{
// Declaring stack template class so we can use the class in the
// prototype in non-member functions (==, !=, <<)
template <class Item>
class stack;

// equivalence operator
// Postcondition: Returns true iff stack1 and stack2 contain the same values 
//    in the same order from top to bottom.
//  Example 1. The stacks top<a, b, c> and top<a, b, c> are equivalent
//  Example 2. The stacks top<a, b, c> and top<c, b, a> are not equivalent
template <class Item>
bool operator== (const stack<Item> & stack1, const stack<Item> & stack2);

// inequivalence operator
// Postcondition: Returns true iff stack1 == stack2 is false.
template <class Item>
bool operator!= (const stack<Item> & stack1, const stack<Item> & stack2);

// PROVIDED FUNCTION
// output stream operator
//
// Printed out Stack should have this general format:
//
// Stack of size <num>:
// top_item
//    .
//    .
//    .
// bottom_item
//
template <class Item>
std::ostream& operator<<(std::ostream & out, const stack<Item> & stk);

// Defining the stack template class
template <class Item>
class stack
{
 public:
    // TYPEDEFS
    typedef std::size_t size_type;
    typedef Item value_type;

    // CONSTRUCTOR for the stack<Item> template class:

    // stack
    // Postcondition: The stack has been initialized as an empty stack.
    stack();

    // DESTRUCTOR for the stack<Item> template class:
    ~stack();

    // CONSTANT MEMBER FUNCTIONS for the stack<Item> class:

    // empty
    // Postcondition: Return value is true iff the stack is empty.
    bool empty() const;

    // top
    // Precondition: size() > 0.
    // Postcondition: The return value is (a copy of) the top item of the stack.
    //   The stack is unchanged. This version differs slightly from the 
    //   STL stack, where the top function returns a _reference_ to the item 
    //   on top of the stack.
    // NOTE: throws domain_error exception if stack is empty
    Item top() const;

    // size
    // Postcondition: Return value is the total number of items in the stack.
    size_type size() const;

    // MODIFICATION MEMBER FUNCTIONS for the stack<Item> class:

    // push
    // Postcondition: A new copy of entry has been pushed onto the stack.
    void push(const Item& val);

    // pop
    // Precondition: size() > 0.
    // Postcondition: The top item of the stack has been removed.
    // NOTE: throws domain_error exception if stack is empty
    void pop();

    // reverse
    // Postcondition: The order of the items in the stack has been reversed.
    // Example:  if the stack was top<d, c, b, a>, after the call to
    // reverse() returns, the queue will be top<a, b, c, d>
    void reverse();

    // COPY CONSTRUCTOR
    stack(const stack &source);

    // ASSIGNMENT OPERATOR
    void operator=(const stack &source);

    // FRIEND FUNCTIONS
    // see: web.mst.edu/~nmjxv3/articles/templates.html
    friend bool operator== <Item>(const stack & stack1, const stack & stack2);
    friend bool operator!= <Item>(const stack & stack1, const stack & stack2);
    friend std::ostream& operator<< <Item>(std::ostream & out, 
                                           const stack & stk);

 //private:
    main_savitch_6B::node<Item>* top_ptr;    // Points to top node of stack
};  // end of class
}   // end of namespace main_savitch_7B

#include "stack.template"  // Include the implementation
#endif /* STACK_H_ */

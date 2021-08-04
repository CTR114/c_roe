// FILE: queue.h
// Header file for Lab 7 Part 1
// Modified version of queue.h provided in Main/Savitch Chap. 8
// Barb Wahl and Theresa Wilson, 4-8-17
//
// ********** DO NOT CHANGE THIS FILE **********
//
// CLASS PROVIDED: queue
//
// TYPEDEFS and MEMBER CONSTANTS for the queue class:
//   typedef ____ value_type
//     queue::value_type is the data type of the items in the queue. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with
//     a default constructor, assignment operator, equivalence operator, and a
//     copy constructor.
//
//   typedef ____ size_type
//     queue::size_type is the data type of any variable that keeps track
//     of how many items are in a queue.
//
//   static const size_type CAPACITY = _____
//     queue::CAPACITY is the maximum number of items that a queue can hold.
//
// VALUE SEMANTICS for the queue class:
//   Assignments and the copy constructor may be used with queue objects.

#ifndef MAIN_SAVITCH_QUEUE1_H
#define MAIN_SAVITCH_QUEUE1_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_8B
{
class queue
{
 public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef std::size_t size_type;
    typedef std::string value_type;
    static const size_type CAPACITY = 30;

    // CONSTRUCTOR
    // Postcondition: queue has been initialized as an empty queue
    queue();
    queue(bool instructor);

    // Note: no destructor needed (does not use dynamic memory).

    // CONSTANT MEMBER FUNCTIONS

    // empty()
    // Postcondition: return value is true iff the queue is empty
    bool empty() const;
    bool empty(bool instructor) const;

    // full()
    // Postcondition: return value is true iff the queue is full
    bool full() const;
    bool full(bool instructor) const;

    // front
    // Precondition:  size() > 0
    // Postcondition: return value is a copy of the front item of the queue,
    //    and the queue is unchanged
    // NOTE: throws domain_error exception if queue is empty
    value_type front() const;
    value_type front(bool instructor) const;

    // size()
    // Postcondition: return value is the total number of items in the queue
    size_type size() const;
    size_type size(bool instructor) const;

    // MODIFICATION MEMBER FUNCTIONS

    // pop
    // Precondition:  size() > 0
    // Postcondition: the front item of the queue has been removed
    // NOTE: throws domain_error exception if queue is empty
    void pop();
    void pop(bool instructor);

    // push
    // Precondition:  size() < CAPACITY
    // Postcondition: a new item, `entry`, has been inserted at the rear
    //    of the queue
    // NOTE: throws domain_error exception if queue is full
    void push(const value_type& entry);
    void push(bool instructor, const value_type& entry);

    // reverse
    // Postcondition: the queue's ordering is reversed
    // Example:  if the queue was <a, b, c, d>, after the call to
    // reverse() returns, the queue will be <d, c, b, a>
    void reverse();
    void reverse(bool instructor);

    // FRIENDS
    friend bool operator== (const queue & queue1, const queue & queue2);
    friend bool operator!= (const queue & queue1, const queue & queue2);
    friend std::ostream& operator<<(std::ostream & out, const queue & q);

 //private:
    value_type data[CAPACITY];  // Circular array
    size_type first;            // Index of item at front of the queue
    size_type last;             // Index of item at rear of the queue
    size_type count;            // Total number of items in the queue

    // next_index
    // private helper method for moving a circular array index forward
    // Precondition: 0 <= i < CAPACITY
    // Postcondition: returns (i + 1) mod CAPACITY
    size_type next_index(size_type i) const { return (i + 1) % CAPACITY; }
};  // end of class definition

// NON-MEMBER FUNCTIONALITY -- all three are friends of the queue class

// equivalence operator
// Postcondition: Returns true iff a) queue1 and queue2 are equal in
//    length, and b) queue1 and queue2 have equivalent values and the 
//    same ordering for those values.
//  Example 1. The queues <a, b, c> and <a, b, c> are equivalent
//  Example 2. The queues <a, b, c> and <c, b, a> are not equivalent
bool operator== (const queue & queue1, const queue & queue2);

// inequivalence operator
// Postcondition: Returns true iff queue1 == queue2 is false.
bool operator!= (const queue & queue1, const queue & queue2);

// output stream operator
// Reports the size of the queue and lists the items, in the
//    proper order.
// Resulting output will have this format:
//
// queue of size <num>:
// <item at front of queue>
//    .
//    .
//    .
// <item at back of queue>
std::ostream& operator<<(std::ostream & out, const queue & q);
}  // end namespace main_savitch_8B

#endif

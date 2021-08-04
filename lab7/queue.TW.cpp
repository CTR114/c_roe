// queue.cpp
// Lab 7 Part 1
//
// Name: Theresa Wilson
// Date: 3-13-2017
//
// CLASS IMPLEMENTED: queue (see queue.h for documentation)
//
// INVARIANT for the queue class:
//   1. The number of items in the queue is maintained in the instance
//      variable `count`.
//
//   2. For a non-empty queue, the items are stored in a circular array
//      beginning at data[first] and continuing through data[last].
//      The `data` array's total capacity is CAPACITY (don't use number
//      value!).
//
//   3. TAKE SPECIAL NOTE! For an EMPTY queue, last is any valid index, and
//      first == next_index(last).
//
// INSTANCE VARIABLES:
//      value_type data[CAPACITY];  // Circular array, created in queue.h
//      size_type first;      // Index of item at front of the queue
//      size_type last;       // Index of item at back of the queue
//      size_type count;      // Total number of items in the queue

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>  // provides standard exceptions -- see p.810 of textbook
#include "queue.h"

using namespace std;

namespace main_savitch_8B
{

// CONSTRUCTOR
// Postcondition: queue has been initialized as an empty queue
queue::queue()
{
	count = 0;
	last = 0;
	first = next_index(last);
}

// CONSTANT MEMBER FUNCTIONS

// empty()
// Postcondition: return value is true iff the queue is empty
bool queue::empty() const
{
	return count == 0;
}

// full()
// Postcondition: return value is true iff the queue is full
bool queue::full() const
{
	return count == CAPACITY;
}

// front
// Precondition:  size() > 0
// Postcondition: return value is a copy of the front item of the queue,
//    and the queue is unchanged
// NOTE: throws domain_error exception if queue is empty
queue::value_type queue::front() const
{
	if (empty()) { throw domain_error("Warning: Queue is empty!"); }
	return data[first];
}

// size()
// Postcondition: return value is the total number of items in the queue
queue::size_type queue::size() const
{
	return count;
}

// MODIFICATION MEMBER FUNCTIONS

// pop
// Precondition:  size() > 0
// Postcondition: the front item of the queue has been removed
// NOTE: throws domain_error exception if queue is empty
void queue::pop()
{
	if (empty()) { throw domain_error("Warning: Queue is empty!"); }
	first = next_index(first);
	--count;
}

// push
// Precondition:  size() < CAPACITY
// Postcondition: a new item, `entry`, has been inserted at the rear
//    of the queue
// NOTE: throws domain_error exception if queue is full
void queue::push(const value_type& entry)
{
	if (full()) { throw domain_error("Warning: Queue is full!"); }
	last = next_index(last);
	data[last] = entry;
	++count;
}

// reverse
// Postcondition: the queue's ordering is reversed
// Example:  if the queue was <a, b, c, d>, after the call to
// reverse() returns, the queue will be <d, c, b, a>
void queue::reverse()
{
	// nothing to do if queue has one item or less
	if (size() <= 1)
	{
		return;
	}

	// swap ends, working toward middle
	value_type temp;
	size_t front_index = first;
	size_t back_index = last;
	for(size_t i = 1; i <= size() / 2; i++)
    {
        temp = data[front_index];
        data[front_index] = data[back_index];
        data[back_index] = temp;
        front_index = (front_index + 1) % CAPACITY;
        back_index = (CAPACITY + back_index - 1) % CAPACITY;
    }
}

// equivalence operator
// Postcondition: Returns true iff a) queue1 and queue2 are equal in
//    length, and b) queue1 and queue2 have equivalent values and the same
//    ordering for those values.
//  Example 1. The queues <a, b, c> and <a, b, c> are equivalent
//  Example 2. The queues <a, b, c> and <c, b, a> are not equivalent
bool operator== (const queue & queue1, const queue & queue2)
{
	if (queue1.size() != queue2.size())
	{
		return false;
	}
	else if (queue1.empty())   // both queues are empty
	{
		return true;
	}

	// check to see if both queues have the same values in the same order
	size_t q1_index = queue1.first;
	size_t q2_index = queue2.first;

    for (size_t i = 0; i<queue1.size(); i++)
    {
    	if (queue1.data[q1_index] != queue2.data[q2_index])
    	{
    		return false;
    	}
    	q1_index = queue1.next_index(q1_index);
    	q2_index = queue2.next_index(q2_index);
    }
    return true;
}

// inequivalence operator
// Postcondition: Returns true iff queue1 == queue2 is false.
bool operator!= (const queue & queue1, const queue & queue2)
{
	return !(queue1 == queue2);
}

// PROVIDED FUNCTION: output stream operator
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
ostream& operator<<(ostream & out, const queue & q)
{
    out << "queue of size " << q.size() << ":\n";
    size_t curr_index;
    for (size_t i = 0; i < q.size(); i++)
    {
        curr_index = (q.first + i) % queue::CAPACITY;
        out << q.data[curr_index] << "\n";
    }
    return out;
}
}  // end namespace main_savitch_8B

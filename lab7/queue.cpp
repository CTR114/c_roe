// queue.cpp
// Lab 7 Part 1
//
// <Chris Roe>
// <March 14th 2017>
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
    	first = 0;
    	last = CAPACITY - 1;
    	count = 0;
    }

    // Note: no destructor needed (does not use dynamic memory).

    // CONSTANT MEMBER FUNCTIONS

    // empty()
    // Postcondition: return value is true iff the queue is empty
    bool queue::empty() const
    {
    	if (count == 0)
    	{
    		return true;
    	}
    	return false;
    	

    }

    // full()
    // Postcondition: return value is true iff the queue is full
    bool queue::full() const
    {
    	if (count == CAPACITY)
    	{
    		return true;
    	}
    	return false;

    }

    // front
    // Precondition:  size() > 0
    // Postcondition: return value is a copy of the front item of the queue,
    //    and the queue is unchanged
    // NOTE: throws domain_error exception if queue is empty
    queue::value_type queue::front() const
    {	 	  	 	  	   	    	  	      	 	
    	if (count == 0)
    	{
    		throw domain_error (" The Queue is empty so there is nothing in front ");
    	}
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
    void queue::pop() // first changes
    {
    	if (empty())
    	{
    		throw domain_error("The Queue is full");
    	}
    	data[first] = "";
    	first = next_index(first);
    	count -= 1; 
    }

    // push
    // Precondition:  size() < CAPACITY
    // Postcondition: a new item, `entry`, has been inserted at the rear
    //    of the queue
    // NOTE: throws domain_error exception if queue is full
    void queue::push(const value_type& entry) // last changes
    {	 	  	 	  	   	    	  	      	 	
    	if (full())
    	{
    		throw domain_error("The queue is full can not add anything");
    	}
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
        for (int i = 0; i < count/2; i++)
        {
            value_type temp = this -> data[i];
            this -> data[i] = data[count - 1 - i];
            data[count -1 -i] = this -> data[i];
        }
    	

    }


 // FRIENDS
    bool operator== (const queue & queue1, const queue & queue2)
    {
        if (queue1.size() == queue2.size())
        {
            for ( int i = 0; i< queue1.size(); i++)
            {
                if ( queue1.data[i] != queue2.data[i])
                {	 	  	 	  	   	    	  	      	 	
                    return false;
                }
            }
            return true;
        }
        return false;
    
    }

    bool operator!= (const queue & queue1, const queue & queue2)
    {
        return !(operator==(queue1, queue2)); 
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




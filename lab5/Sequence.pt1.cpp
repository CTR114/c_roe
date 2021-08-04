// Sequence.cpp
// Implementation file for Sequence Class

// Name:Chris Roe
// Date: 2/19/17

// The private instance variables of the Sequence class are:
//    value_type data[CAPACITY] -- an array for storing the items
//    size_type length          -- current number of items
//    size_type current_index   -- index for the current item
//       current_index implements the following idea:  you can have your
//       index finger on a specific item in the sequence.
//
// CAPACITY is given a specific value in the header file at compile time.
//    Do not use that number value in your implementation.  Always refer
//    to the capacity by name (CAPACITY).
//
// CLASS INVARIANT: the current_index will always satisfy one of the
//    following two conditions:
//    1. 0 <= current_index < length.  In this case, there is a current
//       item, data[current_index].  is_item() returns true in this case.
//    2. current_index == length.  In this case, this is NO current item.
//       is_item() returns false in this case.
//

#include <cstdlib>
#include <iostream>
#include "Sequence.h"

using namespace std;

namespace main_savitch_3
{
   /***************************** PART 1 IMPLEMENTATIONS *************************/
   // CONSTRUCTOR
   // Creates an empty sequence.
   Sequence::Sequence( )
   {	 	  	 	  	   	    	  	      	 	
      //   Sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
      data[CAPACITY]=0;
      length=0;
      current_index=0;

   }

   // CONSTANT MEMBER FUNCTIONS
   Sequence::size_type Sequence::size( ) const
   {
      //   size_type size( ) const
//     Postcondition: The return value is the length of the sequence.
      return length;

   }

   bool Sequence::is_item( ) const
   {
      //   bool is_item( ) const
//     Postcondition: A `true` return value indicates that there is a valid
//     "current" item that may be retrieved by activating the `current`
//     member function (see below). A `false` return value indicates that
//     there is no valid current item.
      if (0<=data[current_index]<length)
      {
         return true;
      }
      else if (data[current_index]==length)
      {
         return false;
      }
     
//

   }	 	  	 	  	   	    	  	      	 	

   Sequence::value_type Sequence::current( ) const
   {
      //   value_type current( ) const
//     Precondition: is_item( ) returns true (there is a current item)
//     Postcondition: item returned is the current item in the Sequence
       return data[current_index];
//

   }

   // MODIFICATION MEMBER FUNCTIONS
   void Sequence::start( )
   {
      //   void start( )
//     Postcondition:  the sequence of items is not modified
//     Postcondition:  if the sequence is not empty, the first item in the sequence
//        is the current item
      
      current_index=0;
      

   }

   void Sequence::advance( )
   {
      //   void advance( )
//     Precondition: is_item() returns true (there is a current item)
//     Postcondition:  the sequence of items is not modified
//     Postcondition: if the current item was already the last item in the
//     sequence, then there is no longer a current item; otherwise, the new
//     current item is the item immediately after the original current item
//     Example:  If the sequence is (p, i, g) with current item p, then after
//     the call to advance() the sequence is (p, i, g) with current item i
      current_index=current_index+1;


//

   }	 	  	 	  	   	    	  	      	 	

   void Sequence::append(const Sequence::value_type& entry)
   {
      //   void append(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: The provided value, `entry`, has been placed at the end of the
//     sequence. The newly appended item is now the current item of the sequence.
//     Example:  If the sequence is (p, i, g) with current item i, then after
//     the call to append('s') the sequence is (p, i, g, s) with current item s
//     Example:  If the sequence is (c, a, t) with NO CURRENT ITEM, then after
//     the call to append('!') the sequence is (c, a, t, !) with current item !
      data[length] = entry;
      current_index = length;
      length=length+1;
//

   }

   

   /*********

   /***************************** PART 2 IMPLEMENTATIONS *************************/

   void Sequence::insert(const Sequence::value_type& entry)
   {
      //   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: The provided value, `entry`, has been inserted in the sequence
//     _before_ the current item. If there was no current item, then the new entry
//     has been inserted at the _front_ of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//     Example:  If the sequence is (c, a, t, !) with current item !, then after
//     the call to insert('Z') the sequence is (c, a, t, Z, !) with current item Z
//     Example:  If the sequence is (X, Y) with NO CURRENT ITEM, then after
//     the call to insert('K') the sequence is (K, X, Y) with current item K


   }	 	  	 	  	   	    	  	      	 	

   void Sequence::remove_current( )
   {
      //   void remove_current( )
//     Precondition: is_item returns true (there is a current item)
//     Postcondition: The current item has been removed from the sequence, and the
//     item which was immediately to the right of current (if there was one) is now
//     the new current item.
//     Example:  If the sequence is (K, X, Y) with current item X, then after
//     the call to remove_current() the sequence is (K, Y) with current item Y
//     Example:  If the sequence is (i, n, d, i, a, n, A) with current item A, then after
//     the call to remove_current() the sequence is (i, n, d, i, a, n) with no current item
//

   }

   // OPERATOR OVERLOADS -- most are friends
   bool operator==(const Sequence& seqA, const Sequence& seqB)
   {

   }

   bool operator!=(const Sequence& seqA, const Sequence& seqB)
   {

   }

   Sequence operator+(const Sequence& seqA, const Sequence& seqB)
   {

   }

   void Sequence::operator+=(const Sequence& otherSeq) // member, not friend
   {

   }	 	  	 	  	   	    	  	      	 	

   std::ostream& operator<<(std::ostream& out, const Sequence& seq)
   {

   }

   std::istream& operator>>(std::istream& in, Sequence& seq)
   {

   }

} // end namespace


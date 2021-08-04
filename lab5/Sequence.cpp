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
      data[CAPACITY]=0;
      length=0;
      current_index=0;
   }

   // CONSTANT MEMBER FUNCTIONS
   Sequence::size_type Sequence::size( ) const
   {
      return length;
   }

   bool Sequence::is_item( ) const
   {
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
       return data[current_index];
   }

   // MODIFICATION MEMBER FUNCTIONS
   void Sequence::start( )
   {
      
      current_index=0;
      
   }	 	  	 	  	   	    	  	      	 	

   void Sequence::advance( )
   {
     
      current_index=current_index+1;



   }

   void Sequence::append(const Sequence::value_type& entry)
   {
      
      data[length] = entry;
      current_index = length;
      length=length+1;

   }

   

   /*********

   /***************************** PART 2 IMPLEMENTATIONS *************************/

   void Sequence::insert(const Sequence::value_type& entry)
   {
      length = length+1;
      for (int i = length;i<current_index; i++)
      {
         data[i] = data[i-1];
      }
      data[current_index] = data[current_index + 1];
      data[current_index] = entry;



   }	 	  	 	  	   	    	  	      	 	

   void Sequence::remove_current( )
   {
      for (int i = current_index; i<length; i++)
      {
         data[i] = data[i+1];
      }
      length =length-1;
   }

   // OPERATOR OVERLOADS -- most are friends
   bool operator==(const Sequence& seqA, const Sequence& seqB)
   {
      if (seqA.size()==seqB.size())
      {
         for (int i = 0;i<seqA.size();i++)
         {
            if (seqA.data[i]==seqB.data[i])
            {
               return true;
            }

         }

      }
      return false;




   }

   bool operator!=(const Sequence& seqA, const Sequence& seqB)
   {
      return !(operator==(seqA,seqB));

   }	 	  	 	  	   	    	  	      	 	

   Sequence operator+(const Sequence& seqA, const Sequence& seqB)
   {
      Sequence seq1;
      seq1.length = seqA.size() + seqB.size();
      for ( int i = 0; i<seqA.size();i++)
      {
         seq1.data[i] = seqA.data[i];
      }
      for (int j = seqA.size();j<seq1.length;j++)
      {
         seq1.data[j] = seqB.data[j-seqA.size()];
      }
      seq1.current_index = 0;
      return seq1;

   }

   void Sequence::operator+=(const Sequence& otherSeq) // member, not friend
   {
      int pos;
      pos = this-> current_index;
      for ( int i=0;i<otherSeq.size();i++)
      {
         this-> append(otherSeq.data[i]);
      }
      this->current_index = pos;
      
   }

   std::ostream& operator<<(std::ostream& out, const Sequence& seq)
   {
      if (seq.size()==0)
      {
         out<< "sequence: <empty sequence>";
         
      }	 	  	 	  	   	    	  	      	 	
      else
      { 
         out << "sequence: ";
         for (int i = 0; i < seq.size()-1;i++)
         {
            out<< seq.data[i] << " ";
         }
         out<<seq.data[seq.size()-1];
      }
      return out;
   }
      

   std::istream& operator>>(std::istream& in, Sequence& seq)
   {
      string str;
      getline(in,str,'\n');
      if (seq.length > 0)
      {
         seq.length=0;
         seq.current_index=0;
      }
      if (str[10]== '<')
      {
         return in;
      }
      for (int i=10;i<str.size();i=i+2)
      {
        seq.append(str[i]);
      }
      seq.current_index = 0;
      return in;
   }


} // end namespace

	 	  	 	  	   	    	  	      	 	

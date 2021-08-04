// throttle.cpp (see Main & Savitch, pp. 34-60)
// Author:  Chris Roe
// Date:  1/24/17
//
// Description: Implementation file for the throttle class.

#include "throttle.h"
#include <cassert>


namespace main_savitch_2A
{
   



/*
     *  throttle()
     *  Precondition:  None.
     *  Postcondition: The throttle has one position above the shut_off position,
     *  and it is currently shut off.
     */
    throttle::throttle()
    {
        top_position = 1;
        position = 0;

    }

    /*
     *  throttle(int size)
     *  Precondition: size > 0.
     *  Postcondition: The throttle has size positions above the shut_off position,
     *  and it is currently shut off.
     */
    throttle::throttle(int size)
    {	 	  	 	  	   	    	  	      	 	
        assert(size>0);
        top_position = size;
        position = 0; 

    }

    /*
     *  shut_off()
     *  Precondition: None
     *  Postcondition: The throttle has been turned off.
     */
    void throttle::shut_off() //changes 
    {

        position = 0; 
        /* if position = 0)
        return false;
        else
            return is_on();
        /*if (throttle::is_on()==false)
            return false;
        else: 
            return true; */
    }

    /*
     *  shift(int amount)
     *  Precondition: None
     *  Postcondition: The throttle's position has been moved by amount (but not
     *  below 0 or above the top position).
     */
    void throttle::shift(int amount)
    {
        position += amount;
        if (position<0)
        {	 	  	 	  	   	    	  	      	 	
            position = 0;
        }
        else if (position > top_position)
        {
            position = top_position;
        }

    }

    /*
     *  flow()
     *  Precondition: None
     *  Postcondition: The value returned is the current flow as a
     *  proportion of the maximum flow.
     */
    double throttle::flow() const 
    {
        return position/ double (top_position);
        //return -1; 
    }

    /*
     *  is_on()

     *  Precondition: None
     *  Postcondition: If the throttle's flow is above 0, then
     *  the function returns true; otherwise, it returns false.
     */
    bool throttle::is_on() const 
    {
         if ((flow() > 0))
         //if ((flow() > 0));
         {
            return true;
         } 
         else
         {	 	  	 	  	   	    	  	      	 	
            return false;
         }
         
    }

}

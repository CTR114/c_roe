// File: throttle.cpp
// from from Main & Savitch, pp. 34-60

#include "throttle.h"
#include <cassert>

namespace main_savitch_2A
{

    /*!
     *	@function	throttle constructor with no parameters
     *	@return	throttle with top_position 1 and position 0
     */
    throttle::throttle()
    {
	    top_position = 1;
	    position = 0;
    }

    
    /*!
     *	@function	throttle constructor with 1 parameter
     *	@param	int size - maximum position for throttle
     *	@return	throttle with top_position size and position 0
     */
    throttle::throttle(int size)
    {
        assert(size > 0);
	    top_position = size;
	    position = 0;
    }

    
    /*!
     *	@function	shut_off
     *	@post	throttle position is 0
     */
    void throttle::shut_off() 
    { 
        position = 0; 
    }
    

    /*!
     *	@function	shift
     *	@post	throttle's position has been moved by amount (but not
     *      	below 0 or above the top position)
     */
    void throttle::shift(int amount)
    {
	    position += amount;
    
	    if (position < 0)
		    position = 0;
	    else if (position > top_position)
		    position = top_position;
    }


    /*!
     *	@flow	retrieves the current flow of the throttle
     *	@return	double - current flow as a proportion of the maximum flow
     */
    double throttle::flow() const 
    { 
        return position / double(top_position); 
    }

    /*!
     *	@is_on	checks whether the throttle is on
     *	@return	bool - returns true if the position is 0; otherwise, returns false
     */
    bool throttle::is_on() const 
    { 
        return (position > 0); 
    }

}

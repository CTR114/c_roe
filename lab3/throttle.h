// FILE: throttle.h
// from Main & Savitch, pp. 34-60
//
// ***** DO NOT CHANGE THIS FILE *****
//
// CLASS PROVIDED: throttle
//
// CONSTRUCTORS for the throttle class:
//   throttle()
//      Postcondition: The throttle has one position above the shut_off position,
//      and it is currently shut off.
//
//   throttle(int size)
//      Precondition: size > 0.
//      Postcondition: The throttle has size positions above the shut_off position,
//      and it is currently shut off.
//
// MODIFICATION MEMBER FUNCTIONS for the throttle class:
//   void shut_off()
//      Postcondition: The throttle has been turned off.
//
//   void shift(int amount)
//      Postcondition: The throttle's position has been moved by amount (but not
//      below 0 or above the top position).
//
// CONSTANT MEMBER FUNCTIONS for the throttle class:
//   double flow() const
//      Postcondition: The value returned is the current flow as a
//      proportion of the maximum flow.
//
//   bool is_on() const
//      Postcondition: If the throttle's flow is above 0, then
//      the function returns true; otherwise, it returns false.
//
// VALUE SEMANTICS for the throttle class:
//   Assignments and the copy constructor may be used with throttle objects.
//

#ifndef MAIN_SAVITCH_THROTTLE
#define MAIN_SAVITCH_THROTTLE

namespace main_savitch_2A
{
    class throttle
    {

    public:
	    // CONSTRUCTORS
	    throttle();
	    throttle(int size);

	    // MODIFICATION MEMBER FUNCTIONS
	    void shut_off();
	    void shift(int amount);

	    // CONSTANT MEMBER FUNCTIONS
	    double flow() const;
	    bool is_on() const;

     private:
	    int top_position;	// maximum position of the throttle
	    int position;		// current position of the throttle

     };

}

#endif

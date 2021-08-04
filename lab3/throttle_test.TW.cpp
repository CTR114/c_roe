// File: throttle_test.cpp
// Author:  YOUR_NAME_HERE
// Date:  CURRENT_DATE
//
// Description: Unit testing code for the throttle class.
//

#include "throttle.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace main_savitch_2A;

/* @function	compareDoubles
 * @param		double d1 
 * @param		double d2 
 * @return		returns true if abs(d1-d2) < 0.001; otherwise, returns false
 */
bool compareDoubles(double d1, double d2)
{
    double diff = d1 - d2;
    if (diff < 0)
        diff = -diff;
    return (diff < 0.001);
}

/* @function	Test basic functionality of the throttle class.
 * @desc		Unit testing for both throttle constructors;
 * 				uses the is_on and flow member functions to test 
 *              that the throttles were created correctly.
 */
void test_basic_functionality()
{
    cout << "Testing default constructor . . . " ;
    throttle throt1;
    assert(! throt1.is_on());
    assert(throt1.flow() == 0);
    cout << "PASSED!" << endl;

    cout << "Testing 1-parameter constructor . . . " ;
    throttle throt2(6);
    assert(! throt2.is_on());
    assert(throt2.flow() == 0);
    cout << "PASSED!" << endl;
}

/* @function	Test additional functionality of the throttle class.
 * @desc		Unit testing for shift, flow, and shut_off member functions.
 */
void test_additional_functionality()
{
    // Create two throttle objects
    throttle throt1;
    throttle throt2(6);

	// Test basic shift() functionality
    cout << "Testing shift() to maximum  . . . " ;
    throt1.shift(1);
    assert(throt1.is_on());
    assert(throt1.flow() == 1.0);
    throt2.shift(6);
    assert(throt2.is_on());
    assert(throt2.flow() == 1.0);
    cout << "PASSED!" << endl;

    // Test shut_off() functionality
    cout << "Testing shut_off() when throttle is on . . . " ;
    throt1.shut_off();
    assert(! throt1.is_on());
    assert(throt1.flow() == 0.0);
    throt2.shut_off();
    assert(! throt2.is_on());
    assert(throt2.flow() == 0.0);
    cout << "PASSED!" << endl;

    cout << "Testing shut_off() when throttle is off . . . " ;
    throt1.shut_off();
    assert(! throt1.is_on());
    assert(throt1.flow() == 0.0);
    throt2.shut_off();
    assert(! throt2.is_on());
    assert(throt2.flow() == 0.0);
    cout << "PASSED!" << endl;

    // Additional shift() testing
    cout << "Test shifting up incrementally . . . ";
    throttle throt3(8);
    throt3.shift(1);
    assert(compareDoubles(throt3.flow(),0.125));
    throt3.shift(1);
    assert(compareDoubles(throt3.flow(),0.25));
    throt3.shift(1);
    assert(compareDoubles(throt3.flow(),0.375));
    throt3.shift(1);
    assert(compareDoubles(throt3.flow(),0.5));
    throt3.shift(1);
    assert(compareDoubles(throt3.flow(),0.625));
    throt3.shift(1);
    assert(compareDoubles(throt3.flow(),0.75));
    throt3.shift(1);
    assert(compareDoubles(throt3.flow(),0.875));
    throt3.shift(1);
    assert(throt3.flow() == 1.0);
    cout << "PASSED!" << endl;

    cout << "Test shifting down incrementally . . . ";
    throt3.shift(-1);
    assert(compareDoubles(throt3.flow(),0.875));
    throt3.shift(-1);
    assert(compareDoubles(throt3.flow(),0.75));
    throt3.shift(-1);
    assert(compareDoubles(throt3.flow(),0.625));
    throt3.shift(-1);
    assert(compareDoubles(throt3.flow(),0.5));
    throt3.shift(-1);
    assert(compareDoubles(throt3.flow(),0.375));
    throt3.shift(-1);
    assert(compareDoubles(throt3.flow(),0.25));
    throt3.shift(-1);
    assert(compareDoubles(throt3.flow(),0.125));
    throt3.shift(-1);
    assert(throt3.flow() == 0.0);
    cout << "PASSED!" << endl;

    cout << "Testing large shift values . . . ";
    throttle throt4(8);
    throt4.shift(6);
    assert(compareDoubles(throt4.flow(),0.75));
    throt4.shift(-3);
    assert(compareDoubles(throt4.flow(),0.375));
    throt4.shift(10);
    assert(throt4.flow() == 1.0);
    throt4.shift(-15);
    assert(throt4.flow() == 0.0);
    cout << "PASSED!" << endl;
}

int main()
{
    cout << "TESTING THROTTLE CLASS" << endl;

    // Test Basic Functionality
    test_basic_functionality();

    // Test Additional Functionality
    test_additional_functionality();

    cout << "DONE" << endl;

}



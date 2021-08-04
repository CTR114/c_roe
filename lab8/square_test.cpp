// square_test.cpp -- CS 223, Lab 8, Part 1
// Provided tests written by Barb Wahl, 3-18-17
//
// Name: Chris Roe
// Date: March 21

#include <cassert>
#include "square.h"
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

// CONSTANT TESTING OBJECTS
static const square wall_sqr(square::WALL, 2, 5);
static const square start_sqr(square::START, 2, 5);
static const square exit_sqr(square::EXIT, 2, 5);
static const square unvisited_sqr(square::UNVISITED, 2, 5);

// an array of the first four types of square
static const square square_array[] = {
    wall_sqr,
    start_sqr,
    exit_sqr,
    unvisited_sqr
};

// an array of the status codes
static const int status_array[] = {
    square::WALL,
    square::START,
    square::EXIT,
    square::UNVISITED,
    square::WORK_LIST,
    square::EXPLORED,
    square::SOLUTION_PATH
};

void test_basics1()
{	 	  	 	  	   	    	  	      	 	
    string test = "  basics.test.1: default constructor (wall)";
    cout << test << endl;

    square sq;

    assert(sq.getStatus() == square::WALL);
    assert(sq.getRow() == 0);
    assert(sq.getCol() == 0);
    assert(sq.getPrev() == NULL);
}

void test_basics2()
{
    string test = "  basics.test.2: 3-argument constructor (wall, start, exit, unvisited)";  // NOLINT
    cout << test << endl;

    for (int i = square::WALL; i <= square::UNVISITED; i++)
    {
        assert(square_array[i].getStatus() == status_array[i]);
        assert(square_array[i].getRow() == 2);
        assert(square_array[i].getCol() == 5);
        assert(square_array[i].getPrev() == NULL);
    }
}

void test_basics()
{
    // test for the constructors and getters
    // NOTE: The constructors were used above to create global objects.
    // Use getters to examine the global objects for correctness

    cout << "\nTesting square basics . . ." << endl;

    // Test 1: default constructor (wall)
    test_basics1();

    // Test 2: 3-argument constructor (wall, start, exit, unvisited)
    test_basics2();

    cout << "    . . . square basics OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_setters1()
{
    string test = "  setters.test.1: setStatus on a non-wall square";
    cout << test << endl;

    // square status codes, non-wall
    // square::START,
    // square::EXIT,
    // square::UNVISITED,
    // square::WORK_LIST,
    // square::EXPLORED,
    // square::SOLUTION_PATH

    // setup: sq is a start square
    square sq(square::UNVISITED, 3, 0);
    sq.setStatus(square::START);
    assert(sq.getStatus() == square::START);
    assert(sq.getRow() == 3);
    assert(sq.getCol() == 0);
    assert(sq.getPrev() == NULL);

    // change to EXIT
    sq.setStatus(square::EXIT);
    assert(sq.getStatus() == square::EXIT);
    assert(sq.getRow() == 3);
    assert(sq.getCol() == 0);
    assert(sq.getPrev() == NULL);

    // change to UNVISITED
    sq.setStatus(square::UNVISITED);
    assert(sq.getStatus() == square::UNVISITED);
    assert(sq.getRow() == 3);
    assert(sq.getCol() == 0);
    assert(sq.getPrev() == NULL);

    // change to EXPLORED
    sq.setStatus(square::EXPLORED);
    assert(sq.getStatus() == square::EXPLORED);

    // change to SOLUTION_PATH
    sq.setStatus(square::SOLUTION_PATH);
    assert(sq.getStatus() == square::SOLUTION_PATH);
}	 	  	 	  	   	    	  	      	 	

void test_setters2()
{
    string test = "  setters.test.2: setPrev on an unvisited square";
    cout << test << endl;

    // setup:  sq1 is an unvisited square with null prev pointer
    square sq1(square::UNVISITED, 3, 0);
    assert(sq1.getPrev() == NULL);

    // setup:  sq2 is an unvisited square pointed to by sq2_ptr
    square sq2(square::UNVISITED, 3, 1);
    square * sq2_ptr = &sq2;

    // execute setPrev on sq1 and test
    sq1.setPrev(sq2_ptr);
    assert(sq1.getPrev() == sq2_ptr);

    // check that other attributes are unchanged
    assert(sq1.getStatus() == square::UNVISITED);
    assert(sq1.getRow() == 3);
    assert(sq1.getCol() == 0);
}

void test_setters3()
{
    string test = "  setters.test.3: setPrev on a start square";
    cout << test << endl;

    // setup:  sq1 is a start square with null prev pointer
    square sq1(square::START, 3, 0);
    assert(sq1.getPrev() == NULL);

    // setup:  sq2 is an unvisited square pointed to by sq2_ptr
    square sq2(square::UNVISITED, 3, 1);
    square * sq2_ptr = &sq2;

    // execute setPrev on sq1 and test
    sq1.setPrev(sq2_ptr);
    assert(sq1.getPrev() == sq2_ptr);

    // check that other attributes are unchanged
    assert(sq1.getStatus() == square::START);
    assert(sq1.getRow() == 3);
    assert(sq1.getCol() == 0);
}	 	  	 	  	   	    	  	      	 	

void test_setters4()
{
    string test = "  setters.test.4: setPrev on a solution_path square";
    cout << test << endl;

    // setup:  sq1 is a solution_path square with null prev pointer
    square sq1(square::UNVISITED, 3, 0);
    sq1.setStatus(square::SOLUTION_PATH);
    assert(sq1.getPrev() == NULL);

    // setup:  sq2 is an unvisited square pointed to by sq2_ptr
    square sq2(square::UNVISITED, 3, 1);
    square * sq2_ptr = &sq2;

    // execute setPrev on sq1 and test
    sq1.setPrev(sq2_ptr);
    assert(sq1.getPrev() == sq2_ptr);

    // check that other attributes are unchanged
    assert(sq1.getStatus() == square::SOLUTION_PATH);
    assert(sq1.getRow() == 3);
    assert(sq1.getCol() == 0);
}

void test_setters()
{
    cout << "\nTesting setters . . ." << endl;

    // Test 1: setStatus for all types of non-wall squares
    test_setters1();

    // Test 2: setPrev for unvisited square
    test_setters2();

    // Test 3: setPrev for start square
    test_setters3();

    // Test 4: setPrev for solution_path square
    test_setters4();

    cout << "    . . . setters OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_isPlainSquare1()
{
    string test = "  isPlainSquare.test.1: wall, start, exit (false)";
    cout << test << endl;

    for (int i = square::WALL; i <= square::EXIT; i++)
    {
        assert(!square_array[i].isPlainSquare());
    }
}

void test_isPlainSquare2()
{
    string test = "  isPlainSquare.test.2: unvisited, worklist, explored, solution_path (true)";  // NOLINT
    cout << test << endl;

    square sq(square::UNVISITED, 2, 0);
    assert(sq.isPlainSquare());

    sq.setStatus(square::WORK_LIST);
    assert(sq.isPlainSquare());

    sq.setStatus(square::EXPLORED);
    assert(sq.isPlainSquare());

    sq.setStatus(square::SOLUTION_PATH);
    assert(sq.isPlainSquare());
}

void test_isPlainSquare()
{
    cout << "\nTesting isPlainSquare . . ." << endl;

    // Test 1:  wall, start, exit (returns false)
    test_isPlainSquare1();

    // Test 2:  unvisited, worklist, explored, solution_path (returns true)
    test_isPlainSquare2();

    cout << "    . . . isPlainSquare OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_isStart1()
{
    string test = "  isStart.test.1: all non-start type squares (false)";  // NOLINT
    cout << test << endl;

    for (int i = square::WALL; i <= square::UNVISITED; i++)
    {
        if (status_array[i] != square::START)
        {
            assert(!square_array[i].isStart());
        }
    }
    square sq(square::UNVISITED, 2, 0);
    sq.setStatus(square::WORK_LIST);
    assert(!sq.isStart());

    sq.setStatus(square::EXPLORED);
    assert(!sq.isStart());

    sq.setStatus(square::SOLUTION_PATH);
    assert(!sq.isStart());
}

void test_isStart2()
{
    string test = "  isStart.test.2: start square (true)";  // NOLINT
    cout << test << endl;

    assert(start_sqr.isStart());
}

void test_isStart()
{
    cout << "\nTesting isStart . . ." << endl;

    // Test 1:  all types except start (returns false)
    test_isStart1();

    // Test 2:  start (returns true)
    test_isStart2();

    cout << "    . . . isStart OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_isExit1()
{
    string test = "  isExit.test.1: all non-exit type squares (false)";
    cout << test << endl;

    for (int i = square::WALL; i <= square::UNVISITED; i++)
    {
        if (status_array[i] != square::EXIT)
        {
            assert(!square_array[i].isExit());
        }
    }
    square sq(square::UNVISITED, 2, 0);
    sq.setStatus(square::WORK_LIST);
    assert(!sq.isExit());

    sq.setStatus(square::EXPLORED);
    assert(!sq.isExit());

    sq.setStatus(square::SOLUTION_PATH);
    assert(!sq.isExit());
}

void test_isExit2()
{
    string test = "  isExit.test.2: exit square (true)";
    cout << test << endl;

    assert(exit_sqr.isExit());
}

void test_isExit()
{
    cout << "\nTesting isExit . . ." << endl;

    // Test 1:  all types except exit (returns false)
    test_isExit1();

    // Test 2:  exit (returns true)
    test_isExit2();

    cout << "    . . . isExit OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_toChar1()
{
    string test = "Test_toChar.1: Testing if WALL translates";
    cout << test << endl;
    square sq;
    assert(sq.getStatus() == square::WALL);
    assert(sq.toChar() == '#');
}
void test_toChar2()
{
    string test = "Test_toChar.2: Testing if Start translates";
    cout << test << endl;
    square sq(square::UNVISITED, 2, 0);
    sq.setStatus(square::START);
    assert(sq.getStatus() == square::START);
    assert(sq.toChar() == 'S');

}
void test_toChar3()
{
    string test = "Test_toChar.3: Testing if EXIT translates";
    cout << test << endl;
    square sq(square::UNVISITED, 2, 0);
    sq.setStatus(square:: EXIT);
    assert(sq.getStatus() == square::EXIT);
    assert(sq.toChar() == 'E');

}
void test_toChar4()
{
    string test = "Test_toChar.4: Testing if Univisted translates";
    cout << test << endl;
    square sq(square::UNVISITED, 2, 0);
    assert(sq.getStatus() == square::UNVISITED);
    assert(sq.toChar() == '_');

}	 	  	 	  	   	    	  	      	 	
void test_toChar5()
{
    string test = "Test_toChar.5: Testing if WORK_LIST translates";
    cout << test << endl;
    square sq(square::UNVISITED, 2, 0);
    sq.setStatus(square::WORK_LIST);
    assert(sq.getStatus() == square::WORK_LIST);
    assert(sq.toChar() == '@');

}
void test_toChar6()
{
    string test = "Test_toChar.6: Testing if EXPLORED translates";
    cout << test << endl;
    square sq(square::UNVISITED, 2, 0);
    sq.setStatus(square::EXPLORED);
    assert(sq.getStatus() == square::EXPLORED);
    assert(sq.toChar() == '.');

}
void test_toChar7()
{
    string test = "Test_toChar.7: Testing if SOLUTION_PATH translates";
    cout << test << endl;
    square sq(square::UNVISITED, 2, 0);
    sq.setStatus(square::SOLUTION_PATH);
    assert(sq.getStatus() == square::SOLUTION_PATH);
    assert(sq.toChar() == 'X');

}

void test_toChar()
{
    cout << "\nTesting toChar . . ." << endl;
    test_toChar1();
    test_toChar2();
    test_toChar3();
    test_toChar4();
    test_toChar5();
    test_toChar6();
    test_toChar7();
    cout << "    . . . toChar is OK!" << endl;
}	 	  	 	  	   	    	  	      	 	
void test_toString1()
{
    string test = "Test_tostring.1: Testing if brackets and common are correct";
    cout << test << endl;
    square sq(square::EXPLORED,2,3);
    assert(sq.toString() == "[2,3]");


}


void test_toString()
{
    cout << "\nTesting toString . . ." << endl;
    test_toString1();
    cout << "    . . . toString is OK!" << endl;
}

void test_reset1()
{
    string test = "Test_reset.1: Testing if WORK_LIST reset is correct";
    cout << test << endl;
    square sq(square::WORK_LIST, 2, 0);
    sq.reset();
    assert(sq.getStatus() == square::UNVISITED);
}
void test_reset2()
{
    string test = "Test_reset.2: Testing if EXPLORED resets correctly";
    cout << test << endl;
    square sq(square::EXPLORED, 2, 0);
    sq.reset();
    assert(sq.getStatus() == square::UNVISITED);
}
void test_reset3()
{	 	  	 	  	   	    	  	      	 	
     string test = "Test_reset.3: Testing if SOLUTION_PATH resets correctly";
    cout << test << endl;
    square sq(square::SOLUTION_PATH, 2, 0);
    sq.reset();
    assert(sq.getStatus() == square::UNVISITED);

}
void test_reset4()
{
    string test = "Test_reset.4: Testing if EXIT resets";
    cout << test << endl;
    square sq(square::EXIT, 2, 0);
    sq.reset();
    assert(sq.getStatus() == square::EXIT);

}
void test_reset5()
{
     string test = "Test_toChar.2: Testing if Start resets";
    cout << test << endl;
    square sq(square::START, 2, 0);
    sq.reset();
    assert(sq.getStatus() == square::START);
}
void test_reset6()
{
    string test = "Test_toChar.1: Testing if WALL translates";
    cout << test << endl;
    square sq (square::WALL,2,0);
    sq.reset();
    assert(sq.getStatus() == square::WALL);
}

void test_reset()
{
    cout << "\nTesting reset . . ." << endl;
    
    test_reset1();
    test_reset2();
    test_reset3();
    test_reset4();
    test_reset5();
    test_reset6();
    cout << "    . . . reset is OK!" << endl;
}	 	  	 	  	   	    	  	      	 	
void test_streamOutput1()
{
    string test = "Test_streamOutput.1: Testing if 1 output is correct";
    cout << test << endl;
    stringstream out;
    square sq(square::UNVISITED, 2, 0);
    string correct = "_";
    out << sq;
    string real = out.str();
    assert (real == correct);
}

void test_streamOutput2()
{
    string test = "Test_streamOutput.2: Testing multiple outputs";
    cout << test << endl;
    stringstream out;
    square sq(square::UNVISITED, 2, 0);
    square sq1(square::START, 2, 0);
    string correct = "_S";
    out << sq << sq1;
    string real = out.str();
    assert (real == correct);
}

void test_streamOutput()
{
    cout << "\nTesting stream output . . ." << endl;

    test_streamOutput1();
    test_streamOutput2();

    cout << "    . . . stream output is OK!" << endl;
}
void test_exceptions1()
{	 	  	 	  	   	    	  	      	 	
    string test = "Test_exceptions.1: Testing if constructor above 6 less than 0";
    cout << test << endl;
    try
    {
        square sq(-1,0,0);
    }
    catch (domain_error& e)
    {
        cout << "..ok" << endl;
        return;
    }
    try
    {
        square sq(7,0,0);
    }
    catch (domain_error& e)
    {
        cout << "....ok"<< endl;
        return;
    }

}
void test_exceptions2()
{
    string test = "Test_exceptions.2: Testing if setStatus cant be WALL";
    cout << test << endl;
    try
    {
        square sq(square::WALL,0 , 0);
        sq.setStatus(square::START);
    }
    catch (domain_error& e)
    {
        cout << "...ok"<< endl;
        return;
    }	 	  	 	  	   	    	  	      	 	
}
void test_exceptions3()
{
    string test = "Test_exceptions.3: Testing if setPrev cant be WALL";
    cout << test << endl;
    try
    {
        square *ptr = NULL;
        square sq(square::WALL, 0 , 0);
        sq.setPrev(ptr);
    }
    catch (domain_error& e)
    {
        cout << "... ok" << endl;
        return;
    }
}


void test_exceptions()
{
    cout << "\nTesting that exceptions are thrown when necessary . . ."
    << endl;

    test_exceptions1();
    test_exceptions2();
    test_exceptions2();

    // cout << "    . . . exception throwing is OK!" << endl;
}

int main()
{
    // complete tests provided
    test_basics();  // constructors, getters
    test_setters();
    test_isPlainSquare();
    test_isStart();
    test_isExit();

    // tests not provided -- students need to implement
    test_toChar();
    test_toString();
    test_reset();
    test_streamOutput();
    test_exceptions();

    cout << "\nAll current tests are passing!  Need to add more??" << endl;
}	 	  	 	  	   	    	  	      	 	

// square_test.cpp -- CS 223, Lab 8, Part 1
// Provided tests written by Barb Wahl, 3-18-17
//
// Name:  Barb Wahl
// Date:  4-2-2017

#include <cassert>
#include <sstream>
#include <stdexcept>
#include "square.h"

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
    string test = "  test.basics.1: default constructor (wall)";
    cout << test << endl;

    square sq;

    assert(sq.getStatus() == square::WALL);
    assert(sq.getRow() == 0);
    assert(sq.getCol() == 0);
    assert(sq.getPrev() == NULL);
}

void test_basics2()
{
    string test = "  test.basics.2: 3-argument constructor (wall, start, exit, unvisited)";  // NOLINT
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
    string test = "  test.setters.1: setStatus on a non-wall square";
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
    string test = "  test.setters.2: setPrev on an unvisited square";
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
    string test = "  test.setters.3: setPrev on a start square";
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
    string test = "  test.setters.4: setPrev on a solution_path square";
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

    // Test 1: setStatus for all types of non-wall square
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
    string test = "  test.isplainsquare.1: wall, start, exit (false)";
    cout << test << endl;

    for (int i = square::WALL; i <= square::EXIT; i++)
    {
        assert(!square_array[i].isPlainSquare());
    }
}

void test_isPlainSquare2()
{
    string test = "  test.isplainsquare.2: unvisited, worklist, explored, solution_path (true)";  // NOLINT
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
    string test = "  test.isStart.1: all non-start type squares (false)";  // NOLINT
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
    string test = "  test.isStart.2: start square (true)";  // NOLINT
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
    string test = "  test.isExit.1: all non-exit type squares (false)";
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
    string test = "  test.isExit.2: exit square (true)";
    cout << test << endl;

    assert(exit_sqr.isExit());
}

void test_IsExit()
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
    string test = "  toChar.test.1: wall prints as #";
    cout << test << endl;

    assert(wall_sqr.toChar() == '#');
}

void test_toChar2()
{
    string test = "  toChar.test.2: start prints as S";
    cout << test << endl;

    assert(start_sqr.toChar() == 'S');
}

void test_toChar3()
{
    string test = "  toChar.test.3: exit prints as E";
    cout << test << endl;

    assert(exit_sqr.toChar() == 'E');
}

void test_toChar4()
{
    string test = "  toChar.test.4: unvisited prints as _";
    cout << test << endl;

    assert(unvisited_sqr.toChar() == '_');
}

void test_toChar5()
{
    string test = "  toChar.test.5: work_list prints as @";
    cout << test << endl;

    square sqr(3, 0 , 0);   // unvisited
    sqr.setStatus(4);   // work_list

    assert(sqr.toChar() == '@');
}

void test_toChar6()
{
    string test = "  toChar.test.6: explored prints as .";
    cout << test << endl;

    square sqr(3, 0 , 0);   // unvisited
    sqr.setStatus(5);   // explored

    assert(sqr.toChar() == '.');
}

void test_toChar7()
{
    string test = "  toChar.test.7: solution_path prints as X";
    cout << test << endl;

    square sqr(3, 0 , 0);   // unvisited
    sqr.setStatus(6);   // solution_path

    assert(sqr.toChar() == 'X');
}

void test_toChar()
{
    /*
    *  toChar
    *  Helper method for printing the maze.
    *  Postcondition: Return value is a char representation of the status:
    *
    *        WALL -> '#'
    *        START  -> 'S'
    *        EXIT -> 'E'
    *        UNVISITED -> '_'
    *        WORK_LIST -> '@'
    *        EXPLORED -> '.'
    *        SOLUTION_PATH -> 'X'
    *        any other value -> '?'
    */
    cout << "\nTesting toChar . . ." << endl;

    // test 1 wall
    test_toChar1();

    // test 2 start
    test_toChar2();

    // test 3 exit
    test_toChar3();

    // test 4 unvisited
    test_toChar4();

    // test 5 work_list
    test_toChar5();

    // test 6 explored
    test_toChar6();

    // test 7 solution_path
    test_toChar7();

    // cout << "    . . . toChar is OK!" << endl;
}

void test_toString1()
{
    string test = "  toString.test.1: a typical square at [4, 7]";
    cout << test << endl;

    square sqr(3, 4 , 7);   // unvisited

    assert(sqr.toString() == "[4,7]");
}

void test_toString()
{
    cout << "\nTesting toString . . ." << endl;

    // Test 1, typical case
    test_toString1();

    // cout << "    . . . toString is OK!" << endl;
}

void test_reset1()
{
    string test = "  reset.test.1: wall unchanged";
    cout << test << endl;

    square sqr(0, 5, 7);

    sqr.reset();
    assert(sqr.getStatus() == 0);
}

void test_reset2()
{
    string test = "  reset.test.2: start unchanged";
    cout << test << endl;

    square sqr(1, 5, 7);

    sqr.reset();
    assert(sqr.getStatus() == 1);
}

void test_reset3()
{
    string test = "  reset.test.3: exit unchanged";
    cout << test << endl;

    square sqr(2, 5, 7);

    sqr.reset();
    assert(sqr.getStatus() == 2);
}

void test_reset4()
{
    string test = "  reset.test.4: unvisited unchanged";
    cout << test << endl;

    square sqr(3, 5, 7);

    sqr.reset();
    assert(sqr.getStatus() == 3);
}

void test_reset5()
{
    string test = "  reset.test.5: worklist -> unvisited";
    cout << test << endl;

    square sqr(3, 5, 7);
    sqr.setStatus(4);

    sqr.reset();
    assert(sqr.getStatus() == 3);
}

void test_reset6()
{
    string test = "  reset.test.6: explored -> unvisited";
    cout << test << endl;

    square sqr(3, 5, 7);
    sqr.setStatus(5);

    sqr.reset();
    assert(sqr.getStatus() == 3);
}

void test_reset7()
{
    string test = "  reset.test.7: solution_path -> unvisited";
    cout << test << endl;

    square sqr(3, 5, 7);
    sqr.setStatus(6);

    sqr.reset();
    assert(sqr.getStatus() == 3);
}


void test_reset()
{
    /*
    *  reset
    *  Postcondition:  If this is a plain square, `status` is set to UNVISITED.
    *     Otherwise, its status is unchanged.
    *  Note:  Does NOT throw an exception for non-plain square.
    */
    cout << "\nTesting reset . . ." << endl;


    // Test 1: wall is still a wall
    test_reset1();

    // Test 2: start is still start
    test_reset2();

    // Test 3: exit is still exit
    test_reset3();

    // Test 4: unvisited -> unvisited
    test_reset4();

    // Test 5: work_list -> unvisited
    test_reset5();

    // Test 6: explored -> unvisited
    test_reset6();

    // Test 7: solution_path -> unvisited
    test_reset7();

    // cout << "    . . . reset is OK!" << endl;
}

void test_streamOutput1()
{
    // STREAM OUTPUT
    /*
    *  Postcondition:  Puts a single char, representing the square status, into
    *     the output stream `out`, and returns `out` to allow for chaining.
    *  Example: If sq.status is WALL, the character `#` is put into the output
    *     stream.
    *  NOTE:  Do not put any whitespace into `out` -- just put a single char
    *     for the status of `sq`.
    */
    string test = "  streamOutput.test.1: wall square";
    cout << test << endl;

    // 1. Create local variables:
    //  - a stringstream for output, called out
    //  - a string for storing the expected message, called correct
    //  - a square sqr
    stringstream out;
    string correct;
    square sqr(0, 5, 7);

    // 2. Store the expected message in the string variable "correct"
    // Get it exactly right!
    correct = "#";

    // 3. Use the output stream variable "out" and the operator "<<" to
    // (hopefully) put the expected message for seq into the stream
    out << sqr;

    // 4. Inside an assert, test whether the "out.str()" result
    // (.str() converts stream to string) equals the expected message string
    string actual = out.str();
    assert(actual == correct);
}

void test_streamOutput2()
{
    // STREAM OUTPUT
    /*
    *  Postcondition:  Puts a single char, representing the square status, into
    *     the output stream `out`, and returns `out` to allow for chaining.
    *  Example: If sq.status is WALL, the character `#` is put into the output
    *     stream.
    *  NOTE:  Do not put any whitespace into `out` -- just put a single char
    *     for the status of `sq`.
    */
    string test = "  streamOutput.test.2: chaining (wall, space, start)";
    cout << test << endl;

    // 1. Create local variables:
    //  - a stringstream for output, called out
    //  - a string for storing the expected message, called correct
    //  - a square sqr
    stringstream out;
    string correct;
    square wall_sqr(0, 5, 7);
    square start_sqr(1, 5, 8);

    // 2. Store the expected message in the string variable "correct"
    // Get it exactly right!
    correct = "# S";

    // 3. Use the output stream variable "out" and the operator "<<" to
    // (hopefully) put the expected message for seq into the stream
    out << wall_sqr << " " << start_sqr;

    // 4. Inside an assert, test whether the "out.str()" result
    // (.str() converts stream to string) equals the expected message string
    string actual = out.str();
    assert(actual == correct);
}

void test_streamOutput()
{
    cout << "\nTesting stream output . . ." << endl;

    // Test 1: typical square (wall)
    test_streamOutput1();

    // Test 2: chaining
    test_streamOutput2();

    cout << "    . . . stream output is OK!" << endl;
}

void test_exceptions1()
{
    string test = "  exceptions.test.1: constructor throws error for invalid starting status"; // NOLINT
    cout << test;

    try {
        square sqr(square::EXPLORED, 2, 5);  // should throw domain_error
    } catch (domain_error&  e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_exceptions2()
{
    string test = "  exceptions.test.2: setStatus throws error if it's a wall square"; // NOLINT
    cout << test;

    square sqr = wall_sqr;

    try {
        sqr.setStatus(square::EXPLORED);  // should throw domain_error
    } catch (domain_error&  e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_exceptions3()
{
    string test = "  exceptions.test.3: setPrev throws error if it's a wall square"; // NOLINT
    cout << test;

    square sqr;

    try {
        sqr.setPrev(&sqr);  // should throw domain_error
    } catch (domain_error&  e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_exceptions()
{
    cout << "\nTesting that exceptions are thrown when necessary . . ."
         << endl;

    // Test 1: 3-argument constructor, throws error for invalid starting status"; // NOLINT
    test_exceptions1();

    // Test 2: setStatus, throws exception if not a plain square"; // NOLINT
    test_exceptions2();

    // Test 3: setPrev, throws exception if it's a wall square"; // NOLINT
    test_exceptions3();

    cout << "    . . . exception throwing is OK!" << endl;
}

int main()
{
    // complete tests provided
    test_basics();  // constructors, getters
    test_setters();
    test_isPlainSquare();
    test_isStart();
    test_IsExit();

    // tests not provided -- students need to implement
    test_toChar();
    test_toString();
    test_reset();
    test_streamOutput();
    test_exceptions();

    cout << "\nAll current tests are passing!  Need to add more??" << endl;
}

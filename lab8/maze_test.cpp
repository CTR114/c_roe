// maze_cpp -- CS 223, Lab 8, Part 2
// Provided tests by T. Wilson and B. Wahl, updated 3-19-17
//
// Name: Chris Roe
// Date: March 25th

#include <cassert>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "maze.h"

using namespace std;

//  The basic maze class functionality (constructor, destructor,
//  getStart, getExit, getNumRows, getNumCols, get), is tested in
//  the test_basics_maze_xx functions, using three of the provided
//  maze text files.
void test_basics_maze_b1()
{
    string test = "  basics.maze.test.1: maze_b1.txt";
    cout << test << endl;

    // contents of maze_b1.txt:
    //    3 4
    //    3 3 3 3
    //    1 0 0 3
    //    2 2 3 3
    //    0 3

    // need to have maze_b1.txt in same directory
    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square* start_ptr = NULL;
    square* exit_ptr = NULL;

    // execute/test
    assert(m1.getNumRows() == 3);
    assert(m1.getNumCols() == 4);

    start_ptr = m1.getStart();
    assert(start_ptr != NULL);
    assert(start_ptr -> isStart());
    assert(start_ptr -> toString() == "[1,0]");

    exit_ptr = m1.getExit();
    assert(exit_ptr != NULL);
    assert(exit_ptr -> isExit());
    assert(exit_ptr -> toString() == "[2,1]");

    // get pointer to [2,1], the EXIT square
    square* sq_ptr = m1.get(2, 1);
    assert(sq_ptr -> isExit());
    assert(sq_ptr -> toString() == "[2,1]");

    // get pointer to [1,0], the START square
    sq_ptr = m1.get(1, 0);
    assert(sq_ptr -> isStart());
    assert(sq_ptr -> toString() == "[1,0]");

    // check [0,0] and [2,3] are unvisited
    sq_ptr = m1.get(0, 0);
    assert(sq_ptr -> getStatus() == square::UNVISITED);
    assert(sq_ptr -> toString() == "[0,0]");
    sq_ptr = m1.get(2, 3);
    assert(sq_ptr -> getStatus() == square::UNVISITED);
    assert(sq_ptr -> toString() == "[2,3]");
}	 	  	 	  	   	    	  	      	 	

void test_basics_maze_t1()
{
    string test = "  basics.maze.test.2: maze_t1.txt";
    cout << test << endl;

    // contents of maze_t1.txt:
    // 3 2
    // 0 1 3 3 2 0

    ifstream mazefile("maze_t1.txt");
    maze m1(mazefile);

    square* start_ptr = NULL;
    square* exit_ptr = NULL;

    // execute/test
    assert(m1.getNumRows() == 3);
    assert(m1.getNumCols() == 2);

    start_ptr = m1.getStart();
    assert(start_ptr != NULL);
    assert(start_ptr -> isStart());
    assert(start_ptr -> toString() == "[0,1]");

    exit_ptr = m1.getExit();
    assert(exit_ptr != NULL);
    assert(exit_ptr -> isExit());
    assert(exit_ptr -> toString() == "[2,0]");

    // get pointer to [2,0], the EXIT square
    square* sq_ptr = m1.get(2, 0);
    assert(sq_ptr -> isExit());
    assert(sq_ptr -> toString() == "[2,0]");

    // get pointer to [0,1], the START square
    sq_ptr = m1.get(0, 1);
    assert(sq_ptr -> isStart());
    assert(sq_ptr -> toString() == "[0,1]");

    // check [0,0] and [2,1] are walls
    sq_ptr = m1.get(0, 0);
    assert(sq_ptr -> getStatus() == square::WALL);
    assert(sq_ptr -> toString() == "[0,0]");
    sq_ptr = m1.get(2, 1);
    assert(sq_ptr -> getStatus() == square::WALL);
    assert(sq_ptr -> toString() == "[2,1]");
}	 	  	 	  	   	    	  	      	 	

void test_basics_maze_b3()
{
    string test = "  basics.maze.test.3: maze_b3.txt";
    cout << test << endl;

    // contents of maze_t2.txt:
    // 2 2
    // 3
    // 1
    // 3
    // 2

    ifstream mazefile("maze_b3.txt");
    maze m1(mazefile);
    square* start_ptr = NULL;
    square* exit_ptr = NULL;

    // execute/test
    assert(m1.getNumRows() == 2);
    assert(m1.getNumCols() == 1);

    start_ptr = m1.getStart();
    assert(start_ptr != NULL);
    assert(start_ptr -> isStart());
    assert(start_ptr -> toString() == "[0,0]");

    exit_ptr = m1.getExit();
    assert(exit_ptr != NULL);
    assert(exit_ptr -> isExit());
    assert(exit_ptr -> toString() == "[1,0]");

    // get pointer to [1,0], the EXIT square
    square* sq_ptr = m1.get(1, 0);
    assert(sq_ptr -> isExit());
    assert(sq_ptr -> toString() == "[1,0]");

    // get pointer to [0,0], the START square
    sq_ptr = m1.get(0, 0);
    assert(sq_ptr -> isStart());
    assert(sq_ptr -> toString() == "[0,0]");
}	 	  	 	  	   	    	  	      	 	

void test_basics_maze()
{
    cout << "\nTesting maze constructor and basic functions . . ." << endl;
    // Test 1: read maze_b1.txt
    test_basics_maze_b1();

    // Test 2: read maze_t1.txt
    test_basics_maze_t1();

    // Test 3: read maze_b3.txt
    test_basics_maze_b3();

    cout << "    . . . basic maze functionality OK!" << endl;
}

void test_toString1()
{
    string test = "  toString.test.1: maze_b1.txt, 3 x 4";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    string str = m1.toString();
    string correct = "\n_ _ _ _ \nS # # _ \n# E _ _ \n";
    // cout << str << correct;
    assert(str == correct);
}

void test_toString2()
{
    string test = "  toString.test.2: maze_b3.txt, 2 x 1";
    cout << test << endl;

    ifstream mazefile("maze_b3.txt");
    maze m1(mazefile);
    string str = m1.toString();
    string correct = "\nS \nE \n";
    // cout << str << correct;
    assert(str == correct);
}	 	  	 	  	   	    	  	      	 	

void test_toString()
{
    cout << "\nTesting toString . . ." << endl;

    // Test 1:  maze_b1.txt, 3 x 4
    test_toString1();

    // Test 2:  maze_b3.txt, 2 x 1
    test_toString2();

    cout << "    . . . toString OK!" << endl;
}
void test_getSquare1()
{
    string test = "test_getSquare1: maze_b1.text, get square (0,0)";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square *test_ptr = m1.get(0,0);
    assert(test_ptr -> toString() == "[0,0]");

}
void test_getSquare2()
{
    string test = "test_getSquare2: maze_b2.text, get square (4,2) in the middle";
    cout << test << endl;

    ifstream mazefile("maze_b2.txt");
    maze m1(mazefile);
    square *test_ptr = m1.get(4,2);
    assert(test_ptr -> toString() == "[4,2]");
}
void test_getSquare3()
{	 	  	 	  	   	    	  	      	 	
    string test = "test_getSquare2: maze_b2.text, get square (7,7) at end";
    cout << test << endl;

    ifstream mazefile("maze_b2.txt");
    maze m1(mazefile);
    square *test_ptr = m1.get(7,7);
    assert(test_ptr -> toString() == "[7,7]");
}
void test_getSquare()
{
    cout << "\nTesting getSquare . . ." << endl;

    test_getSquare1();
    test_getSquare2();
    test_getSquare3();

    // cout << "    . . . getSquare OK!" << endl;
}
void test_neighbors_of_square1()
{
    string test = "test_neighbors_of_square1: neighbors of square 0,0,vector length 2";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square& sq1 = m1.getSquare(m1.getNumRows()-1, m1.getNumCols()-1);
    vector<square *> v1 = m1.neighbors_of_square(sq1);
    assert(v1.size() == 2);
    assert(v1.front() -> getStatus() == square::UNVISITED);
}

void test_neighbors_of_square2()
{
    string test = "test_neighbors_of_square2: neighbors of square 0, col,vector length 3";
    cout << test << endl;

    ifstream mazefile("maze_t3.txt");
    maze m1(mazefile);
    square& sq1 = m1.getSquare(1, m1.getNumCols()-1);
    vector<square *> v1 = m1.neighbors_of_square(sq1);
    assert(v1.size() == 3);
    assert(v1.front() -> getStatus() == square::UNVISITED);
}	 	  	 	  	   	    	  	      	 	
void test_neighbors_of_square3()
{
    string test = "test_neighbors_of_square2: neighbors of square numRows-1, numCols-1,vector length 2";
    cout << test << endl;

    ifstream mazefile("maze_b2.txt");
    maze m1(mazefile);
    square& sq1 = m1.getSquare(m1.getNumRows()-1, m1.getNumCols()-1);
    vector<square *> v1 = m1.neighbors_of_square(sq1);
    assert(v1.size() == 2);
    assert(v1.front() -> getStatus() == square::WALL);
}
void test_neighbors_of_square4()
{
    string test = "test_neighbors_of_square4: neighbors of square row, col,vector length 4";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square& sq1 = m1.getSquare(1, 2);
    vector<square *> v1 = m1.neighbors_of_square(sq1);
    assert(v1.size() == 4);
    assert(v1.front() -> getStatus() == square::UNVISITED);
}
void test_neighbors_of_square5()
{
    string test = "test_neighbors_of_square5: neighbors of square row, numCols-1,vector length 3";
    cout << test << endl;

    ifstream mazefile("maze_t1.txt");
    maze m1(mazefile);
    square& sq1 = m1.getSquare(1, m1.getNumCols()-1);
    vector<square *> v1 = m1.neighbors_of_square(sq1);
    assert(v1.size() == 3);
    assert(v1.front() -> getStatus() == square::START);
}	 	  	 	  	   	    	  	      	 	
void test_neighbors_of_square()
{
    cout << "\nTesting neighbors_of_square . . ." << endl;
    test_neighbors_of_square1();
    test_neighbors_of_square4();
    test_neighbors_of_square5();
    test_neighbors_of_square3();
    test_neighbors_of_square2();


    cout << "    . . . neighbors_of_square OK!" << endl;
}

void test_reset1()
{
    string test = "test_reset: maze_b2.text, square reset to WALL";
    cout << test << endl;

    ifstream mazefile("maze_b2.txt");
    maze m1(mazefile);
    square *test_ptr = m1.get(4,3);
    m1.reset();
    assert(test_ptr -> square::getStatus() == square::WALL );

}
void test_reset2()
{
    string test = "test_reset: maze_b2.text, square reset to UNVISITED";
    cout << test << endl;

    ifstream mazefile("maze_b2.txt");
    maze m1(mazefile);
    square *test_ptr = m1.get(1,0);
    m1.reset();
    assert(test_ptr -> square::getStatus() == square:: UNVISITED);
}	 	  	 	  	   	    	  	      	 	

void test_reset3()
{
    string test = "test_reset: maze_b2.text, square reset to START";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square *test_ptr = m1.get(1,0);
    m1.reset();
    assert(test_ptr -> square::getStatus() == square::START);
}
void test_reset4()
{
    string test = "test_reset: maze_b2.text, square reset to START";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square *test_ptr = m1.get(2,1);
    m1.reset();
    assert(test_ptr -> square::getStatus() == square::EXIT);
}

void test_reset()
{
    cout << "\nTesting reset . . ." << endl;

    test_reset1();
    test_reset2();
    test_reset3();
    test_reset4();

    cout << "    . . . reset OK!" << endl;
}

void test_streamOutput1()
{	 	  	 	  	   	    	  	      	 	
    string test = "  stream.output.test.1: maze_b1";
    cout << test << endl;

    // 1. Create local variables:
    //  - a stringstream for input, called in
    //  - a stringstream for output, called out
    //  - a string for storing the expected message, called correct
    //  - a maze m1 (from maze_b1.txt)
    stringstream in, out;
    string correct;
    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);

    // 2. Store the expected message in the string variable "correct"
    // Get it exactly right!
    correct = "\n_ _ _ _ \nS # # _ \n# E _ _ \n";

    // 3. Use the output stream variable "out" and the operator "<<" to
    // (hopefully) put the expected message for seq into the stream
    out << m1;

    // 4. Inside an assert, test whether the "out.str()" result
    // (.str() converts stream to string) equals the expected message string
    string actual = out.str();
    assert(actual == correct);
}

void test_streamOutput2()
{
    string test = "  stream.output.test.2: maze_b3";
    cout << test << endl;

    // 1. Create local variables:
    //  - a stringstream for input, called in
    //  - a stringstream for output, called out
    //  - a string for storing the expected message, called correct
    //  - a maze m1 (from maze_b3.txt)
    stringstream in, out;
    string correct;
    ifstream mazefile("maze_b3.txt");
    maze m1(mazefile);

    // 2. Store the expected message in the string variable "correct"
    // Get it exactly right!
    correct = "\nS \nE \n";

    // 3. Use the output stream variable "out" and the operator "<<" to
    // (hopefully) put the expected message for seq into the stream
    out << m1;

    // 4. Inside an assert, test whether the "out.str()" result
    // (.str() converts stream to string) equals the expected message string
    string actual = out.str();
    assert(actual == correct);
}	 	  	 	  	   	    	  	      	 	

void test_streamOutput3()
{
    string test = "  stream.output.test.3: chaining the output operator";
    cout << test << endl;

    // 1. Create local variables:
    //  - a stringstream for input, called in
    //  - a stringstream for output, called out
    //  - a string for storing the expected message, called correct
    //  - a maze m1 (from maze_b3.txt)
    stringstream in, out;
    string correct1, correct2, correct;
    ifstream mazefile1("maze_b3.txt");
    maze m1(mazefile1);
    ifstream mazefile2("maze_b1.txt");
    maze m2(mazefile2);

    // 2. Store the expected message in the string variable "correct"
    // Get it exactly right!
    correct1 = "\nS \nE \n";
    correct2 = "\n_ _ _ _ \nS # # _ \n# E _ _ \n";
    correct = correct1 + correct2;

    // 3. Use the output stream variable "out" and the operator "<<" to
    // (hopefully) put the expected message for seq into the stream
    out << m1 << m2;

    // 4. Inside an assert, test whether the "out.str()" result
    // (.str() converts stream to string) equals the expected message string
    string actual = out.str();
    assert(actual == correct);
}

void test_streamOutput()
{	 	  	 	  	   	    	  	      	 	
    cout << "\nTesting stream output . . ." << endl;

    // Test 1:  maze_b1
    test_streamOutput1();

    // Test 2:  maze_b3
    test_streamOutput2();

    // Test 3:  chaining the output operator
    test_streamOutput3();

    cout << "    . . . stream output OK!" << endl;
}

// BAD mazes
void test_mazeWithNoStart()
{
    string test = "  exceptions.test.1: maze without start";
    cout << test;

    ifstream mazefile("maze_with_no_start.txt");
    try {
        maze m1(mazefile);
    } catch (invalid_argument& e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_mazeWithNoExit()
{
    string test = "  exceptions.test.2: maze without exit";
    cout << test;

    ifstream mazefile("maze_with_no_exit.txt");
    try {	 	  	 	  	   	    	  	      	 	
        maze m1(mazefile);
    } catch (invalid_argument& e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_mazeWithTwoStarts()
{
    string test = "  exceptions.test.3: maze with two starts";
    cout << test;

    ifstream mazefile("maze_with_two_starts.txt");
    try {
        maze m1(mazefile);
    } catch (invalid_argument& e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_mazeWithTwoExits()
{
    string test = "  exceptions.test.4: maze with two exits";
    cout << test;

    ifstream mazefile("maze_with_two_exits.txt");
    try {
        maze m1(mazefile);
    } catch (invalid_argument& e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}	 	  	 	  	   	    	  	      	 	

void test_badMazeFiles()
{
    cout << "\nTesting the constructor with bad mazes . . ." << endl;

    // Test 1:  maze with no start
    test_mazeWithNoStart();

    // Test 2:  maze with no exit
    test_mazeWithNoExit();

    // Test 3:  maze with two starts
    test_mazeWithTwoStarts();

    // Test 4:  maze with two exits
    test_mazeWithTwoExits();

    cout << "    . . . exceptions correctly thrown!" << endl;
}

int main()
{
    // PROVIDED
    test_basics_maze();
    test_toString();

    // NOT PROVIDED
    test_getSquare();
    test_neighbors_of_square();
    test_reset();

    // PROVIDED
    test_streamOutput();
    test_badMazeFiles();

    cout << "\nAll current tests passing for maze!" << endl;
}	 	  	 	  	   	    	  	      	 	


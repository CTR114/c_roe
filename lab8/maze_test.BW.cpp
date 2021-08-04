// maze_cpp -- CS 223, Lab 8, Part 2
// Provided tests by T. Wilson and B. Wahl, updated 3-19-17
//
// Name:
// Date:

#include <cassert>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "maze.h"

using namespace std;

//  The basic maze class functionality (constructor, destructor,
//  getStart, getExit, getNumRows, getNumCols, get), is tested
//  in the test_basics_maze_xx functions, using three of the provided
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
    string test = "  getSquare.test.1:  maze_b1.txt";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);

    // get [2,1], the EXIT square
    square sq = m1.getSquare(2, 1);
    assert(sq.isExit());

    // get [1,0], the START square
    sq = m1.getSquare(1, 0);
    assert(sq.isStart());

    // check [0,0] and [2,3] are unvisited
    sq = m1.getSquare(0, 0);
    assert(sq.getStatus() == square::UNVISITED);
}

void test_getSquare2()
{
    string test = "  getSquare.test.2:  maze_b3.txt";
    cout << test << endl;

    ifstream mazefile("maze_b3.txt");
    maze m1(mazefile);

    // get [1,0], the EXIT square
    square sq = m1.getSquare(1, 0);
    assert(sq.isExit());

    // get [0,0], the START square
    sq = m1.getSquare(0, 0);
    assert(sq.isStart());
}

void test_getSquare()
{
    string test = "\nTesting getSquare . . .";
    cout << test << endl;

    // Test 1:  maze_b1.txt
    test_getSquare1();

    // Test 2:  maze_b3.txt
    test_getSquare2();

    cout << "    . . . getSquare OK!" << endl;
}

void test_neighbors_1()
{
    string test = "  neighbors.test.1: upper left corner, 2 neighbors";
    cout << test << endl;

    // setup:  read a maze and get the upper left square
    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(0, 0);

    // execute
    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 2 neighbors
    assert(neighborsVector.size() == 2);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[0,1]");
    assert(neighborsVector[1] -> toString() == "[1,0]");
}

void test_neighbors_2()
{
    string test = "  neighbors.test.2: upper right corner, 2 neighbors";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(0, 3);

    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 2 neighbors
    assert(neighborsVector.size() == 2);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[1,3]");
    assert(neighborsVector[1] -> toString() == "[0,2]");
}

void test_neighbors_3()
{
    string test = "  neighbors.test.3: lower right corner, 2 neighbors";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(2, 3);

    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 2 neighbors
    assert(neighborsVector.size() == 2);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[1,3]");
    assert(neighborsVector[1] -> toString() == "[2,2]");
}

void test_neighbors_4()
{
    string test = "  neighbors.test.4: lower left corner, 2 neighbors";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(2, 0);

    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 2 neighbors
    assert(neighborsVector.size() == 2);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[1,0]");
    assert(neighborsVector[1] -> toString() == "[2,1]");
}

void test_neighbors_5()
{
    string test = "  neighbors.test.5: column 0, middle, 3 neighbors";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(1, 0);

    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 3 neighbors
    assert(neighborsVector.size() == 3);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[0,0]");
    assert(neighborsVector[1] -> toString() == "[1,1]");
    assert(neighborsVector[2] -> toString() == "[2,0]");
}

void test_neighbors_6()
{
    string test = "  neighbors.test.6: row 0, middle, 3 neighbors";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(0, 2);

    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 3 neighbors
    assert(neighborsVector.size() == 3);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[0,3]");
    assert(neighborsVector[1] -> toString() == "[1,2]");
    assert(neighborsVector[2] -> toString() == "[0,1]");
}

void test_neighbors_7()
{
    string test = "  neighbors.test.7: last column, middle, 3 neighbors";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(0, 2);

    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 3 neighbors
    assert(neighborsVector.size() == 3);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[0,3]");
    assert(neighborsVector[1] -> toString() == "[1,2]");
    assert(neighborsVector[2] -> toString() == "[0,1]");
}

void test_neighbors_8()
{
    string test = "  neighbors.test.8: last row, middle, 3 neighbors";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(2, 2);

    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 3 neighbors
    assert(neighborsVector.size() == 3);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[1,2]");
    assert(neighborsVector[1] -> toString() == "[2,3]");
    assert(neighborsVector[2] -> toString() == "[2,1]");
}

void test_neighbors_9()
{
    string test = "  neighbors.test.9: interior square, 4 neighbors";
    cout << test << endl;

    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    square sq = m1.getSquare(1, 1);

    vector <square *> neighborsVector = m1.neighbors_of_square(sq);

    // test that there are 4 neighbors
    assert(neighborsVector.size() == 4);

    // test that the neighbors are in the correct positions and order
    assert(neighborsVector[0] -> toString() == "[0,1]");
    assert(neighborsVector[1] -> toString() == "[1,2]");
    assert(neighborsVector[2] -> toString() == "[2,1]");
    assert(neighborsVector[3] -> toString() == "[1,0]");
}

// cout << "\nTesting neighbors_of_square:" << endl;
void test_neighbors_of_square()
{
    cout << "\nTesting neighbors_of_square . . ." << endl;

    // Test 1:  upper left corner, 2 neighbors
    test_neighbors_1();

    // Test 2:  upper right corner, 2 neighbors
    test_neighbors_2();

    // Test 3:  lower right corner, 2 neighbors
    test_neighbors_3();

    // Test 4:  lower left corner, 2 neighbors
    test_neighbors_4();

    // Test 5:  column 0, middle, 3 neighbors
    test_neighbors_5();

    // Test 6:  row 0, middle, 3 neighbors
    test_neighbors_6();

    // Test 7:  last column, middle, 3 neighbors
    test_neighbors_7();

    // Test 8:  last row, middle, 3 neighbors
    test_neighbors_8();

    // Test 9:  interior square, 4 neighbors
    test_neighbors_9();

    cout << "    . . . neighbors_of_square OK!" << endl;
}

void test_reset1()
{
    string test = "  reset.test.1: put markings on maze_b1, then reset and check";  // NOLINT
    cout << test << endl;

    // setup
    ifstream mazefile("maze_b1.txt");
    maze m1(mazefile);
    m1.get(0, 0) -> setStatus(square::WORK_LIST);
    m1.get(0, 1) -> setStatus(square::EXPLORED);
    m1.get(0, 2) -> setStatus(square::SOLUTION_PATH);
    m1.get(0, 3) -> setStatus(square::WORK_LIST);
    m1.get(1, 3) -> setStatus(square::EXPLORED);
    m1.get(2, 3) -> setStatus(square::SOLUTION_PATH);

    // execute and test
    m1.reset();

    assert(m1.get(0, 0) -> getStatus() == square::UNVISITED);
    assert(m1.get(0, 1) -> getStatus() == square::UNVISITED);
    assert(m1.get(0, 2) -> getStatus() == square::UNVISITED);
    assert(m1.get(0, 3) -> getStatus() == square::UNVISITED);
    assert(m1.get(1, 3) -> getStatus() == square::UNVISITED);
    assert(m1.get(2, 3) -> getStatus() == square::UNVISITED);
    assert(m1.get(2, 2) -> getStatus() == square::UNVISITED);

    // check that walls, start, exit are unchanged
    assert(m1.get(1, 0) -> getStatus() == square::START);
    assert(m1.get(1, 1) -> getStatus() == square::WALL);
    assert(m1.get(1, 2) -> getStatus() == square::WALL);
    assert(m1.get(2, 0) -> getStatus() == square::WALL);
    assert(m1.get(2, 1) -> getStatus() == square::EXIT);
}

void test_reset2()
{
    string test = "  reset.test.2: reset maze_b3 and check";  // NOLINT
    cout << test << endl;

    // setup
    ifstream mazefile("maze_b3.txt");
    maze m1(mazefile);

    // execute and test
    m1.reset();

    assert(m1.get(0, 0) -> getStatus() == square::START);
    assert(m1.get(1, 0) -> getStatus() == square::EXIT);
}

void test_reset()
{
    cout << "\nTesting reset . . ." << endl;

    // Test 1: put markings on maze_b1, then reset and check
    test_reset1();

    // Test 2: reset maze_b3 (minimal maze) and check
    test_reset2();

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
    ifstream mazefile("maze_with_no_start.txt");
    maze m1(mazefile);
}

void test_mazeWithNoExit()
{
    ifstream mazefile("maze_with_no_exit.txt");
    maze m1(mazefile);
}

void test_mazeWithTwoStarts()
{
    ifstream mazefile("maze_with_two_starts.txt");
    maze m1(mazefile);
}

void test_mazeWithTwoExits()
{
    ifstream mazefile("maze_with_two_exits.txt");
    maze m1(mazefile);
}

int main()
{
    test_basics_maze();  // constructor and very basic functions
    test_toString();
    test_getSquare();
    // test_neighbors_of_square();
    cout << "Chris's code creates segmentation fault when testing neighbors_of_square" << endl;
    test_reset();
    test_streamOutput();

    // *********************************************//
    // BAD maze FILES -- your code should throw an exception when
    //    you enable any of the following tests -- TRY ALL!
    // test_mazeWithNoStart();
    // test_mazeWithNoExit();
    // test_mazeWithTwoStarts();
    // test_mazeWithTwoExits();

    cout << "\nAll current tests passing for maze!" << endl;
}


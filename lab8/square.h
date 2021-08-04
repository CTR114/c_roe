/*
*  square.h
*  square header file for Lab 8, Part 1
*
*  Barb Wahl & Theresa Wilson
*  Revised 3-18-17
*
*  DO NOT CHANGE THIS FILE
*
*  An instance of the square class represents a single square in the maze.
*
*  The four instance variables of a square are as follows:
*     - int `status`:
*           0 -- wall
*           1 -- start
*           2 -- exit
*           3 -- plain square, unvisited
*           4 -- plain square, on solver worklist
*           5 -- plain square, already explored, NOT on final solution path
*           6 -- plain square, already explored, ON final solution path
*
*     - int `row`: Indicates the row in which the square resides in the maze.
*       Row 0 is the top row.
*
*     - int `col`: indicates the column in which the square resides in the maze.
*       Column 0 is the leftmost column.
*
*     - square * `prev`: Answers the question, "Which square was being explored
*       when the current square was added to the worklist?"  The previous 
*       pointers can be followed (from current back to start) to construct 
*       the path used to find the current square. If the current square *is* 
*       the start square, prev will be null.
*/

#ifndef square_H
#define square_H

#include <iostream>
#include <string>

class square
{
 public:
    // STATUS CODES -- USE THESE CONSTANTS IN YOUR IMPLEMENTATION FILE 
    //    (do not use the actual number values)

    // Special squares:
    static const int WALL = 0;
    static const int START = 1;
    static const int EXIT = 2;
    // Plain squares:
    static const int UNVISITED = 3;
    static const int WORK_LIST = 4;
    static const int EXPLORED = 5;
    static const int SOLUTION_PATH = 6;

    /*
    *  Default constructor
    *  ALREADY IMPLEMENTED here in the header file.
    *  Postcondition: Makes a WALL square in the upper left corner of the maze
    *     (location [0,0]) with `prev` set to NULL.
    */
    square() { status = row = col = 0; prev = NULL; }

    /*
    *  Constructor with 3 parameters for status, row, and column
    *  Precondition:   WALL <= status_val <= UNVISITED
    *  Postcondition:  The new square has status, row, and col values
    *     initialized to status_val, row_val, and col_val, respectively.
    *  Postcondition:  The `prev` pointer is initialized to NULL.
    *  NOTE: throws domain_error exception if precondition fails
    */
    square(int status_val, int row_val, int col_val);

    // *** ACCESSORS *** //

    // Each get method returns the value of the corresponding instance variable.
    int getStatus() const;
    int getRow() const;
    int getCol() const;
    square * getPrev() const;

    /*
    *  isPlainSquare
    *  Postcondition:  Return value is true iff the square is not a wall,
    *     start, or exit square.
    */
    bool isPlainSquare() const;

    /*
    *  isStart
    *  Postcondition:  Return value is true iff the square is START square.
    */
    bool isStart() const;

    /*
    *  isExit
    *  Postcondition:  Return value is true iff the square is EXIT square.
    */
    bool isExit() const;

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
    *
    *  Hint:  Use a switch statement and the class constants (WALL, START,
    *         EXIT, etc.) to implement this method.
    */
    char toChar() const;

    /*
    *  toString
    *  Postcondition: Return value is a string for reporting the coordinates
    *     of the square in the form "[row_num,col_num]".
    *
    *  Example: If the square is in row 5 and column 0, return "[5,0]".
    */
    std::string toString() const;

    // *** MODIFIERS *** //

    /*
    *  setStatus
    *  Precondition:  This is not a wall square.
    *  Postcondition: `status` is set to new_status.
    *  NOTE: throws domain_error exception if precondition fails
    */
    void setStatus(int new_status);

    /*
    *  setPrev
    *  Precondition:  This is not a wall square.
    *  Postcondition:  This square's `prev` is set to ptr.
    *  NOTE: throws domain_error exception if precondition fails
    */
    void setPrev(square * ptr);

    /*
    *  reset
    *  Postcondition:  If this is a plain square, `status` is set to UNVISITED.
    *     Otherwise, its status is unchanged.
    *  Note:  Does NOT throw an exception for non-plain square.
    */
    void reset();

 private:
    int status;
    int row;
    int col;
    square * prev;
};

    // STREAM OUTPUT
    /*
    *  Postcondition:  Puts a single char, representing the square status, into
    *     the output stream `out`, and returns `out` to allow for chaining.
    *  Example: If sq.status is WALL, the character `#` is put into the output
    *     stream.
    *  NOTE:  Do not put any whitespace into `out` -- just put a single char
    *     for the status of `sq`.
    */
    std::ostream& operator<< (std::ostream &out, const square &sq);

#endif /* square_H */

// square.cpp -- Implementation of Square Class
// CS 223, Lab 8 Part 1
//
// Name:Chris roe
// Date: March 21
//
// STYLE TIP:  Use class constants THROUGHOUT your code for Lab 8, in place
//    of literal integers, to create readable code.  For example, to ask if
//    the square named `sq` is a wall square, you would write:
//
//          if (sq.getStatus() == square::WALL)
//
//       rather than:
//
//          if (sq.getStatus() == 0)
//
// CLASS INVARIANT:  square status is always one of the following:
//    WALL, START, EXIT, UNVISITED, WORK_LIST, EXPLORED, SOLUTION_PATH

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "square.h"

using namespace std;
    /*
    *  Constructor with 3 parameters for status, row, and column
    *  Precondition:   WALL <= status_val <= UNVISITED
    *  Postcondition:  The new square has status, row, and col values
    *     initialized to status_val, row_val, and col_val, respectively.
    *  Postcondition:  The `prev` pointer is initialized to NULL.
    *  NOTE: throws domain_error exception if precondition fails
    */
    square::square(int status_val, int row_val, int col_val)
    {
    	if (status_val < 0 || status_val > 6)
    	{	 	  	 	  	   	    	  	      	 	
    		throw domain_error( "Status val has to be > 0 and < 6 ");
    	}
    	status = status_val;
    	row = row_val;
    	col = col_val;
    	prev = NULL;
    }

    // *** ACCESSORS *** //

    // Each get method returns the value of the corresponding instance variable.
    int square::getStatus() const
    {
    	return status;
    }

    int square::getRow() const
    {
    	return row;
    }

    int square::getCol() const
    {
    	return col;
    }

    square * square::getPrev() const
    {
    	return prev;
    }

    /*    *  isPlainSquare
    *  Postcondition:  Return value is true iff the square is not a wall,
    *     start, or exit square.
    */
    bool square::isPlainSquare() const
    {	 	  	 	  	   	    	  	      	 	
    	if (status == WALL || status == START || status == EXIT)
    	{
    		return false;
    	}
    	return true;
    }

    /*
    *  isStart
    *  Postcondition:  Return value is true iff the square is START square.
    */
    bool square::isStart() const
    {
    	if (status == START && status == START)
    	{
    		return true;
    	}
    	return false;

    }

    /*
    *  isExit
    *  Postcondition:  Return value is true iff the square is EXIT square.
    */
    bool square::isExit() const
    {
    	if (status == EXIT && status == EXIT)
    	{
    		return true;
    	}
    	return false;

    }

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
    char square::toChar() const
    {	 	  	 	  	   	    	  	      	 	
    	switch (status)
    	{
    	case square::WALL:
    		return '#';
    	case square::START:
    		return 'S';
    	case square::EXIT:
    		return 'E';
    	case square::UNVISITED:
    		return '_';
    	case square::WORK_LIST:
    		return '@';
    	case square::EXPLORED:
    		return '.';
    	case square::SOLUTION_PATH:
    		return 'X';
    	}
    	return '?';
    	
    }

    

    /*
    *  toString
    *  Postcondition: Return value is a string for reporting the coordinates
    *     of the square in the form "[row_num,col_num]".
    *
    *  Example: If the square is in row 5 and column 0, return "[5,0]".
    */
    std::string square::toString() const
    {
        stringstream strm;
        strm << "[" << row << "," << col << "]";
        return strm.str();


    }	 	  	 	  	   	    	  	      	 	

    // *** MODIFIERS *** //

    /*
    *  setStatus
    *  Precondition:  This is not a wall square.
    *  Postcondition: `status` is set to new_status.
    *  NOTE: throws domain_error exception if precondition fails
    */
    void square::setStatus(int new_status)
    {
    	if (status == WALL)
    	{
    		throw domain_error("The square can not equal WALL");
    	}
    	status = new_status;

    }

    /*
    *  setPrev
    *  Precondition:  This is not a wall square.
    *  Postcondition:  This square's `prev` is set to ptr.
    *  NOTE: throws domain_error exception if precondition fails
    */
    void square::setPrev(square * ptr)
    {
    	if (status == WALL)
    	{
    		throw domain_error("Square can not equal WALL");
    	}
    	prev = ptr;

    }

    /*
    *  reset
    *  Postcondition:  If this is a plain square, `status` is set to UNVISITED.
    *     Otherwise, its status is unchanged.
    *  Note:  Does NOT throw an exception for non-plain square.
    */
    void square::reset()
    {	 	  	 	  	   	    	  	      	 	
    	if (isPlainSquare() == true)
    	{
    		status = UNVISITED;
    	}

    }


    // STREAM OUTPUT
    /*
    *  Postcondition:  Puts a single char, representing the square status, into
    *     the output stream `out`, and returns `out` to allow for chaining.
    *  Example: If sq.status is WALL, the character `#` is put into the output
    *     stream.
    *  NOTE:  Do not put any whitespace into `out` -- just put a single char
    *     for the status of `sq`.
    */
    std::ostream& operator<< (std::ostream &out, const square &sq)
    {
        out << sq.toChar();
        return out;

    }
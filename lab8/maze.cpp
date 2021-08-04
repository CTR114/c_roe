// maze.cpp -- Implementation of Maze Class
// CS 223, Lab 8 Part 2
//
// Name: Chris Roe
// Date: March 25th

/*
*  INSTANCE VARIABLES
*     square ** arr;  // pointer to a 2-dimensional dynamic array of squares
*     int numRows;    // number of rows in the maze
*     int numCols;    // number of columns in the maze
*     square * start; // pointer to the start square
*     square * exit;  // pointer to the exit square
*
*  >>>>> CLASS INVARIANT -- NOTE THIS IS DIFFERENT THAN IMAGE LAB <<<<<
*     1. arr[i][j] is the maze square in ROW i and COLUMN j.
*     2. Each maze has exactly one START square and one EXIT square.
*/

#include <stdexcept>    // provides standard exceptions
#include <cassert>      // provides assert
#include <sstream>      // provides stringstreams
#include <iostream>
#include "maze.h"
#include "square.h"

using namespace std;
/*
    *  constructor -- initializes a maze from an input stream
    *  Input: `in` is a stream of whitespace-separated tokens, and there
    *     is at least one whitespace character after the last token.
    *  Precondition:  The first two tokens of `in` can be read as positive
    *     integers (they represent the rows (R) and columns (C) for the
    *     dimensions of the maze).
    *  Precondition:  There are R*C tokens to be extracted following the maze
    *     dimensions, and each of these is a digit in the range 0 to 3.
    *  Precondition:  There is exactly one start square and one exit square.
    *  Postcondition: `arr` points to the R x C array of maze squares.
    *  Postcondition: `numRows` and `numCols` have been properly initialized.
    *  Postcondition: `start` points to the start square and `exit` points to 
    *     the exit square.
    *  NOTE: Throws invalid_argument exception if a precondition fails.
    */
    maze::maze(std::istream &in)
    {	 	  	 	  	   	    	  	      	 	
        int start1 = 0;
        int exit1 = 0;
        int temp1;
    	in >> numRows;     // number of rows in the maze
    	in >> numCols;     // number of columns in the maze
    	if (numCols < 0 || numRows < 0)
    	{
    		throw invalid_argument(" The cols and rows must be positive");
    	}
    	arr = new square* [numRows];
    	for ( int x = 0; x < numRows; x++)
    	{
    		arr[x] = new square[numCols];
    	}
		for( int x = 0; x < numRows; x++)
		{
			for (int y = 0; y < numCols; y++)
			{
				in >> temp1;
				arr[x][y] = square(temp1, x, y);
				if (arr[x][y].getStatus() == 1)
				{
					start = &arr[x][y];
					start1++;
				}
				if (arr[x][y].getStatus() == 2)
                {
                    exit = &arr[x][y];
                    exit1++;
                }
            }			
		}
		if (start1 != 1 || exit1 != 1)
        {
            throw invalid_argument("There can only be one start and one exit");
        }	 	  	 	  	   	    	  	      	 	
    }

    /*
    *  Destructor
    */
    maze::~maze()
    {
        for (int x = 0; x < numRows; x++)
        {
            delete[] arr[x];
        }
        delete[] arr;
        arr = NULL;

    }

    // *** Getters *** //
    square* maze::getStart() const
    {
        return start;

    }
    square* maze::getExit() const
    {
        return exit;

    }
    int maze::getNumRows() const
    {
        return numRows;

    }
    int maze::getNumCols() const
    {
        return numCols;

    }	 	  	 	  	   	    	  	      	 	

    /*
    *  get -- get a pointer to a square by row and column indices
    *  Precondition:  `i` is in range 0 through numRows - 1.
    *  Precondition:  `j` is in range 0 through numCols - 1.
    *  Postcondition:  Return value is a pointer to the square in
    *     row i and column j of this maze.
    *  NOTE: Throws invalid_argument exception if a precondition fails.
    */
    square* maze::get(int i, int j) const
    {
        if ( j < 0 || j > numCols - 1 || i < 0 || i > numRows - 1 )
        {
            throw invalid_argument(" i and j need to be in the square");
        }
        return &arr[i][j];

    }

    /*
    *  getSquare -- get a reference to a square by row and column indices
    *  Precondition:  `i` is in range 0 through numRows - 1.
    *  Precondition:  `j` is in range 0 through numCols - 1.
    *  Postcondition:  Return value is a reference to the square in
    *     row i and column j of this maze.
    *  NOTE: Throws invalid_argument exception if a precondition fails.
    */
    square& maze::getSquare(int i, int j) const
    {
        if ( i < 0 || i > numRows-1 || j < 0 || j > numCols-1 )
        {
            throw invalid_argument(" i and j need to be in the square");
        }
        return arr[i][j];
    }

    // *** Other Accessors *** //

    /*
    *  toString
    *  Postcondition: Return value is a string for printing the text version
    *     of the maze, with a '\n' at the very front, a single space after each
    *     square's status symbol, and a '\n' after each row.
    *  EXAMPLE:  If the maze was constructed from a stream holding the following
    *  information:  3 4   3 3 3 3  1 0 0 3  0 2 3 3
    *  then the printed version of the maze would look as follows:
    *     _ _ _ _
    *     S # # _
    *     # E _ _
    */
    std::string maze::toString() const
    {	 	  	 	  	   	    	  	      	 	
        std::ostringstream out;
        for (int x = 0; x < numRows; x++)
        {
            out << '\n';
            for (int y = 0; y < numCols; y++)
            {
                out << arr[x][y].toChar() << " ";
            }
        }
        out << '\n';
        return out.str();

    }

    /*
    *  neighbors_of_square
    *  Precondition:  `sq` is a square in this maze.
    *  Postcondition:  Return value is a vector of pointers to the squares
    *     in this maze which are neighbors of `sq`, where the vector is filled
    *     in this order:  North (up one), East (right one), South (down one),
    *     and West (left one).
    *  Note:  If there is NO neighbor in a given direction, the vector will
    *     have size less than 4.  Corner squares have just two neighbors, and
    *     side squares have three neighbors.
    *  EXAMPLE:  In the maze
    *     _ _ _ _
    *     S # # _
    *     # E _ _
    *  if sq is the start square (position [1,0]) then the return value will
    *  be a vector of length 3 storing:
    *     - a pointer to the [0,0] square
    *     - followed by a pointer to the [1,1] square
    *     - followed by a pointer to the [2,0] square
    */
    std::vector<square *> maze::neighbors_of_square(square sq) const
    {	 	  	 	  	   	    	  	      	 	
        vector<square *> v;
        int row = sq.getRow();
        int col = sq.getCol();
        if (row-1 >= 0)
        {
            v.push_back(&arr[row-1][col]);
        }
        if (row+1 <= this -> getNumRows()-1)
        {
            v.push_back(&arr[row-1][col]);
        }
        if (col+1 <= this -> getNumCols()-1)
        {
            v.push_back(&arr[row][col+1]);
        }
        if (col-1 >= 0)
        {
            v.push_back(&arr[row][col-1]);
        }
        return v;

    }

    // *** Modifiers *** //

    /*
    *  reset - erase all "markings" on maze squares
    *  Postcondition:  All squares in the maze have status WALL, START, EXIT,
    *     or UNVISITED.  Specifically, any squares with status "worklist",
    *     "explored", or "solution_path" have been set back to status
    *     "unvisited", while all squares with status wall, start, or exit
    *     are unchanged.
    */
    void maze::reset()
    {
        for ( int x = 0; x < numRows; x++)
        {	 	  	 	  	   	    	  	      	 	
            for (int y = 0; y < numCols; y++)
            {
                arr[x][y].reset();
            }
        }

    }

/*
*  output stream operator
*  Postcondition:  The string representation of this maze is put into
*     `out`, and `out` is returned to allow for chaining of output.
*
*  Hint:  maze.toString()
*/
std::ostream& operator<< (std::ostream &out, const maze &maze)
{
    for ( int x = 0; x < maze.getNumRows(); x++)
    {
        out << '\n';
        for ( int y = 0; y < maze.getNumCols(); y++)
        {
            out << maze.getSquare(x,y) << " ";
        }
    }
    out << '\n';
    return out;

}	 	  	 	  	   	    	  	      	 	

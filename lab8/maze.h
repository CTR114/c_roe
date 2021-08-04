/*
*  maze.h
*  maze header file for Lab 8, Part 2
*
*  Barb Wahl & Theresa Wilson
*  Revised 3-18-17
*
*  DO NOT CHANGE THIS FILE
*
*  General information about the maze class and how it will be used:
*     A maze is represented by a 2-dimensional dynamic array of squares. Each
*     maze has exactly one start square and one exit square. Some mazes are
*     impossible to solve (no solution path); some have a unique solution path;
*     and some have two or more solution paths.
*
*     The smallest possible mazes have just two squares.  The size of the
*     largest maze is constrained only by available memory.
*
*  The maze constructor:
*
*     A maze is constructed from a file input stream of the following format:
*       - The tokens are separated by any kind of whitespace characters
*         (spaces, tabs, newlines, etc.), and the final token is followed
*         by whitespace.
*
*       - The first token is a positive integer representing the number of
*         rows R in the maze. 
*
*       - The second token is a positive integer representing the number of 
*         columns C in the maze.
*
*       - The remaining R*C tokens are digits in the range 0 to 3. These values 
*         indicate the types of squares in the maze from left to right and top to
*         bottom. The first C values correspond to the top row of the maze, left
*         to right, the next C values correspond to the second row, and so on.
*
*         The digits 0 - 3 are square status codes: 
*              0 => wall (#)
*              1 => start (S)
*              2 => exit (E)
*              3 => plain square, unvisited (_)
*         (Refer to square.h for full documentation of the square class.)
*
*       - EXAMPLE:  If the stream contents are as follows:
*              3 4   3 3 3   3 1    0  \n 0 3 0 2 \t 3 3   \n
*
*         then the maze will have 3 rows, 4 columns, and will look as follows
*         when printed:
*              _ _ _ _
*              S # # _
*              # E _ _
*
*  INSTANCE VARIABLES
*     square ** arr;   // pointer to a 2-dimensional dynamic array of squares
*     int numRows;     // number of rows in the maze
*     int numCols;     // number of columns in the maze
*     square * start;  // pointer to the start square
*     square * exit;   // pointer to the exit square
*
*  Copy Constructor:  disabled
*  Assignment Operator:  disabled
*/

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <stdexcept>
#include "square.h"

class maze
{
 public:
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
    explicit maze(std::istream &in);

    /*
    *  Destructor
    */
    ~maze();

    // *** Getters *** //
    square* getStart() const;
    square* getExit() const;
    int getNumRows() const;
    int getNumCols() const;

    /*
    *  get -- get a pointer to a square by row and column indices
    *  Precondition:  `i` is in range 0 through numRows - 1.
    *  Precondition:  `j` is in range 0 through numCols - 1.
    *  Postcondition:  Return value is a pointer to the square in
    *     row i and column j of this maze.
    *  NOTE: Throws invalid_argument exception if a precondition fails.
    */
    square* get(int i, int j) const;

    /*
    *  getSquare -- get a reference to a square by row and column indices
    *  Precondition:  `i` is in range 0 through numRows - 1.
    *  Precondition:  `j` is in range 0 through numCols - 1.
    *  Postcondition:  Return value is a reference to the square in
    *     row i and column j of this maze.
    *  NOTE: Throws invalid_argument exception if a precondition fails.
    */
    square& getSquare(int i, int j) const;

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
    std::string toString() const;

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
    std::vector<square *> neighbors_of_square(square sq) const;

    // *** Modifiers *** //

    /*
    *  reset - erase all "markings" on maze squares
    *  Postcondition:  All squares in the maze have status WALL, START, EXIT,
    *     or UNVISITED.  Specifically, any squares with status "worklist",
    *     "explored", or "solution_path" have been set back to status
    *     "unvisited", while all squares with status wall, start, or exit
    *     are unchanged.
    */
    void reset();

 private:
    square** arr;   // pointer to a 2-dimensional dynamic array of squares
    int numRows;     // number of rows in the maze
    int numCols;     // number of columns in the maze
    square* start;  // pointer to the start square
    square* exit;   // pointer to the exit square

    // disabled copy constructor (not needed, DON'T implement!)
    maze(const maze &other);

    // disabled assignment operator (not needed, DON'T implement!)
    maze& operator=(const maze &other);
};

/*
*  output stream operator
*  Postcondition:  The string representation of this maze is put into
*     `out`, and `out` is returned to allow for chaining of output.
*
*  Hint:  maze.toString()
*/
std::ostream& operator<< (std::ostream &out, const maze &maze);

#endif /* MAZE_H */

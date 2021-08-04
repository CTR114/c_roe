// FILE: cs223lab.h
// Header file that defines some info used across all CS223 labs
//
// Theresa Wilson, 4-8-17
//

#ifndef CS223LAB_H
#define CS223LAB_H

// Global variable for turning debugging on and off
extern bool verboseout;

namespace generic
{
// print function
// prints the given string plus endl
void print(std::string str)
{
    std::cout << str << std::endl;
}

// print_warning function
// prints the given warning plus endl
void print_warning(std::string str)
{
    std::string stars = "";
    for (int i = 0; i < str.size() + 9; i++) { stars += "*"; }
    std::cout << std::endl << stars << std::endl;
    std::cout << "WARNING: " << str;
    std::cout << std::endl << stars << std::endl;
}

// TEMPLATE FUNCTION TO HELP WORK WITH non-string TYPES
template < class T > std::string to_string(const T& n)
{
    // put n into a stream, then return the .str() result (string
    // equivalent of n)
    std::ostringstream stm;
    stm << n;
    return stm.str();
}
} // END namespace generic

#endif

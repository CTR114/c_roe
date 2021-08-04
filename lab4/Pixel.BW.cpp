// Pixel.cpp
// Implementation file for Lab 4: Pixel Class

// Name:  Barb Wahl
// Date:  2-7-2017

#include <iostream>
#include <sstream>
#include "Pixel.h"

using namespace std;

// VALUE SEMANTICS for the Pixel class:
//   Assignments and the copy constructor may be used with Pixel objects.

// FRIEND FUNCTIONS (may access private data directly)
//   friend std::ostream& operator<< (std::ostream& out, const Pixel& pix);
//   friend std::istream& operator>> (std::istream& in, Pixel& pix);

namespace imagelab
{
   // CONSTRUCTOR for the Pixel class:
   //     Sets the RGB values for a new pixel. The default constructor will
   //       create a black pixel (RGB values all set to 0).
   //     Preconditions: 0 <= r <= 255; 0 <= g <= 255; 0 <= b <= 255
   //     Postconditions:
   //       -The pixel's red value is set to the value of r.
   //       -The pixel's green value is set to the value of g.
   //       -The pixel's blue value is set to the value of b.
   Pixel::Pixel( int r, int g, int b)
   {
      rval = r;
      gval = g;
      bval = b;
   }

   //     Sets the RGB values for the pixel.
   //     Preconditions: 0 <= r <= 255; 0 <= g <= 255; 0 <= b <= 255
   //     Postconditions:
   //       -The pixel's red value is set to the value of r.
   //       -The pixel's green value is set to the value of g.
   //       -The pixel's blue value is set to the value of b.
   void Pixel::set( int r, int g, int b )
   {
      rval = r;
      gval = g;
      bval = b;
   }

   //     Sets the red value for the pixel.
   //     Precondition: 0 <= r <= 255
   //     Postconditions: The pixel's red value is set to the value of r.
   void Pixel::setRed( int r )
   {
      rval = r;
   }

   //     Sets the green value for the pixel.
   //     Precondition: 0 <= g <= 255
   //     Postconditions: The pixel's green value is set to the value of g.
   void Pixel::setGreen( int g )
   {
      gval = g;
   }

   //     Sets the blue value for the pixel.
   //     Precondition: 0 <= b <= 255
   //     Postconditions: The pixel's blue value is set to the value of b.
   void Pixel::setBlue( int b )
   {
      bval = b;
   }

   //     Precondition: None
   //     Postcondition: The return value is the red value for the pixel.
   int Pixel::getRed( ) const
   {
      return rval;
   }

   //     Precondition: None
   //     Postcondition: The return value is the green value for the pixel.
   int Pixel::getGreen( ) const
   {
      return gval;
   }

   //     Precondition: None
   //     Postcondition: The return value is the blue value for the pixel.
   int Pixel::getBlue( ) const
   {
      return bval;
   }

   // OPERATOR OVERLOADING for the Pixel class:

   //     Equivalence operator for pixels.
   //     Two pixels are equivalent if the pixels have the same red
   //       values, the same green values, and the same blue values.
   bool operator== (const Pixel& pix1, const Pixel& pix2)
   {
      return pix1.getRed() == pix2.getRed() &&
             pix1.getGreen() == pix2.getGreen() &&
             pix1.getBlue() == pix2.getBlue();
   }

   //     Inequivalence operator for pixels.
   bool operator!= (const Pixel& pix1, const Pixel& pix2)
   {
      return !(pix1 == pix2);
   }

   //     Stream output operator (<<) for outputting the contents of a pixel.
   //     Example: A pixel with red value 100, green value 150, and blue value 200
   //              will produce the following output:100 150 200
   //     Note: Returns the `out` parameter to allow chaining of stream output.
   std::ostream& operator<< (std::ostream& out, const Pixel& pix)
   {
      out << pix.rval << " " << pix.gval << " " << pix.bval;
      return out;
   }

   //     Stream input operator (>>) for reading a pixel from an input stream.
   //     Precondition: `in` holds a string of three integers separated by spaces;
   //        each integer must be in the range 0 to 255, inclusive.
   //     Postconditions:
   //        -The red value of pix is set to the first integer.
   //        -The green value of pix is set to the second integer.
   //        -The blue value of pix is set to the third integer.
   std::istream& operator>> (std::istream& in, Pixel& pix)
   {
      int rval, gval, bval;
      in >> rval >> gval >> bval;
      pix.setRed(rval);
      pix.setGreen(gval);
      pix.setBlue(bval);
      //cout << "input stream called with colors: " << rval << " " << gval << " " << bval << endl;
      //cout << "colors were set to " << pix.getRed() << " " << pix.getGreen() << " " << pix.getBlue() << endl;
      return in;
   }

}

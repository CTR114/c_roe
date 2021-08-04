// Image.cpp
// Implementation file for Lab 4: Image Class

// Name:  Barb Wahl
// Date:  2-8-2017

// INVARIANTS for the Image class:
//   1. Images are a 2-D array of pixels indexed by their x,y-coordinates such that:
//          (0,0) is the pixel in the upper-left corner
//          (0,width-1) is the pixel in the upper-right corner
//          (height-1,0) is the pixel in the lower-left corner
//          (height-1,width-1) is the pixel in the lower-right corner
//
//   2. In the 2-D image array, pixels are indexed first by their x-coordinate and
//      then by their y-coordinate.  For example, if arr is the 2-D array of pixels,
//      the pixel at coordinate (x,y) will be accessed as: arr[x][y].

// MEMBER CONSTANTS
//    static const int MAX_COLOR = 255;

// INSTANCE VARIABLES
//    std::string format;  // image format
//    int width;           // width of the image in pixels
//    int height;          // height of the image in pixels
//    int maxcolor;        // maximum int value for red or blue or green color
//    Pixel ** arr;        // pointer to a 2-dimensional dynamic array of Pixels

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include "Pixel.h"
#include "Image.h"

using namespace std;

namespace imagelab
{
   // CONSTRUCTORS
   Image::Image(int w, int h, int r, int g, int b)
   {
      format = "P3";
      width = w;
      height = h;
      maxcolor = MAX_COLOR;

      arr = new Pixel*[w];  // column pointers, indexed 0 to w - 1

      for (int x = 0; x < w; x++)
      {
         arr[x] = new Pixel[h];  // xth column of pixels, indexed 0 to h - 1
         for (int y = 0; y < h; y++)
         {
            arr[x][y].set(r, g, b);
         }
      }
   }

   // copy constructor
   Image::Image(const Image &other)
   {
      int x, y;

      // 1. copy the other values over from other
      width = other.getWidth();
      height = other.getHeight();
      maxcolor = other.getMaxColor();
      format = other.getFormat();

      // 2. reallocate memory for this -> arr and copy values
      arr = new Pixel*[width];  // column pointers, indexed 0 to w - 1

      for (x = 0; x < width; x++)
      {
         arr[x] = new Pixel[height];  // xth column of pixels, indexed 0 to h - 1
         for (y = 0; y < height; y++)
         {
            arr[x][y] = other.getPixel(x, y);
         }
      }
   }

   // constructor for creating an image from stream input
   Image::Image(std::istream &in)
   {
      in >> format >> width >> height >> maxcolor;
      assert(format == "P3");

      // now create the array
      arr = new Pixel*[width];  // column pointers, indexed 0 to w - 1

      for (int x = 0; x < width; x++)
      {
         arr[x] = new Pixel[height];  // xth column of pixels, indexed 0 to h - 1
      }

      // to store the Pixel info from the file, iterate FIRST over the rows (y)
      // then over the columns (x)
      for (int y = 0; y < height; y++)
      {
         for (int x = 0; x < width; x++)
         {
            in >> arr[x][y];
         }
      }
   }

   // DESTRUCTOR
   Image::~Image()
   {
      int x;
      for (x = 0; x < width; x++)
      {
         delete [] arr[x];
      }

      delete [] arr;
   }

   // MODIFICATION MEMBER FUNCTIONS
   void Image::setPixel(int x, int y, Pixel pix)
   {
      arr[x][y] = pix;
   }

   void Image::setPixel(int x, int y, int r, int g, int b)
   {
      Pixel pix(r, g, b);
      setPixel(x, y, pix);
   }

   // CONSTANT MEMBER FUNCTIONS
   std::string Image::getFormat() const
   {
      return format;
   }

   int Image::getMaxColor() const
   {
      return maxcolor;
   }

   int Image::getWidth() const
   {
      return width;
   }

   int Image::getHeight() const
   {
      return height;
   }

   Pixel Image::getPixel(int x, int y) const
   {
      Pixel pix(arr[x][y]);      // copy constructor for Pixel
      return pix;
   }

   // OPERATOR OVERLOADS

   // assignment operator makes "this" an independent clone of "source"
   // and avoids creating a memory leak!
   void Image::operator= (const Image& source)
   {
      int x, y;

      // 0. self-assignment check (don't fault students for lacking this)
      if (this == &source) { return; }

      // 1. deallocate memory for this -> arr
      for (x = 0; x < width; x++)
      {
         delete [] arr[x];
      }
      delete [] arr;
      arr = NULL;

      // 2. copy the other values over from source
      width = source.getWidth();
      height = source.getHeight();
      maxcolor = source.getMaxColor();
      format = source.getFormat();

      // 3. reallocate memory for this -> arr and copy values
      arr = new Pixel*[width];  // column pointers, indexed 0 to w - 1

      for (x = 0; x < width; x++)
      {
         arr[x] = new Pixel[height];  // xth column of pixels, indexed 0 to h - 1
         for (y = 0; y < height; y++)
         {
            arr[x][y] = source.getPixel(x, y);
         }
      }
   }

   /*
    *  FRIEND
    *  output stream operator, for printing the PPM version of the image
    The difference in the plain format is:

        There is exactly one image in a file.
        The magic number is P3 instead of P6.
        Each sample in the raster is represented as an ASCII decimal number (of arbitrary size).
        Each sample in the raster has white space before and after it. There must be at least one character
        of white space between any two samples, but there is no maximum.
        There is no particular separation
        of one pixel from another -- just the required separation between the blue sample of one pixel from
        the red sample of the next pixel.
        ( ??? No line should be longer than 70 characters. )

    Here is an example of a small image in this format.

    P3
    # feep.ppm
    4 4
    15
     0  0  0    0  0  0    0  0  0   15  0 15
     0  0  0    0 15  7    0  0  0    0  0  0
     0  0  0    0  0  0    0 15  7    0  0  0
    15  0 15    0  0  0    0  0  0    0  0  0

    There is a newline character at the end of each of these lines.

    NOTE:  Inspired by the actual .ppm files used by image_stacker,
    I've changed to putting a '\n' after each pixel.
    */
   std::ostream& operator<< (std::ostream &out, const Image &image)
   {
      int h = image.getHeight();
      int w = image.getWidth();
      int maxColor = image.getMaxColor();

      out << image.getFormat() << '\n' << w << " " << h << '\n' << maxColor << '\n';
      for (int y = 0; y < h; y++)
      {
         for (int x = 0; x < w; x++)
         {
            out << image.getPixel(x, y) << '\n';
         }
      }
      return out;
   }
}



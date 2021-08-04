// Image.cpp
// Implementation file for Lab 4: Image Class

// Name: Chris roe
// Date: 2/7/17

// INVARIANTS for the Image class:
//   1. Images are a 2-D array of pixels indexed by their x,y-coordinates such that:
//          (0,0) is the pixel in the upper-left corner
//          (width-1,0) is the pixel in the upper-right corner
//          (0,height-1) is the pixel in the lower-left corner
//          (width-1,height-1) is the pixel in the lower-right corner
//
//   2. In the 2-D image array, pixels are indexed first by their x-coordinate and
//      then by their y-coordinate.  For example, if arr is the 2-D array of pixels,
//      the pixel at coordinate (x,y) will be accessed as: arr[x][y].

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pixel.h"
#include "Image.h"

using namespace std;

namespace imagelab
{
	Image::Image(int w, int h, int r, int g, int b)
	{
//Sets the format, width, height, and maxcolor for the
//the new Image object. Also creates a default image
//of the designated width and height that is:
//a) a dynamic 2-D array of Pixel objects
//b) all Pixels have the color represented by
//the given red, green, and blue RGB value.
//Preconditions: w > 0; h > 0; 0 <= r <= 255; 0 <= g <= 255; 0 <= b <= 255
		if (r>=0 && r<=255 &&
			g>=0 && g<=255 &&
			b>=0 && b<=255)
		{
			Pixel pix(r,g,b);
			format = "P3";
			width = w;
			height = h;
			maxcolor = MAX_COLOR;
			arr= new Pixel* [height];
			for( int i = 0; i<height;i++)
			{
				arr[i]=new Pixel[width];
			}
			for (int j=0; j<height; j++)
			{
				for (int k=0; k<width;k++)
				{
					arr[j][k] = pix; //create arr pointer to arr pointer
				}
			}
		}
	}


	Image::Image(const Image& other)
	{
	//Creates a copy of the given image.
//     Postconditions:
//        Image copy's format is set to the format of other.
//        Image copy's width is set to the width of other.
//        Image copy's height is set to the height of other.
//        Image copy's maxcolor is set to the maxcolor of other.
//        Image copy's arr is a 2-D array of pixels with the same width,
//          height as other's array of pixels.
//        Each pixel in the copy's pixel array has the same RGB color values
//          as the pixel at the identical coordinate in other's pixel array.
//        The pixel array for the new Image is stored independently of the other
//          object's pixel array (deep copy).
		format = other.getFormat();
		width = other.getWidth();
		height = other.getHeight();
		maxcolor = other.getMaxColor();
		arr = new Pixel *[height];
		for (int i=0;i<height; i++)
		{
		 	arr[i]= new Pixel[width];
			for (int j = 0; j<width; j++)
		 	{
		 		arr[i][j] = other.arr[i][j];
		 	}
		}
	}



	Image::Image(istream &in)
	{

		// string Height_stream;
		// string width_stream;
		// string Maxstream;
		// getline(in,format);
		// getline(in,width_stream);
		// istringstream buffer(width_stream);
		// buffer>>width;
		// getline(in,Height_stream);
		// istringstream buffer1(Height_stream);
		// buffer1>>height;
		// getline(in,Maxstream);
		// istringstream buffer2(Maxstream);
		// buffer2>> maxcolor;

		in>> format;
		in>> width;
		in>> height;
		in>>maxcolor;

		arr = new Pixel* [width];
		for (int i=0; i<width;i++)
		{
			arr[i]= new Pixel [height];
		}

		for (int y=0; y<height;y++)
		{
			for (int x=0;x<width;x++)
			{
				string red;
				string green;
				string blue;
				int rval;
				int gval;
				int bval;
				in>>rval;
				in>>gval;
				in>>bval;
				arr[x][y].set(rval,gval,bval);
			}
		}

	}

	// }
//     Reads a PPM image from the stream input. Sets the format, width
//       height, and maxcolor for the new Image object based on the
//       input, and creates a 2-D array of pixels, which is populated
//       by the pixel values read from stream input.
//
//     PPM format in brief:
//        All items in PPM format are separated by whitespace.
//          1st item: 2-character format string
//          2nd item: image width in pixels
//          3nd item: image height in pixels
//          4th item: maximum pixel color (255)
//          5th item: pixel-1 red value
//          6th item: pixel-1 green value
//          7th item: pixel-1 blue value
//          8th item: pixel-2 red value
//          9th item: pixel-2 green value
//            .... and so on until the RGB values have been given
//            for all the pixels in the image
//
//        For example, the following are the first 8 lines from a
//        PPM file that is 600 x 339 pixels.  The RGB values for
//        the first five pixels in the image are shown.
//
//          P3
//          600 339
//          255
//          0 0 0
//          0 10 16
//          86 8 14
//          0 0 0
//          84 6 8
//
//        In additional the PPM files that you will be working with will always
//        be formatted as follows:
//
//            1st line: P3
//            2nd line: width height
//            3rd line: 255
//            4th line: r g b
//            5th line: r g b
//                .
//                .
//            last line: r g b
//
//        Note that from line 4 to the end of the file, there will be one pixel
//        per line.
//
//        IMPORTANT: When writing out new PPM files, please use the format
//        above. This will make it straightforward to check whether your
//        stream output function is working correctly. (See moodle instructions.)
//
//     Postconditions:
//        Image format is set to the image format designated by the input stream.
//        Image width is set to the width designated by the input stream.
//        Image height is set to the height designated by the input stream.
//        Image maxcolor is set to the max color designated by the input stream.
//        Image arr is a 2-D array of pixels of the given width and height.
//        Each pixel in the pixel array is set to the RGB color designated
//          for the pixel by the the input stream.
//
//
//
//
	void Image::setPixel(int x, int y, Pixel pix)
	{
		 if (x< width && y< height)
		{
			arr[x][y] = pix;
		}

	}
//     The pixel in arr at position x,y is set to pix.
//     Preconditions:
//       (x, y) is a valid position in the array for this image.
//     Postconditions:
//       The pixel at position x,y is pix.
//

	// PATCHED BY BW -- this was commented out
	// I had to prepend "Image::" and add a stub
	void Image::setPixel(int x, int y, int r, int g, int b){}
//     The pixel in arr at position x,y is set to the given RGB values.
//     Preconditions:
//       (x, y) is a valid position in the array for this image.
//       r <= 255; 0 <= g <= 255; 0 <= b <= 255
//     Postconditions:
//       The pixel at position x,y has the red value r, the green value
//       g, and the blue value b.
//
//
// CONSTANT MEMBER FUNCTIONS for the Image class:
//
	Pixel Image::getPixel(int x, int y) const
	{
		 if (x<width && y<height)
		{
			return arr[x][y];
		}

	}
//     Precondition: (x, y) is a valid position in the array for this image
//     Postcondition: returns the pixel at position x,y.
//
	string Image::getFormat() const
	{
		return format;
	}
//     Postcondition: returns the format of the image.
//
	int Image::getMaxColor() const
	{
		return maxcolor;
	}
//     Postcondition: returns the maximum color value of the image.
//
	int Image::getWidth() const
	{
		return width;
	}
//     Postcondition: returns the width of the image in pixels.
//
	int Image::getHeight() const
	{
		return height;
	}
//     Postcondition: returns the height of the image in pixels.
//
//
// VALUE SEMANTICS for the Image class:
//   The copy constructor may be used with Image objects.
//   The assignment operator may be used with Image objects.
// DESTRUCTOR for the Image class:


// MODIFICATION MEMBER FUNCTIONS for the Image class:
//
//
// OPERATOR OVERLOADING for the Image class:
//

	void Image::operator= (const Image& source)
	{
		for (int i=0;i<height;i++)
		{
		 	delete[] arr[i];
		 	arr[i]=NULL;
		}
		delete[] arr;
		arr= NULL;
		height=source.getHeight();
		width= source.getWidth();
		format= source.getFormat();
		maxcolor= source.getMaxColor();
		arr= new Pixel *[height];
		for (int i= 0; i<height; i++)
		{
			arr[i] = new Pixel[width];
			for (int j = 0; j<width; j++)
			{
				arr[i][j]= source.arr[i][j];
			}
		}

	}

//
	ostream& operator<< (std::ostream& out, const Image& img)
	{
		 out<< img.getFormat()<<endl;
		 out<< img.getWidth()<< " "<< img.getHeight()<<endl;
		 out<<img.getMaxColor()<< endl;
		 for (int i=0;i<img.getHeight(); i++)
		 {
		 	for (int j =0; j<img.getWidth();j++)
		 	{
			 	out<< img.getPixel(j,i)<<endl;
			}

		 }
		 return out;
	}


	Image::~Image()
	{
		for (int i =0; i<height; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr= NULL;

	}
}
//     Deallocates memory used by an Image object.
//     Postcondition: All memory used by the pixel array is deleted, and
//       the image's pixel array arr is set to NULL.
//
//
//



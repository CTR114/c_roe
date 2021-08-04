// Pixel.cpp
// Implementation file for Lab 4: Pixel Class

// Name: Chris Roe
// Date: 2/7/17

#include <iostream>
#include <sstream>
#include "Pixel.h"

using namespace std;

namespace imagelab
{

Pixel::Pixel(int r, int g, int b)
{
	rval = r;
	gval = g;
	bval = b;
	r<=255;
	r>=0;
	g<=255;
	g>=0;
	b<=255;
	b>=0;
}





	//Modifications


	//  Postconditions: 
	//   The pixel's red value is set to the value of r.
	//       -The pixel's green value is set to the value of g.
	//       -The pixel's blue value is set to the value of b.

void Pixel::set( int r, int g, int b )
{	 	  	 	  	   	    	  	      	 	
	
	if (r>=255)
	{

		rval = 255;
	}
	else if (r<=0)

	{
		rval = 0;
	}

	else
	{
		rval = r;
	}
	if (g>=255)
	{
		gval = 255;
	}
	else if (g<=0)
	{
		gval = 0;
	}
	else
	{
		gval = g;
	}
	if (b>=255)
	{
		bval = 255;
	}
	else if (b<=0)
	{
		bval = 0;
	}	 	  	 	  	   	    	  	      	 	
	else
	{
		bval = b;
	}
}




void Pixel::setRed( int r )
{
	//Sets the red value for the pixel.
	//Precondition: 0 <= r <= 255
	//Postconditions: The pixel's red value is set to the value of r.
	if (r>=255)
	{
		rval = 255;
	}
	else if (r<=0)
	{
		rval = 0;
	}
	else
	{
		rval = r;
	}
}

	

void Pixel::setGreen( int g )
{
	//     Sets the green value for the pixel.
	//     Precondition: 0 <= g <= 255
	//     Postconditions: The pixel's green value is set to the value of g.
	if (g>=255)
	{	 	  	 	  	   	    	  	      	 	
		gval = 255;
	}
	else if (g<=0)
	{
		gval = 0;
	}
	else
	{
		gval = g;
	}
}

void Pixel::setBlue( int b )
{
	//     Sets the blue value for the pixel.
	//     Precondition: 0 <= b <= 255
	//     Postconditions: The pixel's blue value is set to the value of b.
	//
	if (b>=255)
	{
		bval = 255;
	}
	else if (b<=0)
	{
		bval = 0;
	}
	else
	{
		bval = b;
	}
	
}


//ACCESSOR MEMBER FUNCTIONS for Pixel class:

int Pixel::getRed( ) const
{	 	  	 	  	   	    	  	      	 	
	return rval;
}

int Pixel::getGreen( ) const
{
	return gval;
}

int Pixel::getBlue( ) const
{
	return bval;
}

// OPERATOR OVERLOADING for the Pixel class:
//
bool operator== (const Pixel& pix1, const Pixel& pix2)
{
	if (pix1.getRed()==pix2.getRed())
	{
		if (pix1.getBlue()==pix2.getBlue())
		{
			if (pix1.getGreen()==pix2.getGreen())
			{
				return true;
			}
		}
	}
	return false;
}

bool operator!= (const Pixel& pix1, const Pixel& pix2)
{
	if ( pix1.getRed()!= pix2.getRed() )
	{
		return true;
	}	 	  	 	  	   	    	  	      	 	
	else if (pix1.getBlue()!=pix2.getBlue())
	{
		return true;
	}
	else if (pix1.getGreen()!=pix2.getGreen())
	{
		return true;
	}
	return false;
}

//
std::ostream& operator<< (std::ostream& out, const Pixel& pix)
{
	out << pix.getRed()<<" "<< pix.getGreen()<< " "<< pix.getBlue();
	return out;
	
}
//     Stream output operator (<<) for outputting the contents of a pixel.
//     Example: A pixel with red value 100, green value 150, and blue value 200
//              will produce the following output:100 150 200
//     Note: Returns the `out` parameter to allow chaining of stream output.
//                  

std::istream& operator>> (std::istream& in, Pixel& pix)
{
	int r;
	int g;
	int b;

	in >> r >> g >> b;
	if (r>=0 && r<=255 &&
		g>=0 && r<=255 &&
		b>=0 && b<=255 )
	{
		pix.set(r,g,b);
	}	 	  	 	  	   	    	  	      	 	
}
//     Stream input operator (>>) for reading a pixel from an input stream.
//     Precondition: `in` holds a string of three integers separated by spaces;
//        each integer must be in the range 0 to 255, inclusive.
//     Postconditions:
//        -The red value of pix is set to the first integer.
//        -The green value of pix is set to the second integer.
//        -The blue value of pix is set to the third integer.
//


}


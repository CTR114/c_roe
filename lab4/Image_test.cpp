// Image_test.cpp
//
// Unit and Other Tests for the Pixel Class
// CS 223, Winter 2017, Lab 4
//
// Name: Chris Roe
// Date: 2/7/17

#include <cassert>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "Pixel.h"
#include "Image.h"

using namespace std;
using namespace imagelab;

// test_basic_functionality() should test the following:
//    Image(w, h, r, g, b);   // (default) constructor
//    getFormat() done
//    getMaxColor() done
//    getWidth() done
//    getHeight() done
//    getPixel()done 
//    setPixel(w, h, pix) done
//    setPixel(w, h, r, g, b) done
void test_basic_functionality()
{
    //cout << "Tests for basic functionality NOT YET IMPLEMENTED!" << endl;
    Image img1(10,15,200,100,40);
    Pixel pix(23, 32, 22);
    Pixel pix1(45, 54, 44);
    assert(img1.getHeight()== 15);
    assert(img1.getWidth()==10);
    assert(img1.getMaxColor()==255);
    assert(img1.getFormat()== "P3");
    img1.setPixel(22,43, pix1);
    

    Image img2;
    assert(img2.getHeight() == 100);
    assert(img2.getWidth() == 100);
    img2.setPixel(16, 20, pix);
    assert(img2.getPixel(16, 20) == pix);
    

}	 	  	 	  	   	    	  	      	 	
void stream_input_constructor_test1()
{
    // Read in an image file to create an Image.
    // Check that image format, width, height, and maxcolor
    // are correctly set.  Also check that the first three
    // and the last three pixels of the the image are correct.

    cout << "  Test 1:" << endl;

    string imagefilestr = "/usr/local/share/images/images_noisy/n44f/n44f_001.ppm";
    cout << "    -reading image " << imagefilestr << endl;
    ifstream imagefile(imagefilestr.c_str());
    Image img(imagefile);
    imagefile.close();

    cout << "    -checking image format and dimensions" << endl;
    assert(img.getFormat() == "P3");
    assert(img.getWidth() == 600);
    assert(img.getHeight() == 339);
    assert(img.getMaxColor() == 255);
    
    cout << "    -checking first three pixels of image" << endl;
    assert(img.getPixel(0,0) == Pixel(0,0,0));
    assert(img.getPixel(1,0) == Pixel(0,10,16));
    assert(img.getPixel(2,0) == Pixel(86,8,14));

    cout << "    -checking last three pixels of image" << endl;
    assert(img.getPixel(597,338) == Pixel(255,100,0));
    assert(img.getPixel(598,338) == Pixel(17,118,0));
    assert(img.getPixel(599,338) == Pixel(255,0,0));
}

void stream_input_constructor_test2()
{
    // Read in an image file to create an Image.
    // Check that image format, width, height, and maxcolor
    // are correctly set.  Also check that the first three
    // and the last three pixels of the the image are correct.

    cout << "  Test 2:" << endl;

    string imagefilestr = "/usr/local/share/images/images_noisy/orion/orion_010.ppm";
    cout << "    -reading image " << imagefilestr << endl;
    ifstream imagefile(imagefilestr.c_str());
    Image image(imagefile);
    imagefile.close();

    cout << "    -checking image format and dimensions" << endl;
    assert(image.getFormat() == "P3");
    assert(image.getWidth() == 600);
    assert(image.getHeight() == 600);
    assert(image.getMaxColor() == 255);
    
    cout << "    -checking first three pixels of image" << endl;
    assert(image.getPixel(0,0) == Pixel(0,0,16));
    assert(image.getPixel(1,0) == Pixel(0,0,0));
    assert(image.getPixel(2,0) == Pixel(14,0,16));

    cout << "    -checking last three pixels of image" << endl;
    assert(image.getPixel(597,599) == Pixel(0,0,18));
    assert(image.getPixel(598,599) == Pixel(0,4,16));
    assert(image.getPixel(599,599) == Pixel(0,4,0));
}	 	  	 	  	   	    	  	      	 	

void stream_output_test()
{
    // Read in an image file to create an Image, then write that
    // image out to a new file. Use the linux command line to check
    // for differences in the two files.

    string imagefilestr = "/usr/local/share/images/images_noisy/n44f/n44f_001.ppm";
    cout << "    -reading image " << imagefilestr << endl;
    ifstream imagefile(imagefilestr.c_str());
    Image image(imagefile);
    imagefile.close();

    string outfilestr = "testimage.ppm";
    cout << "    -writing image to " << outfilestr << endl;
    ofstream outfile(outfilestr.c_str());
    outfile << image;
    outfile.close();

    cout << "\nTo check for differences between the original image file \n";
    cout << "and the newly created image file, please run the following \n";
    cout << "command:\n" << endl;
    cout << "    diff " << imagefilestr << " " << outfilestr << endl << endl;
    cout << "If there are no differences, your stream output operator\n";
    cout << "is correct! If there are differences, there's an error in \n";
    cout << "the implementation of your stream output. Use the 'head'\n"; 
    cout << "and 'tail' commands to inspect the two files and help you \n";
    cout << "figure out what is wrong.\n";
    cout << "\nAs a final test, you should use an image viewer to try to\n";
    cout << "view " << outfilestr << "." << endl;
    cout << "-----------------------------------------" << endl << endl;
}


void test_copy_constructor()
{	 	  	 	  	   	    	  	      	 	
    
    Pixel pix1(22, 33, 44);
    Pixel pix2(55, 66, 77);
    Image img1(120, 120, 44, 44, 44);
    img1.setPixel(50, 51, pix2);
    Image img2(img1);
    assert(img2.getHeight() == img1.getHeight());
    assert(img2.getWidth() == img1.getWidth());
    assert(img2.getFormat() == img1.getFormat());
    assert(img2.getPixel(50,51) == pix2);
    assert(img2.getPixel(32,62) == img1.getPixel(32,62));
    img2.setPixel(60, 62, pix1);
    assert(img1.getPixel(60, 62) != pix1);
    

    

}

void test_assignment_operator()
{
    
    Pixel pix1(90, 86, 23);
    Pixel pix2(23, 25, 77);
    Image img1(320, 328, 45, 76, 89);
    img1.setPixel(88, 99, pix2);
    Image img2;
    img2 = img1;
    assert(img2.getHeight() == img1.getHeight());
    assert(img2.getWidth() == img1.getWidth());
    assert(img2.getFormat() == img1.getFormat());
    assert(img2.getMaxColor() == img1.getMaxColor());
    
}


int main()
{	 	  	 	  	   	    	  	      	 	
   //cout << "\nTesting the Image class!" << endl;

   //cout << "\nTesting basic image creation and functionality . . . " << endl;
   test_basic_functionality();
   cout << "DONE!" << endl;

   //cout << "\nTesting creation of an image from stream input . . . " << endl;
   stream_input_constructor_test1();
   stream_input_constructor_test2();
   //cout << "DONE!" << endl;

   //cout << "\n-----------------------------------------" << endl;
   //cout << "Testing stream output for an image . . . " << endl << endl;
   stream_output_test();

   //cout << "\nTesting copy constructor and assignment operator . . . " << endl;
   test_copy_constructor();
   test_assignment_operator();
   cout << "DONE!" << endl;
}

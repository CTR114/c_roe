

// Name: Chris Roe
// Date: 2/7/17

// image_stacker.cpp
/*
  Specificications for the image stacker program:
     - Ask the user for the directory containing the images to stack
     - Ask the user for what to call the final good image file
     - Average all all noisy images in the given directory to create
       a final good image
     - write the final good image in PPM format to the filename given
       by the user.
*/

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <dirent.h>
#include "Pixel.h"
#include "Image.h"

using namespace std;
using namespace imagelab;

/*!
*   @function      readDir
*   @description   puts filenames from a directory into an output stream
*
*   @param out     output stream (may be a stringstream)
*   @param dir     string containing the path to the directory to read
*   @param n       int number of filenames to return
*   @returns       output stream with the filenames, separated by spaces
*
*   @precondition  dir is a valid directory
*   @precondition  n <= the number of files in dir
*/ // wow

int Num_Files=10;
ostream& readDir(ostream& out, string dir, int n)
{
    string fname, filepath;
    DIR *dp;
    struct dirent *dirp;

    cout << "dir to get files of: " << dir << endl;
    dp =opendir( dir.c_str() );
    if (dp==NULL)
    {
    cout << "ERROR_OPENING:" << dir << endl;
    return out;
    }

    int i=0;
    while ((dirp=readdir(dp))&& i<n)
    {
       fname = dirp->d_name;

       if ((fname.length() >= 3) &&
          (fname.substr(fname.length()-3, 3) == "ppm"))
       {
           filepath = dir + "/" + fname;
           out << filepath << " ";
           i++;
       }
    }
    closedir( dp );
    return out;
}


//get to directory and then set name for last image to be seen.
int main()
{
    stringstream files;
    string dir;
    string file[Num_Files];
    string file_name_str;
    Image images[Num_Files];
    cout <<"Enter the directory of the images you want to use: ";
    cin >>dir;
    readDir(files,"/usr/local/share/images/images_noisy/" + dir,Num_Files);
    for (int i= 0; i<Num_Files;i++)
    {
        getline(files, file[i]);  // PROBLEM #1
    }
    cout << "Enter a name for the product image: ";
    cin >> file_name_str;

    for (int i= 0; i < Num_Files; i++)
    {
        // Constructs an ifstream object, initially associated with the file
        // identified by its first argument (filename), open with default mode
        // 'in'
        // cout << "\n\nOpening file " << file[i] << "and associateing it with infile ifstream" << endl;
        ifstream infile(file[i].c_str());
        Image image(infile);
        images[i] =image;
        infile.close();
    }

    Image newImg(images[0]);

    Pixel pixArr[Num_Files];

// overlapping all colors
    for (int i = 0; i < images[0].getHeight(); i++)
    {

        int rval;
        int gval;
        int bval;
        for (int j=0;j< images[0].getWidth();j++)
        {
            rval=0;
            gval=0;
            bval=0;
            for (int x = 0; x < Num_Files; x++)
            {
                pixArr[x]=(images[x].getPixel(i,j));
                gval=gval+pixArr[x].getGreen();
                bval=bval+pixArr[x].getBlue();
                rval=rval+pixArr[x].getRed();
            }
            Pixel pix(rval/Num_Files, gval/Num_Files, bval/Num_Files);
            newImg.setPixel(i,j,pix);
        }
    }
    ofstream outfile(file_name_str.c_str());
    outfile<<newImg;
    outfile.close();
}


// writeResult ????
// take the finished image and write it to a file
// precondition: `ofilename` is a valid filename
// postcondition: `image` has been written to the specified file in .ppm format
void writeResult(Image image, string ofilename)
{
   ofstream myfile;
   myfile.open(ofilename.c_str());
   myfile<<image;
   myfile.close();
}

 // ???
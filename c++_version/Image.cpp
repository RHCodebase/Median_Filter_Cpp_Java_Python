#include "Image.h"

// Constructor
Image::Image(string fileN)
{
	fileName = fileN;
}

// get information on image from file
void Image::getImageData()
{
	ifstream inStream;
	inStream.open(fileName.c_str());

	if(inStream.fail())
	{
		cout << "Input file opening failed. \n";
		exit(1);
	}

	if(inStream.good())
  	{ 
		// line number        data
    	//     1              P3
        //     2              495 557
        //     3              255
        //     4              240 244 253
        //     .              ...........
        //     .              ...........
		//    275716          174 165 132
        //    275717          168 159 126
        //    275718          164 155 122
		//    275719          no pixel values ie blank

    	getline(inStream, format);    // format = P3

    	if(format.compare("P3") != 0)
		{
    		cout << "The image is not correct format.\n";
    		exit(1);
    	}
    	inStream >> width;              // width     =  495 
    	inStream >> height;             // height    =  557 
    	inStream >> maxColour;          // maxColour =  255 
    	int temp;

        // pixel = R G B
	
        size = (width * height) * 3;    // size = (495 * 557) * 3;  
		                                // size = (495 * 557) * 3;
										// size = (275715)    * 3;
										// size =  827145


    	while( inStream >> temp )
		{
    		ascii.push_back(temp);
  		}
  	} 
	inStream.close();
}


// returns the value at the position in the image
int Image::getAsciiValueAtIndex(int position)
{
	return ascii[position];
}

// returns the size of the image
int Image::getSizeOfImage()
{
	return size;
}

// returns the maxColour
int Image::getMaxColour()
{
    return maxColour;
}

// returns the width
int Image::getWidth()
{
    return width;
}

// returns the height
int Image::getHeight()
{
    return height;
}


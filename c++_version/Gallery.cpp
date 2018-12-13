#include "Gallery.h"

// Constructor
Gallery::Gallery()
{

}

void Gallery::addImage(Image pic)
{
	pictures.push_back(pic);
}


// creates pixels for new image uses median filter
// returns the filtered image

vector<int> Gallery::createMedianImage()
{
	vector<int> filteredImage;

	filteredImage.push_back(pictures[0].getWidth());
	filteredImage.push_back(pictures[0].getHeight());
	filteredImage.push_back(pictures[0].getMaxColour());
	
	for(long i=0; i < pictures[0].getSizeOfImage(); i++)
	{
		vector<int> tempArray;

		for(int j=0; j < pictures.size(); j++)
		{
			tempArray.push_back(pictures[j].getAsciiValueAtIndex(i));
		}
//================================================================================================================
        // cout << " before the sort " << endl;
        // for(int i=0; i<tempArray.size(); i++)
		// {
		//	   cout << " tempArray[" << i << "] is " << tempArray[i] << endl;
		// }
//=================================================================================================================
	    sort (tempArray.begin(), tempArray.begin()+tempArray.size());
//================================================================================================================
        // cout << " after the sort " << endl;
        // for(int i=0; i<tempArray.size(); i++)
		// {
		//     cout << " tempArray[" << i << "] is " << tempArray[i] << endl;
		// }
//=================================================================================================================
        int medianValue = 0;

	    if ( tempArray.size()/2 == 0 )
	    {
			 int first_middle_index  =  ( tempArray.size() / 2 );
 		     int first_middle_value  =  tempArray[first_middle_index];
 
 		     int second_middle_index =  first_middle_index + 1;
 		     int second_middle_value =  tempArray[second_middle_index];   
         
             medianValue = (first_middle_value + second_middle_value) / 2;
	    }
	    else
	    {
             int midindex = (tempArray.size() + 1)/2;
             medianValue  = tempArray[midindex];
	    }	 
//=================================================================================================================
		// put medianValue into vector for new image
		// cout << "medianValue is " << medianValue << endl;

		filteredImage.push_back(medianValue);
	}
	return filteredImage;
}

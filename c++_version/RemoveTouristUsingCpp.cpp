#include "Image.h"
#include "Gallery.h"

int main(int argc, char *argv[])
{
	     const string FORMAT = "P3";

         cout << endl;
	     
		 for (int i = 0; i < argc - 1; i++)
	     {		     
			  string argv_as_string = argv[i];

			  if (argv_as_string.compare(0,8,"filtered") == 0 )
			  {
		 		  cout << "It is better to delete all the previous versions of the filtered ppm files" << endl;
				  cout << "before running this program" << endl;
				  cout << endl;
				  exit(1);
			  }	 
	      }

	      int numOfImageFiles = argc - 1;

		  cout << "\nnumOfImageFiles is " << numOfImageFiles << endl;
	
	      if( numOfImageFiles < 3 )
	      {
		      cout << "\nYou need more images files" << endl;
		      exit(1);
	      }
         
		  Gallery images;
	
		  for (int i = 1; i <= numOfImageFiles; i++)
		  {
			   string imageName = argv[i];
			   cout << "current image is " << imageName << "\n";

			   Image pic(imageName);
			   pic.getImageData();

			   images.addImage(pic);
		  }
		
		  vector<int> imageCreate = images.createMedianImage();
		
		  ofstream myfile;
		  myfile.open ("filteredImageUsingC++.ppm");
		  myfile << FORMAT << endl;
	  	  myfile << imageCreate[0] << " " << imageCreate[1] << endl;
		  myfile << imageCreate[2] << endl;
		
		  for(int i=3; i<imageCreate.size(); i++)
		  {
			    //format file nicely
			    if( i%3 ==0 && i != 3)
			    {
				    myfile << endl;
			    }

			    myfile << imageCreate[i] << " ";
		  }
		  myfile.close();

		  return (0);
}

/*

On Windows
-----------
To compile type in the following:
g++ -o RemoveTouristUsingCpp.o RemoveTouristUsingCpp.cpp Image.cpp Gallery.cpp

To Run type in the following:
RemoveTouristUsingCpp.o *.ppm

this will create an image file called filteredImageUsingC++.ppm 

which can be view using IrfanView 

http://www.irfanview.com/
http://www.irfanview.net/faq.htm


> g++ -o RemoveTouristUsingCpp.o RemoveTouristUsingCpp.cpp Image.cpp Gallery.cpp

> RemoveTouristUsingCpp.o *.ppm

numOfImageFiles is 9
current image is G0010099.ppm
current image is G0010108.ppm
current image is G0010109.ppm
current image is G0010110.ppm
current image is G0010111.ppm
current image is G0010132.ppm
current image is G0010159.ppm
current image is G0010161.ppm
current image is G0010163.ppm

>RemoveTouristUsingCpp.o *.ppm

It is better to delete all the previous versions of the filtered ppm files
before running this program


*/


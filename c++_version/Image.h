#ifndef image
#define image

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Image
{
private:
	string format;
    int width;
    int height;
	int maxColour;
    int size;
	string fileName;
	vector<int> ascii;

public:
	Image(string fileN);
    int  getAsciiValueAtIndex(int position);
	void getImageData();
	int  getSizeOfImage();
	int  getMaxColour();
	int  getWidth();
	int  getHeight();
};

#endif

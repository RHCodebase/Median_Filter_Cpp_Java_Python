#ifndef gallery
#define gallery

#include "Image.h"

class Gallery
{
      private:
	       vector<Image> pictures;

      public:
	       Gallery();
  	       void addImage(Image pic);
	       vector<int> createMedianImage();
};

#endif

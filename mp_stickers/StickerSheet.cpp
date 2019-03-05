#include <cmath>
#include <iostream>
#include"cs225/PNG.h"
#include"cs225/HSLAPixel.h"
#include"StickerSheet.h"

using namespace std;
using namespace cs225;

/*
Initializes this StickerSheet with a base picture and the
ability to hold a max number of stickers (Images) with indices 0 through max-1.
*/
StickerSheet::StickerSheet(const Image& picture, unsigned max){

	// picture: the base picture to use in the StickerSheet
	// max: the maximum number of stickers (Images) on this StickerSheet

	this->baseImage = picture;

	//baseImage.scale(2);
	this->maxSticker = max;
	this->numSticker = 0;

	this->stickerArray = new Image *[max];   // 0 - max-1
	this->x_coord = new unsigned [max];
	this->y_coord = new unsigned [max];

}



/*
Frees all space that was dynamically allocated by this StickerSheet.
*/
StickerSheet::~StickerSheet(){

	delete [] x_coord;
	delete [] y_coord;
	delete [] stickerArray;

}


void StickerSheet::_copy(const StickerSheet &other){

	delete[] x_coord;
	delete[] y_coord;
	delete[] stickerArray;

	this->baseImage = other.baseImage;
	this->maxSticker = other.maxSticker;
	this->numSticker = other.numSticker;

	this->stickerArray = new Image *[other.maxSticker];
	this->x_coord = new unsigned [other.maxSticker];
	this->y_coord = new unsigned [other.maxSticker];

	for(unsigned i = 0; i < this->numSticker; i++){
		stickerArray[i] = other.stickerArray[i];
		x_coord[i] = other.x_coord[i];
		y_coord[i] = other.y_coord[i];
	}

}


/*
The copy constructor makes this StickerSheet an independent copy of the source.
Hint: Code is likely shared between all of the "Rule of Three" functions.
*/
StickerSheet::StickerSheet(const StickerSheet &other){

	this->baseImage = other.baseImage;
	this->maxSticker = other.maxSticker;
	this->numSticker = other.numSticker;

	this->stickerArray = new Image *[maxSticker];
	this->x_coord = new unsigned [maxSticker];
	this->y_coord = new unsigned [maxSticker];

	for(unsigned i = 0; i < this->maxSticker; i++){
		stickerArray[i] = other.stickerArray[i];
		x_coord[i] = other.x_coord[i];
		y_coord[i] = other.y_coord[i];
	}

}



/*
The assignment operator for the StickerSheet class.

Hint: Code is likely shared between all of the "Rule
of Three" functions. Would a helper function (or two) make your life easier?
*/
const StickerSheet& StickerSheet::operator=	(const StickerSheet &other){

	// other: the other Scene object to copy data from
	// a constant Scene reference

	if( this == &other){
		return *this;
	}

	_copy(other);

	return *this;

}



/*
Modifies the maximum number of stickers that can be stored on
this StickerSheet without changing existing stickers' indices.

If the new maximum number of stickers is smaller than the
current number number of stickers, the stickers with indices above max - 1
will be lost.
*/
void StickerSheet::changeMaxStickers(unsigned max){

	// max: the new value for the maximum number of Images in the StickerSheet.
	Image **tempStickerArray = new Image *[this->maxSticker];
	unsigned *temp_x_coord = new unsigned [this->maxSticker];
	unsigned *temp_y_coord = new unsigned [this->maxSticker];

	unsigned int tempMaxSticker = this->maxSticker;
	unsigned int tempNumSticker = this->numSticker;

	for(unsigned i = 0; i < tempNumSticker; i++){

		tempStickerArray[i] = stickerArray[i];
		temp_x_coord[i] = x_coord[i];
		temp_y_coord[i] = y_coord[i];

	}

	delete [] x_coord;
	delete [] y_coord;
	delete [] stickerArray;

	if (tempMaxSticker < max){

		this->stickerArray = new Image *[max];
		this->x_coord = new unsigned [max];
		this->y_coord = new unsigned [max];

		for (unsigned int i = 0; i < tempNumSticker; i++){

			this->stickerArray[i] = tempStickerArray[i];
			this->x_coord[i] = temp_x_coord[i];
			this->y_coord[i] = temp_y_coord[i];

		}

		this->maxSticker = max;

	} else {

		this->stickerArray = new Image *[max];
		this->x_coord = new unsigned [max];
		this->y_coord = new unsigned [max];

		for (unsigned int i = 0; i < max; i++){
			this->stickerArray[i] = tempStickerArray[i];
			this->x_coord[i] = temp_x_coord[i];
			this->y_coord[i] = temp_y_coord[i];
		}

		this->maxSticker = max;
	}

	if(max < this->numSticker){

		numSticker = max;

	}

	delete [] tempStickerArray;
	delete [] temp_x_coord;
	delete [] temp_y_coord;

}




/*
Adds a sticker to the StickerSheet, so that the top-left
of the sticker's Image is at (x, y) on the StickerSheet.

The sticker must be added to the lowest possible layer available.
*/
int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){

	// sticker: the Image of the sticker.
	// x: the x location of the sticker on the StickerSheet
	// y: the y location of the sticker on the StickerSheet

	// return: The zero-based layer index the sticker was added
	// to, or -1 if the sticker cannot be added.

	if(this->numSticker < this->maxSticker){

		stickerArray[this->numSticker] = &sticker;
		x_coord[this->numSticker] = x;
		y_coord[this->numSticker] = y;

		numSticker += 1;

		return numSticker+1;

	} else {

		return -1;
	}




}



/*
Changes the x and y coordinates of the Image in the specified layer.

If the layer is invalid or does not contain a sticker, this function
must return false. Otherwise, this function returns true.
*/
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){


	// index: zero-based layer index of the sticker.
	// x: the new x location of the sticker on the StickerSheet
	// y: the new y location of the sticker on the StickerSheet
	// return: true if the translate was successful; otherwise false.

	if(index < this->numSticker){

		this->x_coord[index] = x;
		this->y_coord[index] = y;

		return true;

	} else {

		return false;

	}

}


/*
Removes the sticker at the given zero-based layer index.
*/
void StickerSheet::removeSticker(unsigned index){

	// index: the layer in which to delete the png
	// need to updata numSticker, x_coord, y_coord

	if(index < this->numSticker){

		unsigned int tempMaxSticker = this->maxSticker;
		unsigned int tempNumSticker = this->numSticker;

		Image **tempStickerArray = new Image *[tempMaxSticker];
		unsigned *temp_x_coord = new unsigned [tempMaxSticker];
		unsigned *temp_y_coord = new unsigned [tempMaxSticker];

		for(unsigned i = 0; i < tempNumSticker; i++){

			tempStickerArray[i] = stickerArray[i];
			temp_x_coord[i] = x_coord[i];
			temp_y_coord[i] = y_coord[i];

		}

		delete [] stickerArray;
		delete [] x_coord;
		delete [] y_coord;

		this->stickerArray = new Image *[tempMaxSticker];
		this->x_coord = new unsigned [tempMaxSticker];
		this->y_coord = new unsigned [tempMaxSticker];

		for(unsigned i = 0; i < index; i++){

			stickerArray[i] = tempStickerArray[i];
			x_coord[i] = temp_x_coord[i];
			y_coord[i] = temp_y_coord[i];

		}

		for(unsigned i = index; i < this->numSticker; i++){

			stickerArray[i] = tempStickerArray[i+1];
			x_coord[i] = temp_x_coord[i+1];
			y_coord[i] = temp_y_coord[i+1];

		}

		this->numSticker -= 1;

		delete [] tempStickerArray;
		delete [] temp_x_coord;
		delete [] temp_y_coord;

	}

}



/*
Returns a pointer to the sticker at the specified index, not a copy of it.

That way, the user can modify the Image. If the index is invalid, return NULL.
*/
Image* StickerSheet::getSticker(unsigned index) const {

	// index: the layer in which to get the sticker.
	// return: A pointer to a specific Image in the StickerSheet

	if(index < this->numSticker){

		return stickerArray[index];

	} else {

		return NULL;

	}

}




/*
Renders the whole StickerSheet on one Image and returns that Image.

The base picture is drawn first and then each sticker is drawn in order
starting with layer zero (0), then layer one (1), and so on.

If a pixel's alpha channel in a sticker is zero (0), no pixel is drawn
for that sticker at that pixel. If the alpha channel is non-zero, a pixel
is drawn. (Alpha blending is awesome, but not required.)

The returned Image always includes the full contents of the picture and
all stickers. This means that the size of the result image may be larger
than the base picture if some stickers go beyond the edge of the picture.

*/
Image StickerSheet::render() const {

	// return: an Image object representing the drawn scene

	unsigned maxWidth = 0;
	unsigned maxHeight = 0;
	unsigned tempWidth = 0;
	unsigned tempHeight = 0;

	// get the max width and max height
	for(unsigned i = 0; i < this->numSticker; i++){

		 tempWidth = stickerArray[i]->width();
		 tempHeight = stickerArray[i]->height();

		 if(tempWidth >= maxWidth){

		 	maxWidth = tempWidth;
		 }

		 if(tempHeight >= maxHeight){

		 	maxHeight = tempHeight;

		 }

	}

	// create an image
	Image stickerImage = this->baseImage;
	//stickerImage.scale(maxWidth, maxHeight);

	// loop all the stickers
	for(unsigned k = 0; k < numSticker; k++){

		// get sticker's width and height
		unsigned tmpStickerWidth = stickerArray[k]->width();
		unsigned tmpStickerHeight = stickerArray[k]->height();
		unsigned stickerX = x_coord[k];
		unsigned stickerY = y_coord[k];
		//unsigned countWidth = 0;
		//unsigned countHeight = 0;

		// base image's width++
		for(unsigned x = stickerX; x < tmpStickerWidth + stickerX; x++){

			// base image's height++
			for(unsigned y = stickerY; y < tmpStickerHeight + stickerY; y++){

				if( (x < stickerImage.width()) && (y < stickerImage.height()) ) {

					// base image pixel
					HSLAPixel &basePixel = stickerImage.getPixel(x, y);

					// get witdth and height of sticker
					HSLAPixel &stickerPixel = stickerArray[k]->getPixel(x-stickerX, y-stickerY);

					if(stickerPixel.a != 0){

						// need to check alpha
						basePixel = stickerPixel;

					}

				}


			}


		}


	}

	return stickerImage;

}

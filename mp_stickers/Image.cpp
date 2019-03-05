#include "Image.h"
#include <cmath>
#include <iostream>

// using namespace std；

/**
* Lighten an Image by increasing the luminance of every pixel by 0.1.
* This function ensures that the luminance remains in the range [0, 1].
*/
void Image::lighten(){

	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       	HSLAPixel &pixel = this->getPixel(x, y);

       	if((pixel.l + 0.1) <= 1){

       		pixel.l = pixel.l + 0.1;

       	} else{

       		pixel.l = 1.0;

       	}

       }
    }

}

/**
* Lighten an Image by increasing the luminance of every pixel by amount.
* This function ensures that the luminance remains in the range [0, 1].
*/
void Image::lighten(double amount){

	// amount is the desired increase in luminance.

	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       	HSLAPixel &pixel = this->getPixel(x, y);

       	if((pixel.l + amount) <= 1){

       		pixel.l = pixel.l + amount;

       	} else{

       		pixel.l = 1.0;

       	}
       }
    }



}

/**
* Darken an Image by decreasing the luminance of every pixel by 0.1.
* This function ensures that the luminance remains in the range [0, 1].
*/
void Image::darken(){

	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       	HSLAPixel &pixel = this->getPixel(x, y);

       	if((pixel.l - 0.1) >= 0){

       		pixel.l = pixel.l - 0.1;

       	} else{

       		pixel.l = 0.0;

       	}

       }
    }



}	

/**
* Darken an Image by decreasing the luminance of every pixel by amount.
* This function ensures that the luminance remains in the range [0, 1].
*/
void Image::darken(double amount){

	// amount is the desired decrease in luminance.

	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       	HSLAPixel &pixel = this->getPixel(x, y);

       	if((pixel.l - amount) >= 0){

       		pixel.l = pixel.l - amount;

       	} else{

       		pixel.l = 0.0;

       	}

       }
    }


}	

/**
* Saturates an Image by increasing the saturation of every pixel by 0.1.
* This function ensures that the saturation remains in the range [0, 1].
*/
void Image::saturate(){

	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       	HSLAPixel &pixel = this->getPixel(x, y);

       	if((pixel.s + 0.1) <= 1){

       		pixel.s = pixel.s + 0.1;

       	} else{

       		pixel.s = 1.0;

       	}

       }
    }

}


/**
* Saturates an Image by increasing the saturation of every pixel by amount.
* This function ensures that the saturation remains in the range [0, 1].
*/
void Image::saturate(double amount){

	// amount is desired increase in saturation.
	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       	HSLAPixel &pixel = this->getPixel(x, y);

       	if((pixel.s + amount) <= 1){

       		pixel.s = pixel.s + amount;

       	} else{

       		pixel.s = 1.0;

       	}

       }
    }


}


/**
* Desaturates an Image by decreasing the saturation of every pixel by 0.1.
* This function ensures that the saturation remains in the range [0, 1].
*/
void Image::desaturate(){

	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       	HSLAPixel &pixel = this->getPixel(x, y);

       	if((pixel.s - 0.1) >= 0){

       		pixel.s = pixel.s - 0.1;

       	} else{

       		pixel.s = 0.0;

       	}

       }
    }

}


/**
* Desaturates an Image by decreasing the saturation of every pixel by amount.
* This function ensures that the saturation remains in the range [0, 1].
*/
void Image::desaturate(double amount){

	// amount is the desired decrease in saturation.
	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       	HSLAPixel &pixel = this->getPixel(x, y);

       	if((pixel.s - amount) >= 0){

       		pixel.s = pixel.s - amount;

       	} else{

       		pixel.s = 0.0;

       	}

       }
    }

	
}


/**
* Turns the image grayscale.
*/
void Image::grayscale(){

	for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {

      HSLAPixel &pixel = this->getPixel(x, y);

      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0.0;
    }
  }

}



/**
* Rotates the color wheel by degrees.
* This function ensures that the hue remains in the range [0, 360].
*/
void Image::rotateColor(double degrees){

	// degrees are the desired amount of rotation.
	// amount is desired increase in saturation.
	for (unsigned x = 0; x < this->width(); x++) {
       for (unsigned y = 0; y < this->height(); y++) {

       		HSLAPixel &pixel = this->getPixel(x, y);

       		if( ((pixel.h + degrees) <= 360) && ((pixel.h + degrees) >= 0) ){

       			pixel.h = pixel.h + degrees;

       		} else if ( (pixel.h + degrees) > 360) {

       			pixel.h = fmod((pixel.h + degrees), 360);

       		} else {

       			double tmpHue = pixel.h + degrees;

       			if((-tmpHue) <= 360){

       				pixel.h = 360 + tmpHue;

       			} else {

       				pixel.h = 360 - fmod((-tmpHue), 360);
       			}
       		}
       }
    }


}

/**
* Illinify the image.
*/
void Image::illinify(){

	int illOrange = 0;
    int illBlue = 0;

    for (unsigned x = 0; x < this->width(); x++) {
    	for (unsigned y = 0; y < this->height(); y++) {

        	HSLAPixel &pixel = this->getPixel(x, y);

			if(pixel.h >=0 && pixel.h <= 11){
	    
	    		pixel.h = 11;

			} else if (pixel.h > 11 && pixel.h < 216){

	    		illOrange = std::abs(pixel.h - 11); 
        	    illBlue = std::abs(pixel.h - 216);

	    		if(illOrange > illBlue){
	     	   		pixel.h = 216;
	    		}else{
	        		pixel.h = 11;
	    		}

			} else {

            	illOrange = std::abs(371 - pixel.h); 
            	illBlue = std::abs(pixel.h - 216);

	    		if(illOrange > illBlue){            
	        		pixel.h = 216;
	    		}else{
	        		pixel.h = 11;
	    		}
			}
    	}
    }

}	
  
/**
* Scale the Image by a given factor.
* 
* For example:
*	A factor of 1.0 does not change the image.
*	A factor of 0.5 results in an image with half the width and half the height.
*	A factor of 2 results in an image with twice the width and twice the height.
*
* This function both resizes the Image and scales the contents.
*/
void Image::scale(double factor){

	double newWidth = this->width() * factor;
	double newHeight = this->height() * factor;

	PNG original = *this;

	this->resize((unsigned)newWidth, (unsigned)newHeight);

	unsigned srcX = 0;
	unsigned srcY = 0;

	for (unsigned int x = 0; x < newWidth; x++) {
		for (unsigned int y = 0; y < newHeight; y++) {

			srcX = floor(x/factor);
			srcY = floor(y/factor);

			HSLAPixel &targetPixel = this->getPixel(x, y);
			HSLAPixel &sourcePixel = original.getPixel((unsigned)srcX, (unsigned)srcY);
			targetPixel = sourcePixel;
		}
    
	}

}	


/**
* Scales the image to fit within the size (w x h).
* 
* This function preserves the aspect ratio of the image, so the result 
* will always be an image of width w or of height h (not necessarily both).
*
* This function both resizes the Image and scales the contents.
*/
void Image::scale(unsigned w, unsigned h){

	// w is the desired width of the scaled Iamge
	// h is the desired height of the scaled Image

	unsigned int sourceWidth = this->width();
	unsigned int sourceHeight = this->height();

	// PNG original = *this;

	// this->resize(w, h);

    double w_ratio = w*1.0 / (double)sourceWidth;
	double h_ratio = h*1.0 / (double)sourceHeight;

	if(w_ratio < h_ratio){
		scale(w_ratio);
	}else{
		scale(h_ratio);
	}

    // deal with scaled image
    // unsigned srcX = 0;
	// unsigned srcY = 0;

    // for (unsigned int x = 0; x < w; x++) {
    // 	for (unsigned int y = 0; y < h; y++) {

	// 		srcX = floor(x/w_ratio);
	// 		srcY = floor(y/h_ratio);

	// 		HSLAPixel &targetPixel = this->getPixel(x, y);
	// 		HSLAPixel &sourcePixel = original.getPixel((unsigned)srcX, (unsigned)srcY);
	// 		targetPixel = sourcePixel;

    // 	}
    // }

}	


// void Image::_copy(Image const & other){ }

//Image::~Image(){
//}

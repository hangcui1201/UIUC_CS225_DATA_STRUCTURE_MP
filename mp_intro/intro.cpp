#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>


void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2

  // Load input image
  cs225::PNG inputImage;

  inputImage.readFromFile(inputFile);

  unsigned width = inputImage.width();
  unsigned height = inputImage.height();

  // Create output image based on the size of the input image
  cs225::PNG outputImage(width, height);

  for(unsigned y = 0; y< height; y++){    // rows of the image
    for(unsigned x = 0; x < width; x++){  // colums of the image
      // Scan the image row by row
      cs225::HSLAPixel & pixel = inputImage.getPixel(x,y);
      cs225::HSLAPixel & rotatePixel = outputImage.getPixel(width-x-1, height-y-1);
      rotatePixel = pixel;
    }
  }

  outputImage.writeToFile(outputFile);

}

// Helper funtion round floating number to one decimal place
float round(float num) 
{ 
	int save_decimal = 10;
    return (float)((int)(num * save_decimal + 0.5))/save_decimal;  
} 

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);

  // TODO: Part 3
  // H: 0-360
  // S: 0-100
  // L: 0-100

  float high = 0.0;
  float low = 0.0;
  float range = 0.0;

  float hue = 0.0;
  float sat = 0.0;
  float lum = 0.0;

  float r = 0.0;
  float g = 0.0;
  float b = 0.0;

  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) {

		cs225::HSLAPixel & pixel = png.getPixel(x, y);

		r = round((x % width)/(float)width);
		g = round((y % height)/(float)height);
		// float b = round((x % width)/(float)width);
		b = 0.5;

		/***************** Convert RGB to HSL *****************/

		high = std::max(std::max(r, g), b);
		low = std::min(std::min(r, g), b);
		range = high - low;

		lum = (high + low) / 2;

		if(range == 0){

			hue = 0;
			sat = 0;

		}else{

	      	sat = (lum  > 0.5) ? (range / (2 - high - low)) : (range / (high + low));

			if (r == high){
				hue = (g - b) / range + (g < b? 6: 0);
			}
			else if (g == high){
				hue = (b - r) / range + 2;
			}
			else{
				hue = (r - g) / range + 4;
			}

			hue /=6.0;
		}

		/***************** Convert RGB to HSL *****************/

		pixel.h = round(hue*360);
		pixel.s = round(sat*100);
		pixel.l = round(lum*100);

    }

  }

  return png;
}

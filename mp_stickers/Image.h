/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once

#include "cs225/PNG.h"
using namespace cs225;

class Image : public PNG
{
	public:
		/*
		Image();
		Image(unsigned int width, unsigned int height);
		Image(Image const & other);
		~Image();

		Image const & operator= (Image const & other);
		bool operator== (Image const & other) const;
		bool operator!= (Image const & other) const;
		bool readFromFile(string const & fileName);
		bool writeToFile(string const & fileName);
		HSLAPixel * getPixel(unsigned int x, unsigned int y);
		unsigned int width() const;
		unsigned int height() const;
		void resize(unsigned int newWidth, unsigned int newHeight);
		*/

		// ~Image();
		void lighten();
		void lighten (double amount);
		void darken();
		void darken(double amount);
		void saturate();
		void saturate(double amount);
		void desaturate();
		void desaturate(double amount);
		void grayscale();
		void rotateColor(double degree);
		void illinify();
		void scale(double factor);
		void scale(unsigned w, unsigned h);


	private:

		/*
		unsigned int width_;            // Width of the image 
    	unsigned int height_;           // Height of the image
    	HSLAPixel *imageData_;          // Array of pixels
		*/
    	// void _copy(Image const & other);  /* Copeies the contents of `other` to self */

};

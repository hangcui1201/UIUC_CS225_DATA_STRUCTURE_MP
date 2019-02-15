#### Part 1: Create a Makefile

In CS 225, we feel it’s important you understand how a C++ program compiles.

Go through the Makefile Tutorial and create a Makefile for this assignment. You may find the lab_intro Makefile useful as a reference.

Your Makefile must compile together your own solution files, namely main.cpp, intro.h, intro.cpp, and files in the cs225 directory. Do not have typos in your file names or your Makefile! For example, make sure your Makefile compiles a file named main.cpp, not a file named main.C or test.cpp or any other such thing.

Please make sure your Makefile does not compile extra files that are not part of this MP. For example, do not add in files from the Makefile tutorial by mistake; the only files the Makefile should be dealing with are the few listed in the paragraph above.

Your Makefile must produce an executable called intro (all lowercase).

#### Part 2: Rotate an Image
Open intro.cpp and complete the rotate function. This function must:

Read in inputFile,
Rotate the image 180 degrees,
Write the rotated image out as outputFile
Here’s alma.png rotated 180 degrees:

In order to complete this, you will need to make use of CS 225’s PNG class, which you learned about in lab_intro.

#### Testing Part 2

$ make  
$ cp in_01.png in.png  
$ ./intro  
$ diff out.png out_01.png


#### Part 3: Getting Creative

Daniel O’Brien, fellow Illini and CS 225 alumni, created a website that now attracts over 40,000 followers that displays randomly generated fusions of color that are both mesmerizing and beautiful. Here are just a few:

Generate Your Own Colored Background
Open up intro.cpp and complete the myArt function. The myArt function must:

Return a width x height PNG image that contains original art you have created.

(1) The width and height of your image will always be the same – every image generated must be a square.

(2) By default, the width and height are both 800. Your TA will see your art rendered at 800 x 800.

(3) You should focus on making sure your art looks the way you like at 800 x 800. However, your art must scale to any size (eg: be generic).

Your art must be unique and something you find beautiful or meaningful. There are very few requirements:

(1)Your art must contain at least three unique colors.

(2) Your art must not contain any external resources (eg: no loading an image from disk/web)

That’s it – everything else is up to you! You are highly encouraged to use gradients, fractals, or other designs in your art. More than anything else, have fun! As an extra bit, course staff will award +1 point to designs that are particularly unique, creative, beautiful, or stand out from other designs. Feel free to share it both on Piazza and across social media with #cs225!

Finally, you will make use of and see your artwork later in the semester. Make it something you’ll be happy to see. :)

#### Testing Part 3

The main.cpp provided for you will produce your artwork instead of an image if you run ./intro with a command line parameter. If you provide a number after ./intro, it will save your artwork as art.png. For example:

$ ./intro 800

#### Autograder Testing

$ make test  
$ ./test

#### Grading and Submission

Makefile  
cs225/HSLAPixel.cpp  
cs225/HSLAPixel.h  
intro.cpp  

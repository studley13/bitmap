/*
 * Canvas.h
 *
 * Author:  Curtis Millar
 * Date:    28 Oct 2012
 *
 * Canvas class that allows for creation and editing of a
 * bit-mapped matrix of an image.
 *
 * Copyright (c) Curtis Millar 2012. All Rights Reserved.
 */

#ifndef CLASS_CANVAS
#define CLASS_CANVAS

#include "bitmap.h"

/*
 * Constants for use in bitmap class
 */

//Image anchors for resizing
#define TOP (1<<0)
#define BOTTOM (1<<1)
#define LEFT (1<<2)
#define RIGHT (1<<3)
#define CENTRE (TOP|BOTTOM|LEFT|RIGHT) //denter of the image

namespace bitmap {
/*
 * Types
 */

typedef int flag; //A variable for holding a flag

/*
 * Class Definition
 */

class Canvas {
    private:
        int height;
        int width;
        int alpha;
        Color** matrix;

        void populateMatrix(); //Allocate the matrix and its cells
        void depopulateMatrix(); //Deallocate the matrix and its cells
        Color* getCell(int x, int y); //get a cell in the matrix

    public:
        Canvas (); //default constructor
        Canvas (int width, int height); //constructor
        ~Canvas (); //destructor

        //getters
        int getWidth() { return this->width; }
        int getHeight() { return this->height; }

        //methods
        Canvas& resize(int width, int height, flag anchor=CENTRE); //resize the image
        Color getAt(int x, int y); //get color at (x, y)
        Canvas& setAt(int x, int y, Color color); //set pixel at (x, y) to color

        /*
        Bitmap& scale(int width, int height); //scale the image to a size
        Bitmap& scale(float ratio); //scale the image in relation to original size
        */
};
}
#endif

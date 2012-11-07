#include "BMP.h"
#include <cstdlib>
#include "../cmtools.h"

/*
 * Constructors
 */

//construct the bitmap
bitmap::format::BMP::BMP() {
    //set defaults
    this->width = 0;
    this->width = 0;
    this->fileSize = this->matrixStart;
    this->res_1 = 0;
    this->res_2 = 0;
    this->bitsPixel = 24;
    this->compression = bitmap::format::BI_RGB;
    this->matrixSize = 0;
    this->hRes = 0;
    this->vRes = 0;
    this->paletteSize = 0;
    this->pixelArray = NULL;
}

//deconstruct the bitmap
bitmap::format::BMP::~BMP() {
    //clear the pixel array
    int pixel;
    int nPixels = this->width * this->height;
    //ensure pixel array exists
    if (this->pixelArray) {
        for(pixel = 0; pixel < nPixels; ++pixel) {
            //ensure pixel is allocated
            if (this->pixelArray[pixel]) {
                delete this->pixelArray[pixel];
            }
        }
        //remove the pixel array
        delete this->pixelArray;
    }
}

/*
 * Private Methods
 */

//convert a bitmap::Color to and BGR array
char* bitmap::format::BMP::asBGR (bitmap::Color color) {
    char* bgr = new char[3]; //allocate the color array

    //fill array with values for Blue, Green and Red
    bgr[bitmap::format::BYTE_RED] = color.getRed();
    bgr[bitmap::format::BYTE_GREEN] = color.getGreen();
    bgr[bitmap::format::BYTE_BLUE] = color.getBlue();

    return bgr;
}

/*
 * Public Methods
 */

//load a Canvas into the BMP
bitmap::format::BMP& bitmap::format::BMP::load(bitmap::Canvas &canvas) {
    //copy items
    this->width = canvas.getWidth();
    this->height = canvas.getHeight();

    //each row of pixels must end on a multiple of 4 bytes
    int bufferedWidth = this->width;
    if (this->width % 4 > 0) { //if not rounded to 4 bits
        bufferedWidth += 4 - (this->width % 4);
    }
    int nPixels = this->width  * this->height;
    this->matrixSize = bufferedWidth * this->height * 3;

    this->fileSize = this->matrixStart + this->matrixSize; //set size of file

    //allocate pixel matrix

    this->pixelArray = new char*[nPixels];

    //copy colors into array as BRG
    int row, col, pixel;
    for (row = 0; row < this->height; ++row) {
        for (col = 0; col < this->width; ++col) {
            pixel = (row*this->width) + col;

            this->pixelArray[pixel] = this->asBGR(canvas.getAt(col, row));
        }
    }

    return *this;
}

/*
 * Operator Overloads
 */

//write to a stream
std::ostream& bitmap::format::operator<<(std::ostream &out, bitmap::format::BMP &bmp) {
    
    //write BMP header data
    //file identifier
    cmtools::stream(out, bmp.identifier);
    //file size
    cmtools::stream(out, bmp.fileSize);
    //reserved bits
    cmtools::stream(out, bmp.res_1);
    cmtools::stream(out, bmp.res_2);
    //start of pixel array
    cmtools::stream(out, bmp.matrixStart);

    //write DIB header data
    //standard header size
    cmtools::stream(out, bmp.headerSize);
    //image dimensions
    cmtools::stream(out, bmp.width);
    cmtools::stream(out, bmp.height);
    //color planes
    cmtools::stream(out, bmp.colorPlanes);
    //bits per pixel
    cmtools::stream(out, bmp.bitsPixel);
    //compression
    cmtools::stream(out, bmp.compression);
    //pixel array size
    cmtools::stream(out, bmp.matrixSize);
    //resolutions
    cmtools::stream(out, bmp.hRes);
    cmtools::stream(out, bmp.vRes);
    //color palette size
    cmtools::stream(out, bmp.paletteSize);
    //important colors in image
    cmtools::stream(out, bmp.importantColors);
    

    // fill out bitmap array
    //each row must be sized out to 4
    int spaceBytes = (4 - (bmp.width %4)) % 4;
    char spacer[] = "\0\0\0\0"; //used to fill spaces at end of rows
    int row, col, pixel;
    for (row = 0; row < bmp.height; ++row) {
        for (col = 0; col < bmp.width; ++col) {
            //get pixel
            pixel = (row * bmp.width) + col; //pixel in array
            //write pixel
            out.write(bmp.pixelArray[pixel], 3);
        }
        //spacer at end of row
        out.write(spacer, spaceBytes);
    }

    return out;
}

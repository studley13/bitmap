/*
 * format/BMP.cpp
 *
 * Author:  Curtis Millar
 * Date:    28 Oct 2012
 *
 * BMP object used to convert a Canvas into a BMP format and
 * vice-versa.
 *
 * Copyright (c) Curtis Millar 2012. All Rights Reserved.
 */

#ifndef CLASS_FORMAT_BMP
#define CLASS_FORMAT_BMP

#include <iostream>
#include "../bitmap.h"

namespace bitmap {
namespace format {

/*
 * Identifiers for bitmaps
 */

const short BMP_BM = 0x4D42;
//compression types
enum Compression {
    BI_RGB,
    BI_RLE8,
    BI_RLE4,
    BI_BITFIELDS,
    BI_JPEG,
    BI_PNG,
    BI_ALHPABITFIELDS
};
//Byte colors
enum byteColors {
    BYTE_BLUE,
    BYTE_GREEN,
    BYTE_RED
};

class BMP {
    private:
        static const short identifier = BMP_BM; //identifer value
        int fileSize; //size of the actual file
        short res_1; //reserved
        short res_2; //reserved
        static const int matrixStart = 54; //starting byte of the pixel matrix
        static const int headerSize = 40; //size of BITMAPINFOHEADER
        int width; //width of the image
        int height; //height of the image
        static const short colorPlanes = 1; //amount of color planes
        short bitsPixel; //bits per pixel
        int compression; //compression type
        int matrixSize; //size of the pixel matrix
        int hRes; //horizontal resolution
        int vRes; //vertical resolution
        int paletteSize; //Colours in palette
        static const int importantColors = 0; //number of important colors

        char** pixelArray; //an array of pixel values

        char* asBGR(Color color); //get color as BRG string

    public:
        BMP(); //constructor
        ~BMP(); //deconstructor
        
        BMP& load(Canvas& canvas); //load a canvas into the BMP

        friend std::ostream& bitmap::format::operator<<(std::ostream &out, BMP &bmp);
};

std::ostream& operator<<(std::ostream &out, BMP &bmp);

}
}

#endif

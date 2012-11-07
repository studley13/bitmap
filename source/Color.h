/*
 * Color.h
 *
 * Author:  Curtis Millar
 * Date:    28 Oct 2012
 *
 * A class that holds an rgba value and can be combined
 * with other colors.
 *
 * Copyright (c) Curtis Millar 2012. All Rights Reserved.
 */

#ifndef CLASS_COLOR
#define CLASS_COLOR

namespace bitmap {
typedef unsigned char chroma; //Intensity of a color from 0x00 to 0xFF
typedef unsigned char opacity; //Opacity of a color

class Color{
    private:
        chroma red;
        chroma green;
        chroma blue;
        opacity alpha;


    public:
        //default constructor
        Color();
        Color(chroma red, chroma green, chroma blue, opacity alpha=0xFF);

        //getters
        chroma getRed() { return this->red; }
        chroma getGreen() { return this->green; }
        chroma getBlue() { return this->blue; }
        opacity getAlpha() { return this->alpha; }

        //setters
        Color& setRed(chroma intensity); //Set the intensity of red
        Color& setGreen(chroma intensity); //Set the intensity of green
        Color& setBlue(chroma intensity); //Set the intensity of blue
        Color& setAlpha(opacity intensity); //Set the opacity of the color
        Color& set(chroma red, chroma green, chroma blue, opacity alpha=0xFF); //set the color

        //operator overloads
        friend bool bitmap::operator==(Color left, Color right);
        friend bool bitmap::operator!=(Color left, Color right);
};

bool operator==(Color left, Color right);
bool operator!=(Color left, Color right);
}
#endif

#include "Color.h"

using namespace bitmap;

/*
 * Constructors
 */

// default
Color::Color() {
    //initiate color as black
    this->set(0, 0, 0);
}

Color::Color(chroma red, chroma green, chroma blue, opacity alpha) {
    //set to given color
    this->set(red, green, blue, alpha);
}

/*
 * Binary Operators
 */

bool bitmap::operator==(Color left, Color right) {
    bool compare = false;
    //all values must be equal
    compare = (left.red == right.red)
           && (left.green == right.green)
           && (left.blue == right.blue)
           && (left.alpha == right.alpha);
    return compare;
}

bool bitmap::operator!=(Color left, Color right) {
    bool compare = false;
    //binary opposite of equal
    compare = (left == right);
    compare = !compare;
    return compare;
}

/*
 * Public Methods
 */

// set the intensity of the red chroma
Color& Color::setRed(chroma intensity) {
    this->red = intensity;
    return *this;
}

// set the intensity of the Green chroma
Color& Color::setGreen(chroma intensity) {
    this->green = intensity;
    return *this;
}

// set the intensity of the blue chroma
Color& Color::setBlue(chroma intensity) {
    this->blue = intensity;
    return *this;
}

// set the opacity of the color
Color& Color::setAlpha(opacity intensity) {
    this->alpha = intensity;
    return *this;
}

// set the color
Color& Color::set(chroma red, chroma green, chroma blue, opacity alpha) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
    return *this;
}


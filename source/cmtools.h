/*
 * cmtools.h
 *
 * Author:  Curtis Millar
 * Date:    28 Oct 2012
 *
 * A set of standard tools and functions
 *
 * Copyright (c) Curtis Millar 2012. All Rights Reserved.
 */

#ifndef CMTOOLS
#define CMTOOLS

#include <iostream>

#define BYTEMASK ((1<<8)-1)

namespace cmtools {

//convert a value into a string.
std::ostream& stream(std::ostream& out, int value);
std::ostream& stream(std::ostream& out, short value);
std::ostream& stream(std::ostream& out, char value);
std::ostream& stream(std::ostream& out, long value);

}

#endif

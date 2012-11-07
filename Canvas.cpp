#include <cstdlib>
#include "Canvas.h"

using namespace bitmap;

/*
 * Constructors
 */

//default
Canvas::Canvas() {
    //initiate a 0 sized bitmap
    this->width = 0;
    this->height = 0;
    this->matrix = NULL;
}

Canvas::Canvas(int width, int height) {
    //set the width and height
    this->width = width;
    this->height = height;
    this->matrix = NULL;
    if ((width * height) > 0) {
        //if the matrix has size
        this->populateMatrix();
    }
}

//Deconstructor
Canvas::~Canvas() {
    //clean up and clear the matrix
    this->depopulateMatrix();
}

/*
 * Private Methods
 */

//Allocate the matrix and its cells
void Canvas::populateMatrix() {
    //ensure matrix has size
    if (this->width * this->height > 0) {
        this->matrix = new Color*[width]; //allocate a matrix of colors
        // allocate columns seperatly
        int col; //a column in the matrix
        for (col = 0; col < width; ++col) {
            //create an array for the column
            this->matrix[col] = new Color[height];
        }
    }
}

//Deallocate the matrix and its cells
void Canvas::depopulateMatrix(){
    //ensure matrix exists
    if (matrix) {
        //deallocate each column first
        int col; //column on the matrix
        for (col = 0; col < width; ++col) {
            //ensure column is allocated
            if (this->matrix[col]) {
                delete this->matrix[col];
            }
        }
        delete this->matrix;
    }
}

//Get a cell from the matrix
Color* Canvas::getCell(int x, int y){
    Color* cell = NULL;
    //if a valid point in the image
    if ((x < this->width) && (x >= 0)
     && (y < this->height) && (y >= 0)) {
        //set cell to point to the cell at (x, y)
        cell = &(this->matrix[x][y]);
    }
    return cell;
}

/*
 * Public Methods
 */

//change the dimensions of the matrix
Canvas& Canvas::resize(int width, int height, flag anchor) {
    //clear the image
    this->depopulateMatrix();
    //change the proportions
    this->width = width;
    this->height = height;
    //fill the matrix
    this->populateMatrix();

    return *this;
}

//get the colour at a point
Color Canvas::getAt(int x, int y) {
    //this color will be returned if a cell cannot be found
    static Color voidColor(0, 0, 0, 0);
    //get the cell from the matrix
    Color* cell = NULL;
    cell = this->getCell(x, y);
    //check for unavailable cell
    if (cell == NULL) {
       cell = &voidColor; //use void color for return 
    }
    //make a constant referece to the cell
    const Color& copy = *cell;
    return copy; 
}

//change the color at a point in the matrix
Canvas& Canvas::setAt(int x, int y, Color color) {
    Color* cell = NULL;
    //get cell from matrix
    cell = this->getCell(x, y);
    if (cell) { //if cell was found
        *cell = color; //set sell to color
    }
    return *this;
}

#ifndef COORDINATES_H
#define COORDINATES_H

// struct for storing location latitude (x) and longitude (y) coordinates
struct Coordinates {
    double x;
    double y;

    // constructors
    Coordinates(double x, double y) {
        this->x = x;
        this->y = y;
    }
    Coordinates():Coordinates(0, 0) {}
};

#endif
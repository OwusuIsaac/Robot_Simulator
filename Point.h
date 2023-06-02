#include <iostream>
#include <cmath>

#define pi 3.142

using namespace std;

class Point {
    // coord_x and coord_y can only be accessed in class
private:
    double coord_x, coord_y;
public:
    Point() : coord_x(0), coord_y(0)
    { }
    Point(double x, double y) {
        coord_x = x;
        coord_y = y;
    }
    // member function sets a value to coord_x
    void set_coord_x(double a) {
        coord_x = a;
    }
    // member function sets a value to coord_y
    void set_coord_y(double b) {
        coord_y = b;
    }
    // member function returns value of coord_x
    double get_coord_x() {
        return coord_x;
    }
    // member function returns value of coord_y
    double get_coord_y() {
        return coord_y;
    }
};
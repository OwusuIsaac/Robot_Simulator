#include <iostream>
#include <cmath>
#include "Point.h"

class Segment {
private:
    Point startPoint, endPoint;
    double angle, length;

public:
    // member function finds the coord_x of endpoint of a segment
    void endPoint_x() {
        endPoint.set_coord_x(length * cos(angle) + startPoint.get_coord_x());
    }
    // member function finds the coord_y of endpoint of a segment
    void endPoint_y() {
        endPoint.set_coord_y(length * sin(angle) + startPoint.get_coord_y());
    }
    Segment() : angle(0), length(0)
    { }
    Segment(double x, double y) {
        startPoint.set_coord_x(x);
        startPoint.set_coord_y(y);
        cout << "Enter the length of the segment here:" << endl;
        cin >> length;
        while (length <= 0) {
            cout << "Please enter a value greater than 0 for length:" << endl;
            cin >> length;
        }
        cout << "Enter the angle between the segment and the horizontal axis:" << endl;
        cin >> angle;
        while (angle < 0 || angle>2 * pi) {
            cout << "Enter a value between 0 and 2pi:" << endl;
            cin >> angle;
        }
        endPoint_x();
        endPoint_y();
    }
    // member function returns the coord_x of endpoint of segment
    double get_endPoint_x() {
        return endPoint.get_coord_x();
    }
    // member function returns the coord_y of endPoint of segment
    double get_endPoint_y() {
        return endPoint.get_coord_y();
    }
    // member function returns the coord_x of startPoint of segment
    double get_startPoint_x() {
        return startPoint.get_coord_x();
    }
    // member function returns the coord_y of startPoint of segment
    double get_startPoint_y() {
        return startPoint.get_coord_y();
    }
    // member function returns the angle of segment
    double get_Angle() {
        return angle;
    }
    // member function returns the length of segment
    double get_length() {
        return length;
    }
    // member function sets value to angle and recalculate the x coordinate and y coordinate of endpoint of segment
    void set_angle(double z) {
        angle = z;
        endPoint_x();
        endPoint_y();
    }
    // member function sets value to the x coordinate and y coordinate of start point of a segment  and recalculate the x coordinate and y coordinate of endpoint of a segment
    void set_start(double m, double n) {
        startPoint.set_coord_x(m);
        startPoint.set_coord_y(n);
        endPoint_x();
        endPoint_y();
    }
    // member function sets value to length and recalculate the x coordinate and y coordinate of endpoint of a segment
    void set_length(double s) {
        length = s;
        while (length <= 0) {
            cout << "Please enter a value greater than 0 for length:" << endl;
            cin >> length;
        }
        endPoint_x();
        endPoint_y();
    }
    // member function prints out the information of a segment
    void printSegmentInfo() {
        cout << "startPoint = (" << startPoint.get_coord_x() << "," << startPoint.get_coord_y() << ")" << endl;
        cout << "angle of segment =  " << get_Angle() << endl;
        cout << "length of segment = " << get_length() << endl;
        cout << "endPoint of segment = (" << endPoint.get_coord_x() << "," << endPoint.get_coord_y() << ")" << endl;
    }
};
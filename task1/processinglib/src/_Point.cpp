//
// Created by abdulla167 on ١٦‏/٥‏/٢٠٢١.
//

#include "_Point.h"

_Point::_Point() {}

_Point::_Point(const _Point &point): x{point.x}, y{point.y} {}

_Point::_Point(int x, int y): x{x}, y{y} {}

_Point _Point::operator+ ( _Point & p2){
    _Point p3{x + p2.x, y + p2.y};
    return p3;
}
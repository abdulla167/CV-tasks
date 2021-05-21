//
// Created by abdulla167 on ١٦‏/٥‏/٢٠٢١.
//

#ifndef CV__POINT_H
#define CV__POINT_H


class _Point {
public:
    int x, y;

    _Point();
    _Point(const _Point & point);
    _Point(int x, int y);
    _Point operator+ ( _Point & p2);
};



#endif //CV__POINT_H

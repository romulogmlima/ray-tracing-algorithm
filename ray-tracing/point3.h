#include "vector3.h"

#ifndef POINT3D_H
#define POINT3D_H

class Point3
{
    public:
        Point3();
        Point3(double _c);
        Point3(double _x, double _y, double _z);

        double x, y, z;

        Vector3 operator- (const Point3 & p) const;
        double distance(const Point3 & p) const;     //distance between the two points
};

#endif // POINT3D_H

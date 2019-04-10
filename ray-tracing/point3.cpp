#include <math.h>
#include "point3.h"

Point3::Point3() : x(0.0), y(0.0), z(0.0)
{

}

Point3::Point3(double _c) : x(_c), y(_c), z(_c)
{

}

Point3::Point3(double _x, double _y, double _z): x(_x), y(_y), z(_z)
{

}

Vector3 Point3::operator -(const Point3 & p) const
{
    return (Vector3(x - p.x, y - p.y, z - p.z));
}

double Point3::distance(const Point3 & p) const
{
    return (sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y) + (z - p.z)*(z - p.z)));
}

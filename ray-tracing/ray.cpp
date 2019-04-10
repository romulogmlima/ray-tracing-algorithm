#include <iostream>
#include "ray.h"

using namespace std;

Ray::Ray(const Point3& origin, const Vector3& dir)
{
    this->origin = origin;
    this->dir = dir;
}

Ray::Ray(const Point3& rOrigin, const Point3& rEndPoint)
{
    this->origin = rOrigin;
    this->dir = (rEndPoint - origin).normalize();
}

const Point3& Ray::getOrigin() const
{
    return origin;
}

const Vector3& Ray::getDirection() const
{
    return dir;
}

Ray& Ray::operator= (const Ray& rhs)
{
    if (this == &rhs)
    {
        return (*this);
    }

    origin = rhs.origin;
    dir = rhs.dir;

    return (*this);
}

#include "vector3.h"
#include "point3.h"

#ifndef RAY_H
#define RAY_H

class Ray
{
    public:
        Ray(const Point3& origin, const Vector3& dir);
        Ray(const Point3& rOrigin, const Point3& rEndPoint);

        void setOrigin(Point3 vPoint);
        const Point3& getOrigin() const;

        void setDirection(Vector3 vDirection);
        const Vector3& getDirection() const;

        Ray& operator= (const Ray& rhs);

    private:
        Point3 origin;
        Vector3 dir;
};

#endif // RAY_H

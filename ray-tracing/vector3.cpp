#include <math.h>
#include "vector3.h"

Vector3::Vector3() : x(0.0), y(0.0), z(0.0)
{

}

Vector3::Vector3(double _c) : x(_c), y(_c), z(_c)
{

}

Vector3::Vector3(double _x, double _y, double _z): x(_x), y(_y), z(_z)
{

}

Vector3 Vector3::normalize()
{
    return (*this) /= this->length();
}

double Vector3::length() const
{
    return sqrtf( x * x + y * y + z * z );
}

Vector3 Vector3::cross(Vector3 const & v) const
{
    return Vector3(y * v.z - v.y * z, v.x * z - x * v.z, x * v.y - v.x * y);
}

double Vector3::dot(const Vector3 &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::operator + (Vector3 const & v) const
{
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 & Vector3::operator += (Vector3 const & v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}

Vector3 Vector3::operator - (Vector3 const & v) const
{
    return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 & Vector3::operator -= (Vector3 const & v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}

Vector3 Vector3::operator * (Vector3 const & v) const
{
   return Vector3(x * v.x, y * v.y, z * v.z);
}

Vector3 & Vector3::operator *= (Vector3 const & v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return *this;
}

Vector3 Vector3::operator / (Vector3 const & v) const
{
   return Vector3(x / v.x, y / v.y, z / v.z);
}

Vector3 & Vector3::operator /= (Vector3 const & v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;

    return *this;
}

Vector3 Vector3::operator * (double const s) const
{
    return Vector3(x * s, y * s, z * s);
}

Vector3 & Vector3::operator *= (double const s)
{
    x *= s;
    y *= s;
    z *= s;

    return *this;
}

Vector3 Vector3::operator / (double const s) const
{
    return Vector3(x / s, y / s, z / s);
}

Vector3 & Vector3::operator /= (double const s)
{
    x /= s;
    y /= s;
    z /= s;

    return *this;
}

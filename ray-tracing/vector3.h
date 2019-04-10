#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3
{
    public:
        Vector3();
        Vector3(double _c);
        Vector3(double _x, double _y, double _z);

        double x, y, z;

        Vector3 normalize();
        double length() const;
        Vector3 cross(Vector3 const & v) const;
        double dot(Vector3 const & v) const;

        Vector3 operator + (Vector3 const & v) const;
        Vector3 & operator += (Vector3 const & v);
        Vector3 operator - (Vector3 const & v) const;
        Vector3 & operator -= (Vector3 const & v);
        Vector3 operator * (Vector3 const & v) const;
        Vector3 & operator *= (Vector3 const & v);
        Vector3 operator / (Vector3 const & v) const;
        Vector3 & operator /= (Vector3 const & v);

        Vector3 operator * (double const s) const;
        Vector3 & operator *= (double const s);
        Vector3 operator / (double const s) const;
        Vector3 & operator /= (double const s);
};

#endif // VECTOR3D_H
